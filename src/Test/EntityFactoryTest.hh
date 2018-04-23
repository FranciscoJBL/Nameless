<?hh

namespace Nameless\Core\Test;

use PHPUnit\Framework\TestCase;
use Nameless\Core\Entity\EntityFactory as Factory;
use Nameless\Core\Entity\EntityOne\EntityOne;
use Nameless\Core\Needs\NeedsBundle as Needs;
use Nameless\Core\Entity\EntityOne\OneMap as Map;

class EntityFactoryTest extends TestCase
{
    public function testCreateNewborn(): void
    {
        $map = new Map();
        $factory = new Factory();
        $entity = new EntityOne($map);

        $this->assertEquals(
            $entity,
            $factory->createNewborn('EntityOne')
        );
    }
}