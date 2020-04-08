//
// Created by Eldar Supataev on 4/7/20.
//

#include "../includes/fractol.h"

void	draw_mandelbrot(t_scope *scope)
{
	double		x;
	double		y;
	double		re;
	int 		i;
	int 		j;
	t_complex	z;
	int 		n;
	t_list		head;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		y = to_complex(i, HEIGHT, scope->scale);
		while (j < WIDTH)
		{
			z.re = 0.0;
			z.im = 0.0;
			x = to_complex(j, WIDTH, scope->scale);
			n = 0;
			while (n < 0xFF)
			{
				re = pow(z.re, 2) - pow(z.im, 2) + x;
				z.im = 2 * z.re * z.im + y;
				z.re = re;
				if (!(fabs(z.re) < 4 && fabs(z.im) < 4))
					break;
				n++;
			}
			if (n == 0xFF)
				put_pixel(scope, j, i, 0x057389);
			else
				put_pixel(scope, j, i, ((0xEF - n) << 16) + ((0xCF - n) << 8) + (0xD0 - n));
			j++;
		}
		i++;
	}
	render_image(scope);
}