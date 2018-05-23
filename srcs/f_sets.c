/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:32:26 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/22 18:01:59 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*new(void *thread)
{
	t_fractol	*m = (t_fractol *)thread;
	t_set		s;

	s->y = -1;
	while (++(s->y) < WIN)
	{
		s->x = -1;
		while (++(s->x) < WIN)
		{
			f_setset(s, m);
			s->tmp = 1.0;
			while (s->i < m->iter && s->tmp > 0.000001)
			{
				s->x0 = s->zx;
				s->y0 = s->zy;
				s->tmp = (s->zx * s->zx + s->zy * s->zy) * (s->zx * s->zx +
						s->zy * s->zy);
				s->zx = (2 * s->zx * s->tmp + s->zx * s->zx - s->zy * s->zy) /
					(3.0 * s->tmp);
				s->zy = (2 * s->zy * (s->tmp - s->x0)) / (3.0 * s->tmp);
				s->tmp = (s->zx - s->x0) * (s->zx - s->x0) + (s->zy - s->y0) *
					(s->zy - s->y0);
				(s->i)++;
			}
			if (s->i < m->iter && s->i > 0)
				f_color(m, s->x, s->y, 1000 * s->i);
		}
	}
	return (NULL);
}

void	*pho(void *thread)
{
	t_fractol	*m = (t_fractol *)thread;
	t_set		s;

	y = -1;
	while (++y < WIN)
	{
		x = -1;
		while (++x < WIN)
		{
			f_setset(s, m);
			x0 = 0;
			y0 = 0;
			while ((zx * zx) + (zy * zy) < 4 && i < m->iter)
			{
				tmp = zx * zx - zy * zy - 0.5 * x0;
				zy = 2 * fabs(zx * zy) - 0.5 * y0;
				zx = tmp + 0.56667;
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

void	*bur(void *thread)
{
	t_fractol	*m = (t_fractol *)thread;
	t_set		s;

	y = -1;
	while (++y < WIN)
	{
		x = -1;
		while (++x < WIN)
		{
			f_setset(s, m);
			x0 = zx;
			y0 = zy;
			i = 0;
			while ((zx * zx) + (zy * zy) < 4 && i < m->iter)
			{
				tmp = zx * zx - zy * zy;
				zy = fabs(2 * zx * zy) + y0 * ((double)m->cursor_y / WIN * 2);
				zx = fabs(tmp + x0) * ((double)m->cursor_x / WIN * 2);
				i++;
			}
			if (i < m->iter && i > 0)
				f_color(m, x, y, 1000 * i);
		}
	}
	return (NULL);
}

void	*jul(void *thread)
{
	t_fractol	*m = (t_fractol *)thread;
	t_set		s;

	y = -1;
	while (++y < WIN)
	{
		x = -1;
		while (++x < WIN)
		{
			f_setset(s, m);
			while ((zx * zx) + (zy * zy) < 4 && i < m->iter)
			{
				tmp = zx * zx - zy * zy;
				zy = 2 * zx * zy + 0.745 * ((double)m->cursor_y / WIN * 2);
				zx = tmp + 0.113 * ((double)m->cursor_x / WIN * 2);
				i++;
			}
			if (i < m->iter && i > 0)
				f_color(m, x, y, 1000 * i);
		}
	}
	return (NULL);
}

void	*man(void *thread)
{
	t_fractol	*m = (t_fractol *)thread;
	t_set		s;

	y = -1;
	while (++y < WIN)
	{
		x = -1;
		while (++x < WIN)
		{
			f_setset(s, m);
			x0 = zx;
			y0 = zy;
			while ((zx * zx) + (zy * zy) < 4 && i < m->iter)
			{
				tmp = zx * zx - zy * zy;
				zy = 2 * zx * zy + y0;
				zx = tmp + x0;
				i++;
			}
			if (i < m->iter && i > 0)
				f_color(m, x, y, 1000 * i);
		}
	}
	return (NULL);
}
