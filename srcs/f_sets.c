/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:32:26 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/23 21:48:31 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define SETS t_fractol *m = (t_fractol *)thread;

void	*newt(void *thread)
{
	t_set		*s;

	SETS;
	s = ft_memalloc(sizeof(t_set));
	s->y = m->start - 1;
	while (++(s->y) < m->end)
	{
		s->x = -1;
		while (++(s->x) < WIN)
		{
			f_setset(s, m);
			s->tmp = 1.0;
			f_new_iter(s, m);
			if (s->i < m->iter && s->i > 0)
				f_color(m, s->x, s->y, 1000 * s->i);
		}
	}
	return (NULL);
}

void	*pho(void *thread)
{
	t_set		*s;

	SETS;
	s = ft_memalloc(sizeof(t_set));
	s->y = m->start - 1;
	while (++(s->y) < m->end)
	{
		s->x = -1;
		while (++(s->x) < WIN)
		{
			f_setset(s, m);
			s->x0 = 0;
			s->y0 = 0;
			f_pho_iter(s, m);
			if (s->i < m->iter && s->i > 0)
				f_color(m, s->x, s->y, 1000 * s->i);
		}
	}
	return (NULL);
}

void	*bur(void *thread)
{
	t_set		*s;

	SETS;
	s = ft_memalloc(sizeof(t_set));
	s->y = m->start - 1;
	while (++(s->y) < m->end)
	{
		s->x = -1;
		while (++(s->x) < WIN)
		{
			f_setset(s, m);
			s->x0 = s->zx;
			s->y0 = s->zy;
			s->i = 0;
			f_bur_iter(s, m);
			if (s->i < m->iter && s->i > 0)
				f_color(m, s->x, s->y, 1000 * s->i);
		}
	}
	return (NULL);
}

void	*jul(void *thread)
{
	t_set		*s;

	SETS;
	s = ft_memalloc(sizeof(t_set));
	s->y = m->start - 1;
	while (++(s->y) < m->end)
	{
		s->x = -1;
		while (++(s->x) < WIN)
		{
			f_setset(s, m);
			while ((s->zx * s->zx) + (s->zy * s->zy) < 4 && s->i < m->iter)
			{
				s->tmp = s->zx * s->zx - s->zy * s->zy;
				s->zy = 2 * s->zx * s->zy + 0.745 *
					((double)m->cursor_y / WIN * 2);
				s->zx = s->tmp + 0.113 * ((double)m->cursor_x / WIN * 2);
				(s->i)++;
			}
			if (s->i < m->iter && s->i > 0)
				f_color(m, s->x, s->y, 1000 * s->i);
		}
	}
	return (NULL);
}

void	*man(void *thread)
{
	t_set		*s;

	SETS;
	s = ft_memalloc(sizeof(t_set));
	s->y = m->start - 1;
	while (++(s->y) < m->end)
	{
		s->x = -1;
		while (++(s->x) < WIN)
		{
			f_setset(s, m);
			s->x0 = s->zx;
			s->y0 = s->zy;
			while ((s->zx * s->zx) + (s->zy * s->zy) < 4 && s->i < m->iter)
			{
				s->tmp = s->zx * s->zx - s->zy * s->zy;
				s->zy = 2 * s->zx * s->zy + s->y0;
				s->zx = s->tmp + s->x0;
				(s->i)++;
			}
			if (s->i < m->iter && s->i > 0)
				f_color(m, s->x, s->y, 1000 * s->i);
		}
	}
	return (NULL);
}
