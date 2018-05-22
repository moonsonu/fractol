/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_setting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:34:24 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/22 10:31:55 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	f_multithrd(t_fractol *m)
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
		if (!ft_strcmp(m->fractal, "mandelbrot"))
			pthread_create(&t[i], NULL, mandelbrot, &thread[i]);
		if (!ft_strcmp(m->fractal, "julia"))
		{
			m->cursor = 1;
			pthread_create(&t[i], NULL, julia, &thread[i]);
		}
		if (!ft_strcmp(m->fractal, "burningship"))
		{
			m->cursor = 1;
			pthread_create(&t[i], NULL, burningship, &thread[i]);
		}
		if (!ft_strcmp(m->fractal, "phoenix"))
		{
			m->cursor = 1;
			pthread_create(&t[i], NULL, phoenix, &thread[i]);
		}
		/*if (!ft_strcmp(m->fractal, "Barnsley") || !ft_strcmp(m->fractal, "barnsley"))
		  pthread_create(&t[i], NULL, barnsley, &thread[i]);*/
	}
	while (--i >= 0)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->image, 0, 0);
}

void		f_color(t_fractol *m, int x, int y, int n)
{
	int		i;

	i = (x * 4) + (y * m->size);
	//m->data[i] = ft_rgb(255, 133, 170);
	m->data[++i] = n * m->r;
	m->data[++i] = ft_rgb(m->r, m->g, m->b);
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
	m->p = 0.5;
}

int			init_fractal(t_fractol *m, char *av)
{
	if (!ft_strcmp(av, "Mandelbrot") || !ft_strcmp(av, "mandelbrot"))
		m->fractal = "mandelbrot";
	else if (!ft_strcmp(av, "Julia") || ft_strcmp(av, "julia"))
		m->fractal = "julia";
	else if (!ft_strcmp(av, "Burningship") || !ft_strcmp(av, "burningship"))
		m->fractal = "burningship";
	else if (!ft_strcmp(av, "Phoenix") || !ft_strcmp(av, "phoenix"))
		m->fractal = "phoenix";
	else
		return (0);
	return (1);
}
