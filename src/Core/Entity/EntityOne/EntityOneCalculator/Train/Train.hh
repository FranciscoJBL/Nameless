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
    public function sendResponse(string $response) :void
    {
        print_r($response);
        print_r("\n");
    }
    public function makeTrain() : array<string>
    {
        $this->sendResponse("iniciando entrenamiento");
        $this->sendResponse("preparando dataset");
        $dataSet = new DataSet();
        $data = $dataSet->getData();
        $this->sendResponse("preparando interprete");
        $interpreter = new Interpreter();
        $this->sendResponse("inicializando red neuronal");
        $numInputs = (count(current($data))-1);
        $this->network = new Network($numInputs);
        $this->network->generateWeights();
        $this->sendResponse("inicializacion completa, comenzando entrenamiento");
        $i = 0;
        while ($i < count($data)) { // we espect 90% of assert
            foreach ($data as $row) {
                $interpreter->setData($row);
                $set = $interpreter->getNativeData();
                $last = count($set)-1;
                $this->espectedResult = $set[$last];
                unset($set[$last]);
                $this->network->setInputs($set);
                $this->network->forwardPropagation();
                $this->network->backPropagation(
                    $this->espectedResult
                );
            }
            $i++;
        }

        $this->sendResponse("entrenamiento completado");
        return [""];
    }

    private function setInputLayer(array<float> $inputLayer) :void
    {
        $this->inputLayer = $inputLayer;
    }
}
