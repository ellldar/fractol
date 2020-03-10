#include "../includes/fractol.h"

int		is_confined(int x, int y)
{
	return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT);
}