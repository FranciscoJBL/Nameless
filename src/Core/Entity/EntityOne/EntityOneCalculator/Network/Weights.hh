<?hh //strict

namespace Nameless\Core\Entity\EntityOne\EntityOneCalculator\Network;

class Weights
{
    public int $initialNeuron;
    public int $finalNeuron;
    public float $value;

    public function __construct(int $initialNeuron, int $finalNeuron,float $value)
    {
        $this->initialNeuron = $initialNeuron;
        $this->finalNeuron = $finalNeuron;
        $this->value = $value;
    }
    public function getInital() :int
    {
        return $this->initial;
    }
        public function getFinal() :int
    {
        return $this->finalNeuron;
    }
        public function getValue() :float
    {
        return $this->value;
    }
}


