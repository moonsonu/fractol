/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:16:38 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/25 19:11:42 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int			key_color(int key, t_fractol *m)
{
	ft_bzero(m->data, WIN * WIN * 4);
	key == 6 ? m->color = 0 : 0;
	key == 7 ? m->color = 1 : 0;
	key == 8 ? m->color = 2 : 0;
	if (key == 5)
	{
		m->r = 2;
		m->g = 94;
		m->b = 50;
	}
	if (key == 11)
	{
		m->r = 5;
		m->g = 27;
		m->b = 130;
	}
	return (0);
}

void		f_color(t_fractol *m, int x, int y, int n)
{
	int		i;
	int		c;

	i = x + (y * WIN);
	m->color == 0 ? c = m->r : 0;
	m->color == 1 ? c = m->g : 0;
	m->color == 2 ? c = m->b : 0;
	m->data[++i] = n * c * 25;
	m->data[++i] = ft_rgb(m->r, m->g, m->b);
}
