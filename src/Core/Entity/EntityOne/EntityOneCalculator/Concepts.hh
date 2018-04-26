<?hh //strict

namespace Nameless\Core\Entity\EntityOne\EntityOneCalculator;

class Concepts
{
    public array<float> $concept = [];
    private ?DataSet $dataset;

    public function __construct(DataSet $dataset) {
        $this->dataset = $dataset;
    }
    public function getConcept(float $data) : array<float>
    {
        $this->cleanConcept($data);
        return $this->concept;

    }
    public function addConcept(float $concept) : void
    {
        $this->concept[] = $concept;
    }
    public function cleanConcept(float $data) : array<float>
    {
        return $this->concept;
    }
}