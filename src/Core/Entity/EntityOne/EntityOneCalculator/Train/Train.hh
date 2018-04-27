<?hh //strict

namespace Nameless\Core\Entity\EntityOne\EntityOneCalculator\Train;

use Nameless\Core\Entity\EntityOne\EntityOneCalculator\DataSet;
use Nameless\Core\Entity\EntityOne\EntityOneCalculator\Interpreter;

class Train
{
    private array<float> $hiddenLayer = [];
    private array<float> $inputLayer = [];
    private array<float> $bias = [];
    private array<float> $w1 = [];
    private array<float> $w2 = [];
    private float $espectedResult = 0.0;
    private float $variation = 0.0;
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
        print_r(count($data));
        while ($i < (count($data) - count($data)/10)) { // we espect 90% of assert
            $i = 0;
            foreach ($data as $row) {
                $interpreter->setData($row);
                $set = $interpreter->getNativeData();
                $this->espectedResult = $set[4];
                unset($set[4]);
                $this->setInputLayer($set);
                $this->propagation();

                $response [] = $interpreter->getReadableData(
                    $this->result
                );
                $range = 450.0;
                if($this->variation < $range && $this->variation > -$range) {
                    print_r($this->variation);
                    print_r("\n");
                    $i++;
                } else {
                    $this->adjustWeights();
                }
                $this->result = 0.0;
            }
            print_r("\n");
        }
        print_r("w1 :");
        print_r("\n");
        print_r($this->w1);
        print_r("\n");
        print_r("w2 :");
        print_r("\n");
        print_r($this->w2);
        print_r("\n");
        print_r("bias :");
        print_r("\n");
        print_r($this->bias);
        print_r("\n");
        exit();
        $this->setConcept();
        return $response;
    }
    private function setConcept() :void
    {

    }
    private function generateWeights() : void
    {
        for ($x = 0;$x < 12;$x++) { //w1
            $this->w1[$x] = floatval(rand(1, 10)) / 10.0;
        }
        $x = 0;
        for ($x = 0;$x < 3;$x++) {//w2, bias
            $this->bias[$x] = floatval(rand(0, 1));
            if ($this->bias == 0.0) {
                $x++;
            }
            $this->w2[$x] = floatval(rand(1, 10)) / 10.0;
        }
        if ($x === 3) {
            $this->bias[0] = 1.0;
            $this->bias[2] = 1.0;
        }
    }
    private function setInputLayer(array<float> $inputLayer) :void
    {
        $this->inputLayer = $inputLayer;
    }
    private function propagation() : void
    {
        for ($i= 0;$i < 3;$i++) {
           for ($x= 0;$x < 4;$x++) {
                for ($z= 0;$z < 12;$z++) {
                    $InputW1 = $this->inputLayer[$x] * $this->w1[$z];
                    $this->hiddenLayer[$i] += $InputW1 * $this->bias[$i];
                }
            }
        }

        //output
        for ($i= 0;$i < 3;$i++) {
            $this->result += round(($this->hiddenLayer[$i]*$this->w2[$i]), 1);
        }
        $this->variation = $this->espectedResult - $this->result;
    }
    private function adjustWeights() :void
    {
        if  ($this->variation !== 0.0 && $this->result  !== 0.0) {
            for ($x = 0;$x < 12;$x++) {
                $this->w1[$x] += round((($this->result * $this->w1[$x]) / $this->variation), 3);
            }

            for ($x = 0;$x < 3;$x++) {//w2
                $this->w2[$x] += round((($this->result * $this->w2[$x]) / $this->variation), 3);
            }
        }
    }
}
