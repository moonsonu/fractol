/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_setting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:34:24 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/22 18:02:35 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		f_multithrd(t_fractol *m)
{
	int			i;
	pthread_t	t[4];
	t_fractol	thread[4];

	i = -1;
	while (++i < 4 && (ft_memcpy((void*)&thread[i], m, sizeof(t_fractol))))
	{
		thread[i].start = i * (WIN / 4);
		thread[i].end = (i + 1) * (WIN / 4);
	}
	i = -1;
	while (++i < 4)
	{
		m->fractal == 1 ? pthread_create(&t[i], NULL, man, &thread[i]) : 0;
		m->fractal == 2 ? pthread_create(&t[i], NULL, jul, &thread[i]) : 0;
		m->fractal == 3 ? pthread_create(&t[i], NULL, bur, &thread[i]) : 0;
		m->fractal == 4 ? pthread_create(&t[i], NULL, pho, &thread[i]) : 0;
		m->fractal == 5 ? pthread_create(&t[i], NULL, new, &thread[i]) : 0;
	}
	while (--i >= 0)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->image, 0, 0);
	f_mlx_message(m);
}

void		f_mlx_message(t_fractol *m)
{
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 5, 0xFFFFFF, "RESET : [R]");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 25, 0xFFFFFF, "ZOOM : [+]/[-]");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 45, 0xFFFFFF, "MOVE : [ARROWS]");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 65, 0xFFFFFF,
			"ITERATION : [I]/[O]");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 85, 0xFFFFFF, "FRACTAL SETS");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 105, 0xFFFFFF,
			"[1] :Mandelbrot");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 125, 0xFFFFFF, "[2] : Julia");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 145, 0xFFFFFF,
			"[3] : Burningship");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 165, 0xFFFFFF, "[4] : Phoenix");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 185, 0xFFFFFF, "[5] : Newton");
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
	m->cursor = 0;
	m->r = 255;
	m->g = 255;
	m->b = 255;
	m->offset_x = 0;
	m->offset_y = 0;
}

int			init_fractal(t_fractol *m, char *av)
{
	if (!ft_strcmp(av, "Mandelbrot") || !ft_strcmp(av, "mandelbrot"))
		m->fractal = 1;
	else if (!ft_strcmp(av, "Julia") || !ft_strcmp(av, "julia"))
	{
		m->fractal = 2;
		m->cursor = 1;
	}
	else if (!ft_strcmp(av, "Burningship") || !ft_strcmp(av, "burningship"))
	{
		m->fractal = 3;
		m->cursor = 1;
	}
	else if (!ft_strcmp(av, "Phoenix") || !ft_strcmp(av, "phoenix"))
		m->fractal = 4;
	else if (!ft_strcmp(av, "Newton") || !ft_strcmp(av, "newton"))
		m->fractal = 5;
	else
		return (0);
	return (1);
}
