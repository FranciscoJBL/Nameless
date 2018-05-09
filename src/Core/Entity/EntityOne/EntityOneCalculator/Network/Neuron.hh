<?hh //strict

namespace Nameless\Core\Entity\EntityOne\EntityOneCalculator\Network;

class Neuron
{
    private float $bias;

    public float $value;

    public bool $endPoint = false;

    public int $identifier;
    public function __construct(float $value,int  $identifier, bool $endPoint = false) : void
    {
        $this->endPoint = $endPoint;
        if ($endPoint === false) {
            $this->bias = floatval(rand(0, 1));
        } else {
            $this->bias = 1.0;
        }
        $this->value = $value;
        $this->identifier = $identifier;
    }

    public function comunicate(float $neuron) : float
    {
        return $this->value * 1.0;
    }

    public function setValue(float $value) : void
    {
        if ($this->endPoint === true) {
            $this->value = round($value, 6);
        } else {
            $this->value += round($value, 4);
        }
    }

    public function getValue() : float
    {
        if ($this->value == 0) {
            return 1.0;
        }
        return $this->value;
    }

    public function getIdentity()
    {
        return $this->identifier;
    }
}
