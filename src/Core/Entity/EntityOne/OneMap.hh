<?hh //strict

namespace Nameless\Core\Entity\EntityOne;

use Nameless\Core\Needs\NeedsBundle as Needs;
use Nameless\Core\Needs\Especific\Success as Need;
use Nameless\Core\Needs\Especific\Success as Success;
// the map, genoma, of EntityOne
class OneMap
{
    //needs
    public Need $success;

    public function __construct() : void
    {
        $this->success = new success(10);
    }
    public function getNeeds() : Needs
    {
        $needs =  new Needs();
        $needs->addNeeds($this->getSuccess());
        return $needs;
    }
    public function getSuccess() : Need
    {
        return $this->success;
    }

    public function setSuccess(Need $success): void
    {
        $this->success = $success;
    }
}