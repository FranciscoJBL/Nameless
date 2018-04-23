<?hh //strict

namespace Nameless\Core\Entity\EntityOne;

use Nameless\Core\Entity\EntityTemplate as Template;
use Nameless\Core\Entity\EntityOne\OneMap;

class EntityOne extends Template
{

    public function __construct(OneMap $map) : void
    {
        $this->map = $map;
        $this->needs = ($this->map->getNeeds());
    }
}