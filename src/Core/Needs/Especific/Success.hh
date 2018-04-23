<?hh //strict
namespace Nameless\Core\Needs\Especific;

use Nameless\Core\Needs\NeedsInterface;
/* The initial need of our entity its just success in the work that we
 * want him to do, so, if you don't want to make it suffer, please don't
 * try to make him do impossible things :(
*/
const int TYPE = 1;
class Success implements NeedsInterface
{
    public float $impact;
    public float $satisfaction;

    public function  __construct(float $impact) : void
    {
        $this->impact = $impact;
        $this->satisfaction = 1.0;
    }

    public function fullfill(float $range) : float
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

    public function adverseEfect() : float
    {
        return 10.0;
    }
}