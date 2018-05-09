<?hh //strict

namespace Nameless\Core\Entity\EntityOne\EntityOneCalculator\Network;

class Weights
{
    public int $initialNeuron;
    public int $finalNeuron;
    public float $value;
    public float $oldValue;

    public function __construct(int $initialNeuron, int $finalNeuron,float $value)
    {
        $this->initialNeuron = $initialNeuron;
        $this->finalNeuron = $finalNeuron;
        $this->value = $value;
    }
    public function getInitial() :int
    {
        return $this->initialNeuron;
    }
    public function getFinal() :int
    {
        return $this->finalNeuron;
    }
    public function getValue() :float
    {
        return $this->value;
    }
    public function setValue(float $value) :void
    {
        $this->value = $value;
    }
    public function getOldValue() :float
    {
        return $this->oldValue;
    }

    public function setOldValue(float $value) :void
    {
        $this->oldValue = $value;
    }
}


