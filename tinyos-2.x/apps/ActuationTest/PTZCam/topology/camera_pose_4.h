
void get_pose(uint16_t node, pose2d_t *p) {
	switch (node) {
		case 0:
		{
			p->loc.x = 0;
			p->loc.y = 0;
			p->a = 0;
			break;
		}
		case 1:
		{
			p->loc.x = 100;
			p->loc.y = 0;
			p->a = 0;
			break;
		}
		case 2:
		{
			p->loc.x = 200;
			p->loc.y = 0;
			p->a = 0;
			break;
		}
		case 3:
		{
			p->loc.x = 700;
			p->loc.y = 0;
			p->a = 0;
			break;
		}
		case 4:
		{
			p->loc.x = 800;
			p->loc.y = 0;
			p->a = 0;
			break;
		}
		case 5:
		{
			p->loc.x = 0;
			p->loc.y = 100;
			p->a = 0;
			break;
		}
		case 6:
		{
			p->loc.x = 100;
			p->loc.y = 100;
			p->a = 0;
			break;
		}
		case 7:
		{
			p->loc.x = 400;
			p->loc.y = 100;
			p->a = 0;
			break;
		}
		case 8:
		{
			p->loc.x = 500;
			p->loc.y = 100;
			p->a = 0;
			break;
		}
		case 9:
		{
			p->loc.x = 700;
			p->loc.y = 100;
			p->a = 0;
			break;
		}
		case 10:
		{
			p->loc.x = 800;
			p->loc.y = 100;
			p->a = 0;
			break;
		}
		case 11:
		{
			p->loc.x = 0;
			p->loc.y = 200;
			p->a = 0;
			break;
		}
		case 12:
		{
			p->loc.x = 400;
			p->loc.y = 200;
			p->a = 0;
			break;
		}
		case 13:
		{
			p->loc.x = 500;
			p->loc.y = 200;
			p->a = 0;
			break;
		}
		case 14:
		{
			p->loc.x = 600;
			p->loc.y = 200;
			p->a = 0;
			break;
		}
		case 15:
		{
			p->loc.x = 900;
			p->loc.y = 200;
			p->a = 0;
			break;
		}
		case 16:
		{
			p->loc.x = 100;
			p->loc.y = 300;
			p->a = 0;
			break;
		}
		case 17:
		{
			p->loc.x = 300;
			p->loc.y = 300;
			p->a = 0;
			break;
		}
		case 18:
		{
			p->loc.x = 400;
			p->loc.y = 300;
			p->a = 0;
			break;
		}
		case 19:
		{
			p->loc.x = 500;
			p->loc.y = 300;
			p->a = 0;
			break;
		}
		case 20:
		{
			p->loc.x = 700;
			p->loc.y = 300;
			p->a = 0;
			break;
		}
		case 21:
		{
			p->loc.x = 800;
			p->loc.y = 300;
			p->a = 0;
			break;
		}
		case 22:
		{
			p->loc.x = 900;
			p->loc.y = 300;
			p->a = 0;
			break;
		}
		case 23:
		{
			p->loc.x = 400;
			p->loc.y = 400;
			p->a = 0;
			break;
		}
		case 24:
		{
			p->loc.x = 900;
			p->loc.y = 400;
			p->a = 0;
			break;
		}
		default:
		{
			p->loc.x = 0;
			p->loc.y = 0;
			p->a = 0;
			break;
		}
	}
}

