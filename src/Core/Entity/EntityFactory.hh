<?hh //strict

namespace Nameless\Core\Entity;

use Nameless\Core\Entity\EntityOne\EntityOne;
use Nameless\Core\Entity\EntityOne\OneMap;
//A factory class to give life :)
class EntityFactory
{
    public function createNewborn($type) : Entity
    {
        if ($type == 'EntityOne') {
            $entity = new  EntityOne(new OneMap());
            return $entity;
        }
    }
}