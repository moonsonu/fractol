/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:32:26 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/21 15:21:25 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*phoenix(void *thread)
{
	t_fractol *m = (t_fractol *)thread;
	double	zx;
	double	zy;
	double	xtemp;
	int		x;
	int		y;
	int		i;
	double	x0;
	double	y0;

	y = -1;
	while (++y < WIN)
	{
		x = -1;
		while (++x < WIN)
		{
			zx = 1.5 * (x - (WIN / 2)) / (WIN * 0.2 * m->zoom) + m->x_move;
			zy = (y - WIN / 2) / (WIN * 0.2 * m->zoom) + m->y_move;
			x0 = zx;
			y0 = zy;
			i = 0;
			while ((zx * zx) + (zy * zy) < 4 && i < m->iter)
			{
				xtemp = zx * zx - zy * zy - (0.5 * zx) - (0.5 * x0);
				zy = 2 * zx * zy - (0.5 * zy) - (0.5 * y0) * ((double)m->cursor_y / WIN * 3);
				zx = xtemp + 0.5667 * ((double)m->cursor_x / WIN * 3);
				i++;
			}
			if (i < m->iter && i > 0)
				f_color(m, x, y, 1000 * i);
		}
	}
	return (NULL);
	//mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->image, 0, 0);
}

void	*burningship(void *thread)
{
	t_fractol *m = (t_fractol *)thread;
	double	zx;
	double	zy;
	double	xtemp;
	int		x;
	int		y;
	int		i;
	double	x0;
	double	y0;

	y = -1;
	while (++y < WIN)
	{
		x = -1;
		while (++x < WIN)
		{
			zx = (x - (WIN / 2)) / (WIN * 0.2 * m->zoom) + m->x_move;
			zy = (y - WIN / 2) / (WIN * 0.2 * m->zoom) + m->y_move;
			x0 = zx;
			y0 = zy;
			i = 0;
			while ((zx * zx) + (zy * zy) < 4 && i < m->iter)
			{
				xtemp = zx * zx - zy * zy;
				zy = fabs(2 * zx * zy) + y0 * ((double)m->cursor_y / WIN * 2);
				zx = fabs(xtemp + x0) * ((double)m->cursor_x / WIN * 2);
				i++;
			}
			if (i < m->iter && i > 0)
				f_color(m, x, y, 1000 * i);
		}
	}
	return (NULL);
}
void	*julia(void *thread)
{
	t_fractol *m = (t_fractol *)thread;
	double	zx;
	double	zy;
	double	xtemp;
	int		x;
	int		y;
	int		i;

	y = -1;
	while (++y < WIN)
	{
		x = -1;
		while (++x < WIN)
		{
			zx = 1.5 * (x - (WIN / 2)) / (WIN * 0.2 * m->zoom) + m->x_move;
			zy = (y - WIN / 2) / (WIN * 0.2 * m->zoom) + m->y_move;
			i = 0;
			while ((zx * zx) + (zy * zy) < 4 && i < m->iter)
			{
				xtemp = zx * zx - zy * zy;
				zy = 2 * zx * zy + 0.745 / ((double)m->cursor_y / WIN * 3);
				zx = xtemp + 0.113 / ((double)m->cursor_x / WIN * 3);
				i++;
			}
			if (i < m->iter && i > 0)
				f_color(m, x, y, 1000 * i);
		}
	}
	return (NULL);
	//mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->image, 0, 0);
}

void	*mandelbrot(void *thread)
{
	t_fractol *m = (t_fractol *)thread;
	double	zx;
	double	zy;
	double	xtemp;
	int		x;
	int		y;
	int		i;
	double	x0;
	double	y0;

	y = -1;
	while (++y < WIN)
	{
		x = -1;
		while (++x < WIN)
		{
			zx = (x - (WIN / 2)) / (WIN * 0.2 * m->zoom) + m->x_move;
			zy = (y - WIN / 2) / (WIN * 0.2 * m->zoom) + m->y_move;
			x0 = zx;
			y0 = zy;
			i = 0;
			while ((zx * zx) + (zy * zy) < 4 && i < m->iter)
			{
				xtemp = zx * zx - zy * zy;
				zy = 2 * zx * zy + y0;
				zx = xtemp + x0;
				i++;
			}
			if (i < m->iter && i > 0)
				f_color(m, x, y, 1000 * i);
		}
	}
	return (NULL);
}

void	f_multithrd(t_fractol *m)
{
	int			i;
	pthread_t	t[4];
	t_fractol	thread[4];

	i = -1;
	while (++i < 4 && (ft_memcpy((void*)&thread[i], m, sizeof(t_fractol))))
	{
		thread[i].start = i * (WIN / 4);
		thread[i].end = (i + 1) * (WIN / 4);
	}
	i = -1;
	while (++i < 4)
	{
		if (!ft_strcmp(m->fractal, "Mandelbrot") || !ft_strcmp(m->fractal, "mandelbrot"))
			pthread_create(&t[i], NULL, mandelbrot, &thread[i]);
		if (!ft_strcmp(m->fractal, "Julia") || !ft_strcmp(m->fractal, "julia"))
		{
			m->cursor = 1;
			pthread_create(&t[i], NULL, julia, &thread[i]);
		}
		if (!ft_strcmp(m->fractal, "Burningship") || !ft_strcmp(m->fractal, "burningship"))
		{
			m->cursor = 1;
			pthread_create(&t[i], NULL, burningship, &thread[i]);
		}
		if (!ft_strcmp(m->fractal, "Phoenix") || !ft_strcmp(m->fractal, "phoenix"))
		{
			m->cursor = 1;
			pthread_create(&t[i], NULL, phoenix, &thread[i]);
		}
	}
	while (--i >= 0)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->image, 0, 0);
}
