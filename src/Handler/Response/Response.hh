<?hh //strict

namespace Nameless\Handler\Response;

use Nameless\Core\Entity\Entity;

class Response
{
    private ?Entity $entity;

    public function __construct(?Entity $entity)
    {

    }
}