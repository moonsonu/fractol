/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 19:05:43 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/28 14:10:57 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		help_message(void)
{
	ft_putendl("\n'*.'*.'*.'*.KEYBOARD.*'.*'.*'.*'");
	ft_putendl("\nRESET : [R]");
	ft_putendl("ZOOM : [+]/[-]");
	ft_putendl("MOVE : [ARROWS]");
	ft_putendl("ITERATION : [I]/[O]");
	ft_putendl("CHANGE SETS :");
	ft_putendl("	[1] - Mandelbrot");
	ft_putendl("	[2] - Julia");
	ft_putendl("	[3] - Burningship");
	ft_putendl("	[4] - Phoenix");
	ft_putendl("	[5] - Newton");
	ft_putendl("CHANGE COLORS : [R]/[G]/[B]");
	ft_putendl("		[Z]/[X]/[C]");
	ft_putendl("HIDE HELP : [SPACE BAR]");
	ft_putendl("\n.'*.'*.'*.'*.'MOUSE'.*'.*'.*'.*'");
	ft_putendl("\n[LEFT CLICK] : bring the position to");
	ft_putendl("	       the center");
	ft_putendl("[WHEEL UP/DOWN] : zoom in/out follows");
	ft_putendl("		  the cursor position\n");
}

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
				"[1] : Mandelbrot");
		mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 125, 0xFFFFFF, "[2] : Julia");
		mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 145, 0xFFFFFF,
				"[3] : Burningship");
		mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 165, 0xFFFFFF,
				"[4] : Phoenix");
		mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 185, 0xFFFFFF,
				"[5] : Newton");
		mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 205, 0xFFFFFF,
				"COLOR : [R]/[G]/[B]");
		mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 230, 0xFFFFFF,
				"        [Z]/[X]/[C]");
	}
}

void		error_message(void)
{
	ft_putendl("usage : ./fractol [fractal set] [fractal set]\n");
	ft_putendl("[fractal sets]	Mandelbrot");
	ft_putendl("		Julia");
	ft_putendl("		Burningship");
	ft_putendl("		Phoenix");
	ft_putendl("		Newton");
	exit(0);
}

void		win_set(t_fractol *m)
{
	init_mlx(m);
	init_env(m);
	f_multithrd(m);
	mlx_hook(m->win_ptr, 2, 0, keyfunction, m);
	mlx_hook(m->win_ptr, 6, 0, cursorfunction, m);
	mlx_mouse_hook(m->win_ptr, mousefunction, m);
	mlx_loop(m->mlx_ptr);
}

int			main(int ac, char **av)
{
	t_fractol	*m;

	m = (t_fractol*)malloc(sizeof(t_fractol));
	if ((ac != 2 && ac != 3) || !init_fractal(m, av[1]))
		error_message();
	help_message();
	if (ac == 3)
	{
		if (!fork())
			win_set(m);
		else
		{
			av[1] = av[2];
			if (init_fractal(m, av[1]) == 1)
				win_set(m);
			else
				error_message();
		}
	}
	win_set(m);
	return (0);
}
