#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libs/libft/includes/libft.h"
# include "../libs/mlx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <pthread.h>
# define WIN 500

typedef struct		s_fractol
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*data;
	void			*image;
	char			*fractal;
	int				bpp;
	int				size;
	int				endian;
	double			newr;
	double			newi;
	double			oldr;
	double			oldi;
	int				width;
	int				height;
}					t_fractol;
#endif
