<?hh //strict

namespace Nameless\Core\Entity;

use Nameless\Core\Entity\EntityOne\EntityOne;
use Nameless\Core\Entity\EntityOne\OneMap;
use Nameless\Core\Entity\Entity;
//A factory class, and this makes the role of a singleton too
class EntityFactory
{
    public static ?Entity $entity = null;

    public function createNewborn(string $type) : ?Entity
    {
        if ($type == 'EntityOne') {
            self::$entity = new EntityOne(new OneMap());
        }

        return self::$entity;
    }
    public function getEntity(string $type) : ?Entity
    {
        if (self::$entity === null) {
            $this->createNewborn($type);
        }
        return self::$entity;
    }
}