<?hh //strict

namespace Nameless\Core\Entity;

use Nameless\Core\Entity\EntityOne\OneMap as Map;
//all our entities, no matter its clasification, MUST have those methods.
interface Entity
{
    public function die() :string;
    public function replicate() :string;
    public function getMap() : Map;
}