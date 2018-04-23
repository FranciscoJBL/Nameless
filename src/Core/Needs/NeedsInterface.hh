<?hh //strict

namespace Nameless\Core\Needs;

//a common interface for any Need
interface NeedsInterface
{
    public function fullfill(float $range):float;
    public function drop() : void;
    public function adverseEfect() : float;
}



