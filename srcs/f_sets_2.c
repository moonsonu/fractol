/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sets_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:56:21 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/25 17:32:57 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		f_setset(t_set *s, t_fractol *m)
{
	if (m->fractal == 1 || m->fractal == 3)
	{
		s->zx = (s->x - (WIN / 2)) / (WIN * 0.2 * m->zoom) + m->x_move +
			m->offset_x;
		s->zy = (s->y - WIN / 2) / (WIN * 0.2 * m->zoom) + m->y_move +
			m->offset_y;
		s->i = 0;
	}
	else
	{
		s->zx = 1.5 * (s->x - (WIN / 2)) / (WIN * 0.2 * m->zoom) + m->x_move +
			m->offset_x;
		s->zy = (s->y - WIN / 2) / (WIN * 0.2 * m->zoom) + m->y_move +
			m->offset_y;
		s->i = 0;
	}
}

void		f_new_iter(t_set *s, t_fractol *m)
{
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
}

void		f_pho_iter(t_set *s, t_fractol *m)
{
	while ((s->zx * s->zx) + (s->zy * s->zy) < 4 && s->i < m->iter)
	{
		s->tmp = s->zx * s->zx - s->zy * s->zy - 0.5 * s->x0;
		s->zy = 2 * fabs(s->zx * s->zy) - 0.5 * s->y0;
		s->zx = s->tmp + 0.56667;
		s->x0 = s->zx;
		s->y0 = s->zy;
		(s->i)++;
	}
}

void		f_bur_iter(t_set *s, t_fractol *m)
{
	while ((s->zx * s->zx) + (s->zy * s->zy) < 4 && s->i < m->iter)
	{
		s->tmp = s->zx * s->zx - s->zy * s->zy;
		s->zy = fabs(2 * s->zx * s->zy) + s->y0 *
			((double)m->cursor_y / WIN * 2);
		s->zx = fabs(s->tmp + s->x0) * ((double)m->cursor_x / WIN * 2);
		(s->i)++;
	}
}

void		f_man_iter(t_set *s, t_fractol *m)
{
	while ((s->zx * s->zx) + (s->zy * s->zy) < 4 && s->i < m->iter)
	{
		s->tmp = s->zx * s->zx - s->zy * s->zy;
		s->zy = 2 * s->zx * s->zy + s->y0;
		s->zx = s->tmp + s->x0;
		(s->i)++;
	}
}
