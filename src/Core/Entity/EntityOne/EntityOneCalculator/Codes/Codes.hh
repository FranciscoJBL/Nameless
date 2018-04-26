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
    public function setCode(string $identifier) : void
    {

    }
}