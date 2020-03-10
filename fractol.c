#include "includes/fractol.h"

int	main(void)
{
	t_scope	*scope;
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	scope = init_scope(mlx_ptr, WIDTH, HEIGHT, "FRACTOL");
	printf("TEST!\n");
	put_pixel(scope, WIDTH / 2, HEIGHT / 2, 0xFFFFFF);
	render_image(scope);
	mlx_loop(mlx_ptr);
	return (0);
}
