<?hh //strict

namespace Nameless\Core\Entity\EntityOne\EntityOneCalculator;

use Nameless\Core\Entity\EntityOne\EntityOneCalculator\Concepts;

class DataSet
{
     private ?Concepts $concepts;
     private ?Map<string,float> $data;
     private ?array<array<string>> $dataset;

     public function getCodes() : Map<string,float>
     {
          if ( ! $this->concepts) {
               $this->concepts = new Concepts();
          }

          $this->data = $this->concepts->getConcept();
          return $this->data;
     }
     public function getData() : array<array<string>>
     {
          if ( ! $this->concepts) {
               $this->concepts = new Concepts();
          }

          $this->dataset = $this->concepts->getMemorizedData();

          return $this->dataset;
     }
     public function addCode(string $identifier) : float
     {
          $value = floatval(mt_rand(100, 1000000)) * 100;
          if ( ! $this->concepts) {
               $this->concepts = new Concepts();
          }
          $this->concepts->addConcept($identifier, $value);
          return $value;
     }
}


