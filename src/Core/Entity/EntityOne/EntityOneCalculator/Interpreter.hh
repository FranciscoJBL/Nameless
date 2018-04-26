<?hh //strict

namespace Nameless\Core\Entity\EntityOne\EntityOneCalculator;

use Nameless\Core\Entity\EntityOne\EntityOneCalculator\Codes\Codes;

class Interpreter
{
    private ?array<array<string>> $data;
    private array<?float> $nativeData = [];
    private ?Codes $codes;
    public function __construct(?array<array<string>> $data)
    {
        $this->data = $data;
    }
    public function getNativeData() : array<?float>
    {
        if ($this->data !== null) {
            foreach ($this->data as $register) {
                foreach ($register as $result) {
                    $this->nativeData[] = $this->parseData($result);
                }
            }
        } else {
            $this->nativeData[] = null;
        }
        return $this->nativeData;
    }
    public function parseData(?string $result) : ?float
    {
        if($result !== null) {
            $partial = floatval($result);
            if ($partial === 0.0){
                $partial = $this->getCode($result);
            }
            return $partial;
        }
        return 0.0;
    }
    private function getCode(string $value) : float
    {
        $this->codes = new Codes();
        return $this->codes->getCode($value);
    }
    public function getReadableData(array<float> $data) : array<float>
    {
        return $data;
    }
}