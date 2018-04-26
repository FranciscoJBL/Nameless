<?hh //strict

namespace Nameless\Core\Entity\EntityOne\EntityOneCalculator\Codes;

use Nameless\Core\Entity\EntityOne\EntityOneCalculator\DataSet;
class Codes
{
    public ?DataSet $data;

    public function getCode(string $identifier) : float
    {
        $this->data = new DataSet();
        $dataSet = $this->data->getCodes();
        if($dataSet[$identifier]){
            return $dataSet[$identifier];
        }
        return 0.0;
    }
    public function getValue(float $identifier) : string
    {
        $this->data = new DataSet();
        $dataSet = $this->data->getCodes();
        $aproach = 1000.0;
        $return = '';
        foreach ($dataSet as $k => $v) {
            if(abs($v - $identifier) < $aproach) {
                $aproach = abs($v - $identifier);
                $return = $k;
            }
        }
        if ($aproach === 1000.0){
            $return = 'No entiendo el concepto :( '.strval($identifier);
        }
        return $return;

    }
    public function setCode(string $identifier) : void
    {

    }
}