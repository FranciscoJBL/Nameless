<?hh //strict

namespace Nameless\Core\Entity\EntityOne\EntityOneCalculator\Network;

class Neuron
{
    private float $bias;
    public float $value;
    public int $identifier;
    public function __construct(float $value,int  $identifier, bool $endPoint = false) : void
    {
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
    public function adjustWeights() : void
    {

    }
    public function setValue(float $value) : void
    {
        $this->value += $value * $this->bias;
    }
    public function getValue() : float
    {
        return $this->value;
    }
    public function getIdentity()
    {
        return $this->identifier;
    }
}
