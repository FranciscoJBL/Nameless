<?hh //strict

namespace Nameless\Core\Entity\EntityOne\EntityOneCalculator;

use Nameless\Core\Entity\EntityOne\EntityOneCalculator\Codes\Codes;

class Interpreter
{
    private ?array<string> $data;
    private ?Codes $codes;

    public function setData(?array<string> $data) :void
    {
        $this->data = $data;
    }

    public function getNativeData() : array<float>
    {
        if ($this->data !== null) {
            $espectedResult = false;
            $nativeData = [];
            foreach ($this->data as $register) {
                $partial = floatval($register);
                if ($partial === 0.0) {
                    $espectedResult = $this->parseData($register);
                    continue;
                }
                $nativeData[] = $partial;
            }
            if (is_float($espectedResult)) {
                $nativeData[] = $espectedResult;
            }
        }
        return $nativeData;
    }

    public function parseData(string $result) : float
    {
        return $this->getCode($result);
    }

    private function getCode(string $value) : float
    {
        $this->codes = new Codes();
        return $this->codes->getCode($value);
    }

    public function getReadableData(float $data) : string
    {
        if ($this->codes === null) {
            $this->codes = new Codes();
        }
        return $this->codes->getValue($data);

    }
}