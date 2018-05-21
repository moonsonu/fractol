/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_hooks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:30:33 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/21 15:21:23 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

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
	key == 18 ? m->fractal = "mandelbrot" : 0;
	key == 19 ? m->fractal = "julia" : 0;
	key == 20 ? m->fractal = "burningship" : 0;
	key == 21 ? m->fractal = "phoenix" : 0;
	f_multithrd(m);
	return (0);
}

int		cursorfunction(int x, int y, t_fractol *m)
{
	ft_bzero(m->data, WIN * WIN * 4);
	if (m->cursor != 0)
	{
		m->cursor_x = x;
		m->cursor_y = y;
		f_multithrd(m);
	}
	return (0);
}

int		mousefunction(int button, int x, int y, t_fractol *m)
{
	(void)x;
	(void)y;
	ft_bzero(m->data, WIN * WIN * 4);
	button == 4 && m->zoom / 1.1 > 0 ? m->zoom /= 1.1 : 0;
	button == 5 ? m->zoom *= 1.1 : 0;
	f_multithrd(m);
	return (0);
}
