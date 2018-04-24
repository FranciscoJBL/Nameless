<?hh //strict

namespace Nameless\Core\Entity\EntityOne\EntityOneCalculator;

use Nameless\Core\Entity\EntityOne\EntityOneCalculator\Interpreter;
use Nameless\Core\Entity\EntityOne\EntityOneCalculator\Concepts;

class Calculator
{
    private ?array<string> $data;
    private array<float> $hiddenLayer = [];
    private array<float> $inputLayer = [];
    private array<float> $bias = [];
    private array<float> $w1 = [];
    private array<float> $w2 = [];
    private ?float $variation = null;
    private float $result = 0.0;
    public function setData(?array<string> $data) : void
    {
        $this->data = $data;
    }
    public function getConclusion() : array<float>
    {
        $interpreter = new Interpreter($this->data);
        $concept = new Concepts();

        return $interpreter->getReadableData(
            $concept->getConcept(
                $this->inputData($interpreter->getNativeData())
            )
        );

        //return 'its supposed that i have to think about that...';
    }
    private function inputData(array<float> $inputs) : array<float>
    {
        $testDataSet = [
            [2.0, 4.0, 6.0],
            [1.0, 4.0, 5.0],
            [3.0, 2.0, 5.0],
            [1.0, 2.0, 3.0],
            [1.1, 2.2, 3.3],
            [1.4, 2.2, 3.6],
            [8.4, 1.2, 9.6],
            [2.0, 4.2, 6.2],
            [1.0, 4.2, 5.2],
            [3.0, 2.2, 5.2],
            [1.0, 2.2, 3.2],
            [1.1, 2.6, 3.7],
            [1.4, 2.6, 4.0],
            [8.4, 1.5, 9.9]
        ];

        return $this->train($testDataSet);
    }

    public function train(array<array<float>> $dataset) : array<float>
    {
        $this->adjustWeights();
        $index = 0;
        $i = 0;
        $output = [];
        while ($i < 200){
            foreach ($dataset as $data) {
                //propagation
                $oldvariation = $this->variation === null ? 0.0 : $this->variation;
                $output[] = $this->propagation($data);
                $this->adjustWeights();
                $this->hiddenLayer = [0.0,0.0,0.0];
                $this->result = 0.0;
            }
            $i++;
        }
        return $output;
    }

    private function adjustWeights() :void
    {
        if ($this->variation === null) {

            for ($x = 0;$x < 6;$x++) { //w1
                    $this->w1[$x] = floatval(rand(1, 10)) / 10.0;
            }

            for ($x = 0;$x < 3;$x++) {//w2, bias
                    $this->bias[$x] = floatval(rand(0, 1));
                    $this->w2[$x] = floatval(rand(1, 10)) / 10.0;
            }

        } else if ($this->variation > 0.0) {

            for ($x = 0;$x < 6;$x++) {
                $this->w1[$x] += ($this->w1[$x] * $this->variation) * 0.1;
            }
            for ($x = 0;$x < 3;$x++) {//bias
                $this->bias[$x] += floatval(rand(0, 1));
            }
            for ($x = 0;$x < 3;$x++) {//w2
                $this->w2[$x] += ($this->w2[$x] * $this->variation)  * 0.1;
            }
        }
    }

    private function propagation(array<float> $data) : float
    {
            $result = 0.0;
            $espectedResult = $data[2];

            //input
            $this->inputLayer[0] = $data[0];
            $this->inputLayer[1] = $data[1];

            //hidden
            for ($i= 0;$i < 3;$i++) {
               for ($x= 0;$x < 2;$x++) {
                    for ($z= 0;$z < 6;$z++) {
                        $this->hiddenLayer[$i] += ($this->inputLayer[$x] * $this->w1[$z])*$this->bias[$i];
                    }
                }
            }

            //output
            for ($i= 0;$i < 3;$i++) {
                $this->result += $this->hiddenLayer[$i]*$this->w2[$i];
                $this->variation = ($espectedResult - $this->result);
            }
            print_r($this->result);
            print_r("\n");
            print_r($this->variation);
            print_r("\n");
            print_r($espectedResult);
            print_r("\n");
            print_r("next one");
            print_r("\n");
            return $this->result;
    }
}