<?hh

namespace Nameless\Core\Entity\EntityOne\EntityOneCalculator;

use Nameless\Core\Entity\EntityOne\EntityOneCalculator\Train\Train;

class Calculator
{

    public function getConclusion() : array<string>
    {

        $train = new Train();

        return $train->makeTrain();

        // 'its supposed that i have to think about that...';
    }
}