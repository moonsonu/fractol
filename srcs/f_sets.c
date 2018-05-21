/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:32:26 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/20 18:40:46 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
				zy = fabs(2 * zx * zy) + y0;
				zx = fabs(xtemp + x0);
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
				zy = 2 * zx * zy + 0.662;
				zx = xtemp + 0.282;
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
			pthread_create(&t[i], NULL, julia, &thread[i]);
		if (!ft_strcmp(m->fractal, "Burningship") || !ft_strcmp(m->fractal, "burningship"))
			pthread_create(&t[i], NULL, burningship, &thread[i]);
	}
	while (--i >= 0)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->image, 0, 0);
}
