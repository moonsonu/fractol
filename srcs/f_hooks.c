/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_hooks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:30:33 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/23 17:51:27 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_set(int key, t_fractol *m)
{
	key == 18 ? m->fractal = 1 : 0;
	key == 19 ? m->fractal = 2 : 0;
	key == 20 ? m->fractal = 3 : 0;
	key == 21 ? m->fractal = 4 : 0;
	key == 23 ? m->fractal = 5 : 0;
	init_env(m);
	return (0);
}

int		key_message(int key, t_fractol *m)
{
	if (key == 49)
	{
		if (m->message == 1)
			m->message = 0;
		else
			m->message = 1;
	}
	return (0);
}

int		keyfunction(int key, t_fractol *m)
{
	ft_bzero(m->data, WIN * WIN * 4);
	if (key == 53)
	{
		mlx_destroy_image(m->mlx_ptr, m->image);
		mlx_destroy_window(m->mlx_ptr, m->win_ptr);
		exit(0);
	}
	key == 27 && m->zoom / 1.1 > 0 ? m->zoom /= 1.1 : 0;
	key == 24 ? m->zoom *= 1.1 : 0;
	key == 34 ? m->iter += 1 : 0;
	key == 31 && m->iter > 1 ? m->iter -= 1 : 0;
	key == 15 ? init_env(m) : 0;
	key == 123 ? m->x_move += 0.3 : 0;
	key == 124 ? m->x_move -= 0.3 : 0;
	key == 125 ? m->y_move -= 0.3 : 0;
	key == 126 ? m->y_move += 0.3 : 0;
	if ((key >= 18 && key <= 21) || key == 23)
		key_set(key, m);
	if (key == 49)
		key_message(key, m);
	f_multithrd(m);
	return (0);
}

int		cursorfunction(int x, int y, t_fractol *m)
{
	ft_bzero(m->data, WIN * WIN * 4);
	if (m->cursor != 0)
	{
		if (x <= WIN && y <= WIN && x >= 0 && y >= 0)
		{
			m->cursor_x = x;
			m->cursor_y = y;
		}
		f_multithrd(m);
	}
	return (0);
}

int		mousefunction(int button, int x, int y, t_fractol *m)
{
	ft_bzero(m->data, WIN * WIN * 4);
	if (button == 4 || button == 5)
	{
		if (button == 4)
		{
			m->offset_x += (((2 * x - WIN) / (WIN / 4)) / m->zoom) / 5.5;
			m->offset_y += (((2 * y - WIN) / (WIN / 4)) / m->zoom) / 5.5;
			m->zoom /= 0.9;
		}
		else if (button == 5)
		{
			m->offset_x -= (((2 * x - WIN) / (WIN / 4)) / m->zoom) / 5.5;
			m->offset_y -= (((2 * y - WIN) / (WIN / 4)) / m->zoom) / 5.5;
			m->zoom *= 0.9;
		}
	}
	if (button == 1)
	{
		m->offset_x += ((2 * x - WIN) / (WIN / 4)) / m->zoom;
		m->offset_y += ((2 * y - WIN) / (WIN / 4)) / m->zoom;
	}
	f_multithrd(m);
	return (0);
}
