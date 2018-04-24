<?hh //strict

namespace Nameless\Core\Entity\EntityOne\EntityOneCalculator;

use Nameless\Core\Entity\EntityOne\EntityOneCalculator\Interpreter;
use Nameless\Core\Entity\EntityOne\EntityOneCalculator\Concepts;

class Calculator
{
    private ?array<string> $data;
    public function setData(?array<string> $data) : void
    {
        $this->data = $data;
    }
    public function getConclusion() : string
    {
        $interpreter = new Interpreter($this->data);
        $concept = new Concepts();

        return $interpreter->getReadableData(
            $concept->getConcept(
                $this->inputData($interpreter->getNativeData())
            )
        );

        return 'its supposed that i have to think about that...';
    }
    private function inputData(array<float> $inputs) : array<float>
    {
        return [0.1];
    }
}