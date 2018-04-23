<?hh //strict

namespace Nameless\Core\Entity\EntityOne;

class Calculator
{
    private ?array<string> $data;
    public function setData(?array<string> $data) : void
    {
        $this->data = $data;
    }
    public function getConclusion() : string
    {
        return 'its supposed that i have to think about that...';
    }
}