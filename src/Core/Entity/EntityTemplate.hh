<?hh //strict

namespace Nameless\Core\Entity;

use Nameless\Core\Needs\NeedsBundle as Needs;
use Nameless\Core\Entity\EntityOne\OneMap as Map;

// A common (forced) implementation of Entity Interfaz
// methods can be reimplemented, or changed the template,
// but every new template has to implements Entity interfaz
abstract class EntityTemplate implements Entity
{
    public Map $map;
    protected ?Needs $needs;

    public function die() :string
    {
        return 'die';
    }

    public function replicate() :string
    {
        return 'replicate';
    }

    public function getMap() : Map
    {
        return $this->map;
    }

    public function setNeeds(Needs $needs) :void
    {
        $this->needs = $needs;
    }
}