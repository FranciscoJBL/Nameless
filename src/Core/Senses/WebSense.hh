<?hh //strict

namespace Nameless\Core\Senses;

use Nameless\Core\Entity\EntityOne\EntityOneCalculator\DataSet;


class WebSense
{
    public ?DataSet $request;
    public ?array<string> $response;

    public function setRequest(array<string> $request) : void
    {
        $this->request = new DataSet();
    }
    public function getRequest() : ?array<array<string>>
    {
        if($this->request === null) {
            return null;
        }
        return $this->request->getData();
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