<?hh //strict

namespace Nameless\Core\Entity\EntityOne\EntityOneCalculator;

class Interpreter
{
    private ?array<string> $data;
    public function __construct(?array<string> $data)
    {
        $this->data = $data;
    }
    public function getNativeData() : array<float>
    {
        return [10.0, 1.2, 2.1, 4.2];
    }
    public function getReadableData(array<float> $data) : array<float>
    {
        return ($data);
    }
}