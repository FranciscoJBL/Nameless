<?hh //strict
namespace Nameless\Core\Needs\Especific;

use Nameless\Core\Needs\NeedsInterface;
/* The initial need of our entity its just success in the work that we
 * want him to do, so, if you don't want to make it suffer, please don't
 * try to make him do impossible things :(
*/
const TYPE = 1;
class Success implements NeedsInterface
{
    public int $impact;
    public int $satisfaction;

    public function  __construct(int $impact) : void
    {
        $this->impact = $impact;
    }

    public function fullfill(int $range) : int
    {
        $this->impact = ($this->impact * 2) / $range;
        $this->satisfaction = ($this->satisfaction + $range);
        return $this->satisfaction;
    }

    public function drop() : void
    {
        $this->satisfaction -= $this->satisfaction/2;
        $this->impact += $this->impact/2;
    }

    public function adverseEfect() : int
    {
        return 10;
    }
}