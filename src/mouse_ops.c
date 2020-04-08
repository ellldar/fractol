//
// Created by Eldar Supataev on 4/7/20.
//

#include "../includes/fractol.h"

int	mouse_press(int button, int x, int y, t_scope *scope)
{
	scope->mouse->pressed = 1;
	scope->mouse->button = button;
	if (button == 2)
	{
		clear_image(scope);
		render_image(scope);
	}
	printf("Mouse key pressed! - %i\n", button);
	return (0);
}

int	mouse_release(int button, int x, int y, t_scope *scope)
{
	scope->mouse->pressed = 0;
	scope->mouse->button = 0;
	return (0);
}

int	mouse_move(int x, int y, t_scope *scope)
{
	if(is_confined(x, y) && scope->mouse->button && scope->mouse->pressed)
		put_pixel(scope, x, y, 0xFFFFFF);
	return (0);
}