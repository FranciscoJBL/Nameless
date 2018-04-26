<?hh //strict

namespace Nameless\Core\Entity\EntityOne\EntityOneCalculator;

class Concepts
{
    public float $concept = 0.0;
    private ?DataSet $dataset;

    public function __construct(DataSet $dataset) {
        $this->dataset = $dataset;
    }
    public function getConcept(float $data) : float
    {
        $this->cleanConcept($data);
        return $this->concept;

    }
    public function addConcept(float $concept) : void
    {
        $this->concept = $concept;
    }
    public function cleanConcept(float $data) : float
    {
        return $this->concept;
    }
}