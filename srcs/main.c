#include "fractol.h"
#include <stdio.h>

int		keyfunction(int key, t_fractol *m)
{
	(void)m;
	key == 53 ? exit(0) : 0;
	return (0);
}

void		init_mlx(t_fractol *m)
{
	m->mlx_ptr = mlx_init();
	m->win_ptr = mlx_new_window(m->mlx_ptr, WIN, WIN, "FRACT'OL by KSONU");
	m->image = mlx_new_image(m->mlx_ptr, WIN, WIN);
	m->data = mlx_get_data_addr(m->image, &m->bpp, &m->size, &m->endian);
	mlx_hook(m->win_ptr, 2, 0, keyfunction, m);
	mlx_loop(m->mlx_ptr);
}

void		error_message(void)
{
	ft_putendl("usage : ./fractol [fractal set]\n");
	ft_putendl("[fractal sets]	Mandelbrot");
	ft_putendl("		Julia");
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
}
