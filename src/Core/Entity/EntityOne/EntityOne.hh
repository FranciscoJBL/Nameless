<?hh //strict

namespace Nameless\Core\Entity\EntityOne;

use Nameless\Core\Entity\Entity as Entity;
use Nameless\Core\Entity\EntityTemplate as Template;

class EntityOne extends Template
{
    public function __construct($map) : void
    {
        $this->map = $map;
        $this->born();
    }
}