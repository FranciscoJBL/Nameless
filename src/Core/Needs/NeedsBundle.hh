<?hh //strict

namespace Nameless\Core\Needs;

use Nameless\Core\Needs\NeedsInterface;
use Nameless\Core\Needs\Especific\Success as Need;
//this its a object container for NeedsInterface
//acts as a decorator

class NeedsBundle
{
    private Need $need;
    //we register our needs
    public function addNeeds(Need $need) : void
    {
        $this->need = $need;
    }
    public function getNeeds(Need $need) : Need
    {
        return $this->need;
    }
}