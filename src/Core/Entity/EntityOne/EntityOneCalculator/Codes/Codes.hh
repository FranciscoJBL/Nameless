<?hh //strict

namespace Nameless\Core\Entity\EntityOne\EntityOneCalculator\Codes;

use Nameless\Core\Entity\EntityOne\EntityOneCalculator\DataSet;

class Codes
{
    public DataSet $data;

    public function __construct()
    {
        $this->data = new DataSet();
    }
    public function getCode(string $identifier) : float
    {
        $this->data = new DataSet();

        $value = $this->findConcept($identifier);
        if ($value === null) {
            return $this->data->addCode($identifier);
        } else {
            return $value;
        }
    }
    private function findConcept(string $identifier) : ?float
    {
        if($this->data === null) {
            $this->data = new DataSet();
        }
        $dataSet = $this->data->getCodes();
        if (array_key_exists($identifier, $dataSet)) {
            return floatval($dataSet[$identifier]);
        }

        return null;
    }
    public function getValue(float $identifier) : string
    {
        if($this->data === null) {
            $this->data = new DataSet();
        }

        $dataSet = $this->data->getCodes();
        $aproach = 1000.0;
        $return = '';

        foreach ($dataSet as $k => $v) {
            if(abs($v - $identifier) < $aproach) {
                $aproach = abs($v - $identifier);
                $return = $k;
            }
        }

        if ($aproach >= 1000.0) {
            $return = 'No entiendo el concepto :( '.strval($identifier);
        }

        return $return;
    }

    public function setCode(string $identifier) : void
    {

    }
}