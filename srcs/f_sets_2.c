/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sets_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:56:21 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/22 18:00:35 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		f_setset(t_set *s, t_fractal *m)
{
	s->zx = 1.5 * (s->x - (WIN / 2)) / (WIN * 0.2 * m->zoom) + m->x_move +
		m->offset_x;
	s->zy = (s->y - WIN / 2) / (WIN * 0.2 * m->zoom) + m->y_move +
		m->offset_y;
	s->i = 0;
}
