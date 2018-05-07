<?hh //strict

namespace Nameless\Core\Entity\EntityOne\EntityOneCalculator;

class Concepts
{
    public float $concept = 0.0;
    private string $dataFolder = '../src/Core/Entity/EntityOne/EntityOneCalculator/Data/';

    public function __construct()
    {

    }
    public function getMemorizedData() : array<array<string>>
    {
        $file = $this->dataFolder."1000.dat";
        $outputFile = fopen($file, 'r');
        $concept = fread($outputFile, filesize($file));
        return json_decode($concept, true);
    }

    public function getConcept() : Map<string,float>
    {
        $file = $this->dataFolder."concept.dat";
        $outputFile = fopen($file, 'r');
        if(filesize($file) <= 0) {
            return new Map(null);
        }
        $concept = fread($outputFile, filesize($file));

        return new Map(json_decode($concept, true));
    }

    public function addConcept(string $concept, float $value) : void
    {
        $file = $this->dataFolder.'concept.dat';
        $concepts = $this->getConcept();
        $concepts[] = Pair{$concept, $value};
        $outputFile = fopen($file, 'w');
        fwrite($outputFile, json_encode($concepts));
        /*
        $file = $this->dataFolder.$concept.'.dat';
        $outputFile = fopen($file, 'w');
        fwrite($outputFile, json_encode($dataSet));
        */
    }
}