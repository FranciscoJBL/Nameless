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
            return $this->entity
                ->getMap()
                ->analize();
        }
        return [0.0];
        //return 'something went really bad...';
    }
}