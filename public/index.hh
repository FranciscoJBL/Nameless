<?hh

use Nameless\Handler\Handler;
use Nameless\Core\Entity\EntityOne\EntityOneCalculator\Network\Network;
require '../vendor/autoload.php';
$request = [];

if ($_REQUEST) {
    $request = $_REQUEST;
} elseif ($argv) {
    unset($argv[0]);
    $request = $argv;
}

$network = new Network([0.0, 0.0]);
$network->generateWeights();
exit();

$handler = new Handler($request);
$handler->processRequest();
$handler->generateResponse();
$handler->getResponse();
//print_r($handler->getResponse());


