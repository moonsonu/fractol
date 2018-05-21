/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 19:05:43 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/21 15:21:29 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void		error_message(void)
{
	ft_putendl("usage : ./fractol [fractal set]\n");
	ft_putendl("[fractal sets]	Mandelbrot");
	ft_putendl("		Julia");
	ft_putendl("		Burningship");
	ft_putendl("		Phoenix");
	exit(0);
}

int			main(int ac, char **av)
{
	t_fractol	*m;

	m = (t_fractol*)malloc(sizeof(t_fractol));
	if (ac != 2)
		error_message();
	m->fractal = av[1];
	init_mlx(m);
	init_env(m);
	f_multithrd(m);
	mlx_hook(m->win_ptr, 2, 0, keyfunction, m);
	mlx_hook(m->win_ptr, 6, 0, cursorfunction, m);
	mlx_mouse_hook(m->win_ptr, mousefunction, m);
	mlx_loop(m->mlx_ptr);
}
