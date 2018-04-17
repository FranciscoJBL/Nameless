<?hh //strict

namespace Nameless\Core\Entity;

use Nameless\Core\Needs\NeedsBundle as Needs;
use Nameless\Core\Entity\EntityOne\OneMap as Map;
// A common (forced) implementation of Entity Interfaz
// methods can be reimplemented, or changed the template,
// but every new template has to implements Entity interfaz
class EntityTemplate implements Entity
{
    protected Map $map;
    protected Needs $needs;

    public function born() :string
    {
        $this->setNeeds($this->map->getNeeds());
        return 'born';
    }

    public function die() :string
    {
        return 'die';
    }

    public function Replicate() :string
    {
        return 'replicate';
    }

    public function getMap() : Map
    {
        return $this->map;
    }

    public function setNeeds(Needs $needs) :void
    {
        $this->Needs = $needs;
    }
}