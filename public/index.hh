<?hh

use Nameless\Handler\Handler;

require '../vendor/autoload.php';

$request = [];

if ($_REQUEST) {
    $request = $_REQUEST;
} elseif ($argv) {
    unset($argv[0]);
    $request = $argv;
}

$handler = new Handler($request);
$handler->processRequest();
$handler->generateResponse();
echo $handler->getResponse();


