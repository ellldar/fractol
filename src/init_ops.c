#include "../includes/fractol.h"

t_image	*init_image(t_scope *scope, int width, int height)
{
	t_image	*image;

	image = (t_image*)malloc(sizeof(t_image));
	image->ptr = mlx_new_image(scope->mlx_ptr, width, height);
	image->addr = mlx_get_data_addr(image->ptr, &image->bits_ppxl, &image->line_size, &image->endian);
	return (image);
}

t_scope	*init_scope(void *mlx_ptr, int width, int height, char *title)
{
	t_scope	*scope;

	scope = (t_scope*)malloc(sizeof(t_scope));
	scope->mlx_ptr = mlx_ptr;
	scope->win_ptr = mlx_new_window(mlx_ptr, width, height, title);
	scope->image = init_image(scope, width, height);
	scope->width = width;
	scope->height = height;
	scope->scale = 4;
	scope->mouse = (t_mouse*)malloc(sizeof(t_mouse));
	ft_bzero(scope->mouse, sizeof(t_mouse));
	scope->key = (t_key*)malloc(sizeof(t_key));
	ft_bzero(scope->key, sizeof(t_key));
	return (scope);
}