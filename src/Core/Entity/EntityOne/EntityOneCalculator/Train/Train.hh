<?hh //strict

namespace Nameless\Core\Entity\EntityOne\EntityOneCalculator\Train;

use Nameless\Core\Entity\EntityOne\EntityOneCalculator\DataSet;
use Nameless\Core\Entity\EntityOne\EntityOneCalculator\Interpreter;
use Nameless\Core\Entity\EntityOne\EntityOneCalculator\Concepts;
use Nameless\Core\Entity\EntityOne\EntityOneCalculator\Network\Network;


class Train
{
    private ?Network $network;

    private float $espectedResult = 0.0;
    private float $result = 0.0;

    public function __construct() : void
    {

    }

    public function makeTrain() : array<string>
    {
        $dataSet = new DataSet();
        $data = $dataSet->getData();
        $interpreter = new Interpreter();
        $response = [];
        $this->generateWeights();
        $i = 0;
        while ($i < count($data)) { // we espect 90% of assert
            $i = 0;
            foreach ($data as $row) {
                if ($this->variation > 1000000) {
                    //i dont like recreating the values, but it seems necessary
                    //to avoid some weird stuff in some cases
                    //where the weights become crazy
                    $this->generateWeights();
                }
                $interpreter->setData($row);
                $set = $interpreter->getNativeData();
                $this->espectedResult = $set[count($set)-1];
                unset($set[4]);
                $this->setInputLayer($set);
                $this->propagation();
                $maxRange = 50.0;
                $minRange = -50.0;
                if(
                    $this->variation < $maxRange
                    && $this->variation > $minRange
                ) {
                    $i++;
                    print_r($i);
                    print_r("\n");
                } else {
                    $this->adjustWeights();
                }
                print_r($this->variation);
                print_r("\n");
            }
        }
        return ["terminé :D \n"];
    }

    private function generateWeights() : void
    {
        for ($x = 0;$x < 32;$x++) { //w1
            $this->w1[$x] = floatval(rand(1, 10)) / 10.0;
        }
        $x = 0;
        for ($x = 0;$x < 8;$x++) {//w2, bias
            $this->bias[$x] = floatval(rand(0, 1));
            $this->w2[$x] = floatval(rand(1, 10)) / 10.0;
        }
    }

    private function setInputLayer(array<float> $inputLayer) :void
    {
        $this->inputLayer = $inputLayer;
    }

    private function propagation() : void
    {
        for ($i= 0;$i < 8;$i++) {
           for ($x= 0;$x < 4;$x++) {
                for ($z= 0;$z < 32;$z++) {
                    $InputW1 = $this->inputLayer[$x] * $this->w1[$z];
                    $this->hiddenLayer[$i] += $InputW1 * $this->bias[$i];
                }
            }
        }
        //output
        $this->result= 0.0;
        for ($i= 0;$i < 8;$i++) {
            $this->result += round(($this->hiddenLayer[$i]*$this->w2[$i]), 1);
        }
        $this->variation = round(($this->espectedResult - $this->result), 3);
    }

    private function adjustWeights() :void
    {
        if (
            $this->variation >= 1.0
            || $this->variation <= -1.0
        ) {
            for ($x = 0;$x < 32;$x++) {
                $this->w1[$x] += round(
                    $this->variation / $this->espectedResult,
                    6
                ) * 1.1;
            }

            for ($x = 0;$x < 8;$x++) {//w2
                $this->w2[$x] += round(
                    $this->variation / $this->espectedResult,
                    6
                ) * 1.1;
                $this->bias[$x] = floatval(rand(0, 1));
            }

            print_r("\n");
            print_r("\n");
        }
    }
}
