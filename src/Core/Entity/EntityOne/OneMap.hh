<?hh //strict

namespace Nameless\Core\Entity\EntityOne;

use Nameless\Core\Senses\WebSense as WebS;
use Nameless\Core\Needs\NeedsBundle as Needs;
use Nameless\Core\Needs\Especific\Success as Need;
use Nameless\Core\Needs\Especific\Success as Success;
// the map, genoma, of EntityOne
class OneMap
{
    //needs
    public Need $success;

    public WebS $websense;

    public function __construct() : void
    {
        $this->success = new Success(10.0);
        $this->websense = new WebS();
    }
    //this its no more than a decorator
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
    public function getWebsense() : WebS
    {
        return $this->websense;
    }

    public function setWebsense(WebS $WebS): void
    {
        $this->websense = $WebS;
    }
}