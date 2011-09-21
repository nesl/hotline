
#include "coord2d.h"
#include "Vector.h"

module Vector2dC {
    provides interface Vector<pose2d_t> as Vector2d;
}

implementation {

    command void Vector2d.add(pose2d_t *base, pose2d_t *rel, 
                              pose2d_t *add_pose) {
        float rad = RADIANS(base->a);
        add_pose->loc.x = base->loc.x + rel->loc.x*cos(rad) - rel->loc.y*sin(rad);
        add_pose->loc.y = base->loc.y + rel->loc.x*sin(rad) + rel->loc.y*cos(rad);
        add_pose->a = normalize(base->a + rel->a);
    }

}
