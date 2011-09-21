
void get_pose(uint16_t node, pose2d_t *p) {
    uint16_t i = node % GRID_SIZE;
    uint16_t j = node / GRID_SIZE;
    p->loc.x = i*100;
    p->loc.y = j*100;
    p->a = 0;
}


