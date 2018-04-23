<?hh //strict

namespace Nameless\Handler;

use Nameless\Handler\Request\Request;
use Nameless\Handler\Response\Response;
use Nameless\Core\Entity\EntityFactory;

class Handler
{
    private array<string> $request;
    public ?string $response;
    private EntityFactory $factory;
    public function __construct(array<string> $request)
    {
        $this->factory = new EntityFactory();
        $this->request = $request;
    }

    public function processRequest() : void
    {
        $request = new Request(
            $this->factory->getEntity('EntityOne'),
            $this->request
        );

        //in the future, we will send request to our request object,
        //and make funny things with that :D
    }

    public function generateResponse() :void
    {
        $response = new Response(
            $this->factory->getEntity('EntityOne'),
        );
    }

    public function getResponse() : ?string
    {
        return $this->response;
    }
}