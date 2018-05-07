<?hh

namespace Nameless\Core\Entity\EntityOne\EntityOneCalculator;

use Nameless\Core\Entity\EntityOne\EntityOneCalculator\Train\Train;
use Nameless\Core\Entity\EntityOne\EntityOneCalculator\DataSet;

class Calculator
{

    public function getConclusion() : array<string>
    {
        $DataSet = new DataSet();
        $train = new Train();
        return $train->makeTrain();

        // 'its supposed that i have to think about that...';
    }
}