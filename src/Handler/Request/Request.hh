<?hh //strict

namespace Nameless\Handler\Request;

use Nameless\Core\Entity\Entity;
class Request
{
    private ?Entity $entity;

    public function __construct(?Entity $entity, array<string> $request)
    {
        $this->entity = $entity;
        if ($this->entity !== null) {
            $this->entity
                ->getMap()
                ->getWebsense()
                ->setRequest($request);
        }
    }
}