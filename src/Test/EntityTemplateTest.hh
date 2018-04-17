<?hh //strict

namespace Nameless\Core\Test;

use PHPUnit\Framework\TestCase;
use Nameless\Core\Entity\EntityTemplate as Template;
use Nameless\Core\Entity\EntityOne\OneMap as Map;
use Nameless\Core\Entity\EntityOne\EntityOne as EntityOne;

class EntityTemplateTest extends TestCase
{
    public function testBorn(): void
    {
        $result = 'born';
        $map = new Map();
        $template = new EntityOne($map);
        $this->assertEquals(
            $result,
            $template->born()
        );
    }
    public function testDie(): void
    {
        $map = new Map();
        $template = new EntityOne($map);
        $result = 'die';
        $this->assertEquals(
            $result,
            $template->die()
        );
    }
    public function testReplicate(): void
    {
        $map = new Map();
        $template = new EntityOne($map);
        $result = 'replicate';
        $this->assertEquals(
            $result,
            $template->replicate()
        );
    }
    public function testGetMap(): void
    {
        $map = new Map();
        $template = new EntityOne($map);
        $result = new Map();
        $this->assertEquals(
            $result,
            $template->getMap()
        );
    }
}