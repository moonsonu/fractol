/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 19:05:43 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/19 20:23:03 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void		f_color(t_fractol *m, int x, int y, int n)
{
	int		i;

	i = (x * 4) + (y * m->size);
	m->data[i] = n;
	m->data[++i] = 255 * n;
	m->data[++i] = n % 255;
	//printf("data[%d] = [%d]\n", i, m->data[i]);
}

void	julia(t_fractol *m)
{
	double	zx;
	double	zy;
	double	xtemp;
	int		x;
	int		y;
	int		i;

	m->iter = 50;
	m->zoom = 1;
	m->x_move = 0;
	m->y_move = 0;
	y = -1;
	while (++y < WIN)
	{
		x = -1;
		while (++x < WIN)
		{
			zx = 1.5 * (x - (WIN / 2)) / (WIN * 0.5 * m->zoom) + m->x_move;
			zy = (y - WIN / 2) / (WIN * 0.5 * m->zoom) + m->y_move;
			i = 0;
			while ((zx * zx) + (zy * zy) < 4 && i < m->iter)
			{
				xtemp = zx * zx - zy * zy;
				zy = 2 * zx * zy - 0.662;
				zx = xtemp + 0.282;
				i++;
			}
			if (i < m->iter)
				f_color(m, x, y, 1000 * i);
		}
	}
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->image, 0, 0);
}

void	mandelbrot(t_fractol *m)
{
	double	zx;
	double	zy;
	double	xtemp;
	int		x;
	int		y;
	int		i;
	int		x0;
	int		y0;

	m->iter = 50;
	m->zoom = 1;
	m->x_move = 0;
	m->y_move = 0;
	y = -1;
	while (++y < WIN)
	{
		x = -1;
		while (++x < WIN)
		{
			zx = 1.5 * (x - (WIN / 2)) / (WIN * 0.5 * m->zoom) + m->x_move;
			zy = (y - WIN / 2) / (WIN * 0.5 * m->zoom) + m->y_move;
			x0 = zx;
			y0 = zy;
			i = 0;
			while ((zx * zx) + (zy * zy) < 4 && i < m->iter)
			{
				xtemp = zx * zx - zy * zy + x0;
				zy = 2 * zx * zy + y0;
				zx = xtemp;
				i++;
			}
			if (i < m->iter)
				f_color(m, x, y, 1000 * i);
		}
	}
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->image, 0, 0);
}

int		keyfunction(int key, t_fractol *m)
{
	(void)m;
	key == 53 ? exit(0) : 0;
	return (0);
}

void		init_mlx(t_fractol *m)
{
	m->mlx_ptr = mlx_init();
	m->win_ptr = mlx_new_window(m->mlx_ptr, WIN, WIN, "FRACT'OL by KSONU");
	m->image = mlx_new_image(m->mlx_ptr, WIN, WIN);
	m->data = mlx_get_data_addr(m->image, &m->bpp, &m->size, &m->endian);
}

void		error_message(void)
{
	ft_putendl("usage : ./fractol [fractal set]\n");
	ft_putendl("[fractal sets]	Mandelbrot");
	ft_putendl("		Julia");
	exit(0);
}

int			main(int ac, char **av)
{
	t_fractol	*m;

	m = (t_fractol*)malloc(sizeof(t_fractol));
	if (ac != 2)
		error_message();
	//m->fractal = av[1];
	init_mlx(m);
	if (!ft_strcmp(av[1], "Mandelbrot"))
		mandelbrot(m);
	if (!ft_strcmp(av[1], "Julia"))
		julia(m);
	mandelbrot(m);
	mlx_hook(m->win_ptr, 2, 0, keyfunction, m);
	mlx_loop(m->mlx_ptr);
}
