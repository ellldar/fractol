#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft-wip-version/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <unistd.h>

# include <stdlib.h>
# include <stdio.h>
# include <time.h>

# define WIDTH	1024
# define HEIGHT	720

typedef struct	s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct	s_mouse
{
	int		x1;
	int		y1;
	int		pressed:1;
	int		button:2;
}				t_mouse;

typedef struct	s_key
{
	int		pressed:1;
	int		button:10;
}				t_key;

typedef struct	s_image
{
	void	*ptr;
	char	*addr;
	int		bits_ppxl;
	int		line_size;
	int		endian;
}				t_image;

typedef struct	s_scope
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	*image;
	t_mouse	*mouse;
	t_key	*key;
	int		width;
	int		height;
	int		scale;
}				t_scope;

t_image			*init_image(t_scope *scope, int width, int height);
t_scope			*init_scope(void *mlx_ptr, int width, int height, char *title);
void			put_pixel(t_scope *scope, int x, int y, int color);
void			render_image(t_scope *scope);
void			clear_image(t_scope *scope);
void			set_background(t_scope *scope, int color);

int				mouse_press(int button, int x, int y, t_scope *scope);
int				mouse_release(int button, int x, int y, t_scope *scope);
int				mouse_move(int x, int y, t_scope *scope);

void			draw_mandelbrot(t_scope *scope);

int				is_confined(int x, int y);
double			to_complex(int n, int plane, int scale);

#endif