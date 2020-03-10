#include "../includes/fractol.h"

void	put_pixel(t_scope *scope, int x, int y, int color)
{
	char	*addr;

	if (is_confined(x, y))
	{
		addr = scope->image->addr;
		addr += y * scope->image->line_size + x * (scope->image->bits_ppxl / 8);
		*(unsigned int*)addr = color;
	}
}

void		render_image(t_scope *scope)
{
	clear_image(scope);
	mlx_put_image_to_window(scope->mlx_ptr, scope->win_ptr, scope->image->ptr, 0, 0);
}

void		clear_image(t_scope *scope)
{
	ft_bzero(scope->image->addr, scope->height * scope->image->line_size);
}