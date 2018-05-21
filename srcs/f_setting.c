/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_setting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:34:24 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/21 10:22:57 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		f_color(t_fractol *m, int x, int y, int n)
{
	int		i;

	i = (x * 4) + (y * m->size);
	m->data[i] = ft_rgb(255, 133, 170);
	m->data[++i] = n % 255;
	m->data[++i] = ft_rgb(255, 255, 255);
}

void		init_mlx(t_fractol *m)
{
	m->mlx_ptr = mlx_init();
	m->win_ptr = mlx_new_window(m->mlx_ptr, WIN, WIN, "FRACT'OL by KSONU");
	m->image = mlx_new_image(m->mlx_ptr, WIN, WIN);
	m->data = mlx_get_data_addr(m->image, &m->bpp, &m->size, &m->endian);
}

void		init_env(t_fractol *m)
{
	m->x_move = 0;
	m->y_move = 0;
	m->iter = 50;
	m->zoom = 1;
	m->cursor = 1;
}
