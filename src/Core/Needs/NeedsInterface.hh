<?hh //strict

namespace Nameless\Core\Needs;

//a common interface for any Need
interface NeedsInterface
{
    public function fullfill(int $range):int;
    public function drop() : void;
    public function adverseEfect() : int;
}



