/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 19:05:43 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/25 17:39:47 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void		f_mlx_message(t_fractol *m)
{
	if (m->message == 0)
	{
		mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 5, 0xFFFFFF, "RESET : [R]");
		mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 25, 0xFFFFFF,
				"ZOOM : [+]/[-]");
		mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 45, 0xFFFFFF,
				"MOVE : [ARROWS]");
		mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 65, 0xFFFFFF,
				"ITERATION : [I]/[O]");
		mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 85, 0xFFFFFF, "FRACTAL SETS");
		mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 105, 0xFFFFFF,
				"[1] :Mandelbrot");
		mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 125, 0xFFFFFF, "[2] : Julia");
		mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 145, 0xFFFFFF,
				"[3] : Burningship");
		mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 165, 0xFFFFFF,
				"[4] : Phoenix");
		mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 185, 0xFFFFFF,
				"[5] : Newton");
	}
}

void		error_message(void)
{
	ft_putendl("usage : ./fractol [fractal set]\n");
	ft_putendl("[fractal sets]	Mandelbrot");
	ft_putendl("		Julia");
	ft_putendl("		Burningship");
	ft_putendl("		Phoenix");
	ft_putendl("		Newton");
	exit(0);
}

int			main(int ac, char **av)
{
	t_fractol	*m;

	m = (t_fractol*)malloc(sizeof(t_fractol));
	if ((ac != 2 && ac != 3) || !init_fractal(m, av[1]))
		error_message();
	if (ac == 3)
	{
		if (!fork())
			main(2, av);
		else
		{
			av[1] = av[2];
			main(2, av);
		}
	}
	init_mlx(m);
	init_env(m);
	f_multithrd(m);
	mlx_hook(m->win_ptr, 2, 0, keyfunction, m);
	mlx_hook(m->win_ptr, 6, 0, cursorfunction, m);
	mlx_mouse_hook(m->win_ptr, mousefunction, m);
	mlx_loop(m->mlx_ptr);
	return (0);
}
