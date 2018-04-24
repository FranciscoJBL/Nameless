<?hh

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

    private float $variation = 0.0;
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

        // 'its supposed that i have to think about that...';
    }

    private function inputData(array<float> $inputs) : array<float>
    {
        $dataset = new DataSet();
        $testDataSet = $dataset->getData();

        return $this->train($testDataSet);
    }

    public function train($dataset) : array<float>
    {
        $this->adjustWeights();
        $index = 0;
        $i = 0;
        $output = [];
        while ($i < 1) {
            foreach ($dataset as $data) {
                //propagation
                $output[] = $this->propagation($data);
                $this->adjustWeights();
                $this->hiddenLayer = [0.1,0.1,0.1];
                $this->result = 0.0;
                $i++;
            }
        }
        return $output;
    }

    private function adjustWeights() :void
    {

        if ($this->variation === 0.0 && $this->result  === 0.0) {
            for ($x = 0;$x < 12;$x++) { //w1
                    $this->w1[$x] = floatval(rand(1, 10)) / 10.0;
            }

            for ($x = 0;$x < 3;$x++) {//w2, bias
                    $this->bias[$x] = floatval(rand(0, 1));
                    $this->w2[$x] = floatval(rand(1, 10)) / 10.0;
            }

        } elseif  ($this->variation !== 0.0) {
            for ($x = 0;$x < 12;$x++) {
                $this->w1[$x] = $this->w1[$x] + ($this->w1[$x] * ($this->variation / 100));
                $this->w1[$x] = round($this->w1[$x], 5);
            }

            for ($x = 0;$x < 3;$x++) {//w2
                $this->w2[$x] = $this->w2[$x] + ($this->w2[$x] * ($this->variation  / 100));
                $this->w2[$x] = round($this->w2[$x], 5);
            }
        }
    }

    private function propagation(array<float> $data) : float
    {
            $result = 0.0;
            $translation = [
                'Iris-setosa' => 1.0,
                'Iris-versicolor'=> 2.0,
                'Iris-virginica' => 3.0,
            ];
            $espectedResult = $translation[$data[4]];

            //input
            $this->inputLayer[0] = $data[0];
            $this->inputLayer[1] = $data[1];
            $this->inputLayer[2] = $data[2];
            $this->inputLayer[3] = $data[3];
            //hidden
            for ($i= 0;$i < 3;$i++) {
               for ($x= 0;$x < 4;$x++) {
                    for ($z= 0;$z < 12;$z++) {
                        $this->hiddenLayer[$i] += ($this->inputLayer[$x] * $this->w1[$z]) * $this->bias[$i];
                    }
                }
            }

            //output
            for ($i= 0;$i < 3;$i++) {
                $this->result += $this->hiddenLayer[$i]*$this->w2[$i];
                $this->variation = $espectedResult - $this->result;
            }
            $this->result = round($this->result);
            $this->variation = round($this->variation, 1);
            $translation = [
                '1' => 'Iris-setosa',
                '2' => 'Iris-versicolor',
                '3' => 'Iris-virginica'
            ];

            if (array_key_exists(strval($this->result), $translation)) {
                print_r($translation[$this->result]);
                print_r("\n");
            }
            return $this->result;
    }
}