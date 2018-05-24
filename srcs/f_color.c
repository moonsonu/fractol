/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:16:38 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/24 14:42:15 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			key_color(int key, t_fractol *m)
{
	key == 6 ? m->color = 0 : 0;
	key == 7 ? m->color = 1 : 0;
	key == 8 ? m->color = 2 : 0;
	if (key == 5)
	{
		m->r = 2;
		m->g = 255;
		m->b = 2;
	}
	if (key == 11)
	{
		m->r = 5;
		m->g = 2;
		m->b = 150;
	}
	return (0);
}

void		f_color(t_fractol *m, int x, int y, int n)
{
	int		i;
	int		c;

	i = (x * 4) + (y * m->size);
	m->color == 0 ? c = m->r : 0;
	m->color == 1 ? c = m->g : 0;
	m->color == 2 ? c = m->b : 0;
	//m->data[i] = ft_rgb(255, 133, 170);
	m->data[++i] = n * c * 255;
	m->data[++i] = ft_rgb(m->r, m->g, m->b);
	//m->data[++i] = ft_rgb(m->r + n, m->g + n, m->b + n);
}
