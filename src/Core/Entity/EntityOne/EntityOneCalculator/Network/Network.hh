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
    private Map<Neuron> $response = new Map();;

    private array<?Weight> $w1 = [];
    private array<?Weight> $w2 = [];
    private array<?Weight> $w3 = [];

    public function __construct(array<float> $inputs) : void
    {

        $identifier = 0;
        for ($i = 0; $i < count($inputs); $i++) {
            $this->inputLayer[$identifier] = $new Neuron($inputs[$i], $identifier, true);
            $identifier++;
        }
        for ($i = 0; $i < 6; $i++) {
            $this->hiddenLayer[$identifier] = $new Neuron(0.0, $identifier);
            $identifier++;
        }

        for ($i = 0; $i < 3; $i++) {
            $this->hiddenLayer2[$identifier] = $new Neuron(0.0, $identifier);
            $identifier++;
        }

        $this->response[$identifier] = new Neuron (0.0, $identifier, true);

    }
    public function generateWeights() : void
    {
        $pos = 0;
        for ($x = 0; $x < count($this->inputLayer); $x++) {
            for ($i = 0; $i < count($this->hiddenLayer); $i++) {
                $this->w1[$pos] = new Weight(
                    $this->inputLayer[$x]->getIdentity(),
                    $this->hiddenLayer[$i]->getIdentity(),
                    floatval(rand(1, 10)) / 10.0
                );
                $pos++;
            }
        }

        $pos = 0;
        for ($x = 0; $x < count($this->hiddenLayer); $x++) {
            for($i = 0; $i < count($this->hiddenLayer2); $i++){
                $this->w2[$pos] = new Weight(
                    $this->hiddenLayer[$x]->getIdentity(),
                    $this->hiddenLayer2[$i]->getIdentity(),
                    floatval(rand(1, 10)) / 10.0
                );
                $pos++;
            }
        }

        for ($x = 0; $x < count($this->hiddenLayer2); $x++) {
                $this->w3[$x] = new Weight(
                    $this->hiddenLayer2[$x]->getIdentity(),
                    $this->response->getIdentity(),
                    floatval(rand(1, 10)) / 10.0
                );
        }
        /*
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
        */
    }

    private function ForwardPropagation() : float
    {
        $output = 0.0;

        for ($i = 0; $i < count($this->w1); $i++) {

            $initial = $this->w1[$i]->getInitial();
            $final = $this->w1[$i]->getFinal();

            $initialvalue = $this->inputLayer[$initial]->getValue();
            $weigthValue = $this->w1[$i]->getValue();

            $this->hiddenLayer[$final]->setValue(
                $Initialvalue * $weigthValue
            );

        }

        for ($i = 0; $i < count($this->w2); $i++) {

            $initial = $this->w2[$i]->getInitial();
            $final = $this->w2[$i]->getFinal();

            $initialvalue = $this->hiddenLayer[$initial]->getValue();
            $weigthValue = $this->w2[$i]->getValue();

            $this->hiddenLayer2[$final]->setValue(
                $Initialvalue * $weigthValue
            );

        }

        for ($i = 0; $i < count($this->w3); $i++) {

            $initial = $this->w3[$i]->getInitial();
            $final = $this->w3[$i]->getFinal();

            $initialvalue = $this->hiddenLayer2[$initial]->getValue();
            $weigthValue = $this->w3[$i]->getValue();

            $this->response[$final]->setValue(
                $Initialvalue * $weigthValue
            );

        }

    }

    private function backPropagation(float $espectedResult, float $result) :void
    {
        $derivative = $result * (1.0 - $result);
        $error = ($espectedResult - $result) * $derivative;

        $rate = round($espectedResult/$result, 4);
        $rate = ($rate / 2) * 1.2;

        for ($i = 0 ; $i < count($this->hiddenLayer2); $i++) {
            $this->w3[$i] = $this->hiddenLayer2[$i]->getValue()*$rate;
        }
    }
}