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
	char			*data;
	void			*image;
	char			*fractal;
	int				bpp;
	int				size;
	int				endian;
	int				x_move;
	int				y_move;
	int				zoom;
	int				iter;
	int				start;
	int				end;
}					t_fractol;
#endif
