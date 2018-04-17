<?hh //strict

namespace Nameless\Core\Entity;
//all our entities, no matter its clasification, MUST have those methods.
interface Entity
{
    public function die() :string;
    public function born() :string;
    public function replicate() :string;
}