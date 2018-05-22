/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:32:26 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/21 21:52:06 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

/*void	*barnsley(void *thread)
{
	t_fractol *m = (t_fractol *)thread;
	double	x0 = 0;
	double	y0 = 0;
	double	x1;
	double	y1;
	int		d;
	int		i;
	int		x;
	int		y;

	while (m->iteri-- > 0)
	{
		d = ((float)rand()) / WIN;
		if (d == 0)
		{
			x1 = 0;
			y1 = 0.16 * y0;
		}
		else if (d >= 1 && d <= 7)
		{
			x1 = -0.15 * x0 + 0.28 * y0;
			y1 = 0.23 * x0 + 0.22 * y0 + 1.6;
		}
		else
		{
			x1 = 0.85 * x0 + 0.04 * y0;
			y1 = -0.04 * x0 + 0.85 * y0 + 1.6;
		}
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->image, 0, 0);
	}
	return (NULL);
}*/

void	*phoenix(void *thread)
{
	t_fractol	*m = (t_fractol *)thread;
	double		zx;
	double		zy;
	double		xtemp;
	int			x;
	int			y;
	int			i;
	double		x0;
	double		y0;

	y = -1;
	while (++y < WIN)
	{
		x = -1;
		while (++x < WIN)
		{
			zx = 1.5 * (x - (WIN / 2)) / (WIN * 0.2 * m->zoom) + m->x_move;
			zy = (y - WIN / 2) / (WIN * 0.2 * m->zoom) + m->y_move;
			x0 = 0;
			y0 = 0;
			i = 0;
			while ((zx * zx) + (zy * zy) < 4 && i < m->iter)
			{
				xtemp = zx * zx - zy * zy - m->p * x0;
				zy = 2 * fabs(zx * zy) - m->p * y0;
				zx = xtemp + 0.56667;
				x0 = zx;
				y0 = zy;
				i++;
			}
			if (i < m->iter && i > 0)
				f_color(m, x, y, 1000 * i);
		}
	}
	return (NULL);
}

void	*burningship(void *thread)
{
	t_fractol	*m = (t_fractol *)thread;
	double		zx;
	double		zy;
	double		xtemp;
	int			x;
	int			y;
	int			i;
	double		x0;
	double		y0;

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
