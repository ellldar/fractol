#include "includes/fractol.h"

static void	init_hooks(t_scope *scope)
{
	mlx_hook(scope->win_ptr, 4, 0, mouse_press, scope);
	mlx_hook(scope->win_ptr, 5, 0, mouse_release, scope);
	mlx_hook(scope->win_ptr, 6, 0, mouse_move, scope);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_scope	*scope;

	mlx_ptr = mlx_init();
	scope = init_scope(mlx_ptr, WIDTH, HEIGHT, "FRACTOL");
	init_hooks(scope);
	draw_mandelbrot(scope);
	mlx_loop(mlx_ptr);
	return (0);
}
