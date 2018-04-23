<?hh //strict

namespace Nameless\Core\Senses
;

class WebSense
{
    public ?array<string> $request;
    public ?array<string> $response;

    public function setRequest(array<string> $request) : void
    {
        $this->request = $request;
    }
    public function getRequest() : ?array<string>
    {
        return $this->request;
    }
    public function setResponse(array<string> $response) : void
    {
        $this->response = $response;
    }
    public function getResponse() : ?array<string>
    {
        return $this->response;
    }
}