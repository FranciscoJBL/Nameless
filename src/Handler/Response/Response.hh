<?hh //strict

namespace Nameless\Handler\Response;

use Nameless\Core\Entity\Entity;

class Response
{
    private ?Entity $entity;

    public function __construct(?Entity $entity)
    {
        $this->entity = $entity;
    }
    public function getResponse() : array<float>
    {
        if ($this->entity !== null) {
            $this->makeResponse(
                $this->entity
                    ->getMap()
                    ->analize()
            );
        }
        return [0.0];
    }
    public function makeResponse(array<mixed> $result) :void
    {
        print_r("holi\n");
        print_r($result);
        print_r("\n");
    }
}