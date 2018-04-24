<?hh //strict

namespace Nameless\Core\Entity\EntityOne\EntityOneCalculator;

class Concepts
{
    public array<float> $concept = [10.0];

    public function getConcept(array<float> $data) : array<float>
    {
        return $data;
    }
    public function addConcept(float $concept) : void
    {
        $this->concept[] = $concept;
    }
}