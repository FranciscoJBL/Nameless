<?hh //strict

namespace Nameless\Core\Entity\EntityOne\EntityOneCalculator\Network;

use Nameless\Core\Entity\EntityOne\EntityOneCalculator\Network\Weights as Weight;
/*
 * A neuronal network
 *
 */
class Network
{
    /*
     * Neurons of the network
     */
    private Map<Neuron> $inputLayer = new Map();
    private Map<Neuron> $hiddenLayer = new Map();
    private Map<Neuron> $hiddenLayer2 = new Map();
    private Map<Neuron> $response = new Map();

    private float $totalNeurons;
    private array<Weight> $w1 = [];
    private array<Weight> $w2 = [];
    private array<Weight> $w3 = [];

    private float $learning_rate = 0.000011;


    public function __construct(int $numberInputs) : void
    {
        $identifier = 0;
        for ($i = 0; $i < $numberInputs; $i++) {
            $this->inputLayer[$identifier] = new Neuron(
                0.0,
                $identifier,
                true
            );
            $identifier++;
        }
        for ($i = 0; $i < 6; $i++) {
            $this->hiddenLayer[$identifier] = new Neuron(0.0, $identifier);
            $identifier++;
        }

        for ($i = 0; $i < 3; $i++) {
            $this->hiddenLayer2[$identifier] = new Neuron(0.0, $identifier);
            $identifier++;
        }

        $this->response[$identifier] = new Neuron (0.0, $identifier, true);

        $this->totalNeurons = $identifier;

    }
    public function setInputs(array<float> $inputs) : void
    {
        $identifier = 0;
        foreach ($inputs as $i) {
            $this->inputLayer[$identifier]->setValue($i);
            $identifier++;
        }
    }
    public function generateWeights() : void
    {

        $input = count($this->inputLayer);
        $hidden = count($this->hiddenLayer) + $input;
        $hidden2 = count($this->hiddenLayer2) + $hidden;
        $response = count($this->response) + $hidden2;

        $pos = 0;
        for ($i = 0; $i < $input; $i++) {
            for ($x = $input; $x < $hidden; $x++) {
                $this->w1[$pos] = new Weight(
                    $this->inputLayer[$i]->getIdentity(),
                    $this->hiddenLayer[$x]->getIdentity(),
                    floatval(rand(1, 10)) / 10.0
                );
                $pos++;
            }
        }

        $pos = 0;
        for ($i = $input; $i < $hidden; $i++) {
            for ($x = $hidden; $x < $hidden2; $x++) {
                $this->w2[$pos] = new Weight(
                    $this->hiddenLayer[$i]->getIdentity(),
                    $this->hiddenLayer2[$x]->getIdentity(),
                    floatval(rand(1, 10)) / 10.0
                );
                $pos++;
            }
        }

        $pos = 0;
        for ($i = $hidden; $i < $hidden2; $i++) {
            for ($x = $hidden2; $x < $response; $x++) {
                $this->w3[$pos] = new Weight(
                    $this->hiddenLayer2[$i]->getIdentity(),
                    $this->response[$x]->getIdentity(),
                    floatval(rand(1, 10)) / 10.0
                );
                $pos++;
            }
        }
    }

    public function forwardPropagation() : void
    {
        for ($i = 0; $i < count($this->w1); $i++) {

            $initial = $this->w1[$i]->getInitial();
            $final = $this->w1[$i]->getFinal();
            $initialvalue = $this->inputLayer[$initial]->getValue();
            $weigthValue = $this->w1[$i]->getValue();

            $this->hiddenLayer[$final]->setValue(
                $initialvalue * $weigthValue
            );
        }

        for ($i = 0; $i < count($this->w2); $i++) {

            $initial = $this->w2[$i]->getInitial();
            $final = $this->w2[$i]->getFinal();

            $initialvalue = $this->hiddenLayer[$initial]->getValue();
            $weigthValue = $this->w2[$i]->getValue();

            $this->hiddenLayer2[$final]->setValue(
                $initialvalue * $weigthValue
            );
        }

        for ($i = 0; $i < count($this->w3); $i++) {

            $initial = $this->w3[$i]->getInitial();
            $final = $this->w3[$i]->getFinal();

            $initialvalue = $this->hiddenLayer2[$initial]->getValue();
            $weigthValue = $this->w3[$i]->getValue();

            $this->response[$final]->setValue(
                $initialvalue * $weigthValue
            );
        }
    }

    public function backPropagation(float $espectedResult) :void
    {
        $error = $espectedResult / $this->response[$this->totalNeurons]->getValue();
        $error = abs(round($error, 4));

        print_r($error);
        print_r("\n");
        print_r($espectedResult);
        print_r("\n");
        print_r($this->response[$this->totalNeurons]->getValue());
        print_r("\n");
        print_r("\n");
        print_r("\n");
        for ($i = 0; $i < count($this->w3); $i++) {
            $this->w3[$i]->setValue(
                ($this->w3[$i]->getValue() * $error) * $this->learning_rate
            );

        }
        for ($i = 0; $i < count($this->w2); $i++) {
            $this->w2[$i]->setValue(
                ($this->w2[$i]->getValue() * $error) * $this->learning_rate
            );

        }
        for ($i = 0; $i < count($this->w1); $i++) {
            $this->w1[$i]->setValue(
                ($this->w1[$i]->getValue() * $error) * $this->learning_rate
            );
        }
    }

    private function Debug()
    {
        print_r($this->inputLayer);
        print_r("\n");
        print_r($this->w1);
        print_r("\n");
        print_r($this->hiddenLayer);
        print_r("\n");
        print_r($this->w2);
        print_r("\n");
        print_r($this->hiddenLayer2);
        print_r("\n");
        print_r($this->w3);
        print_r("\n");
        print_r($this->response);
        print_r("\n");exit();
    }
}