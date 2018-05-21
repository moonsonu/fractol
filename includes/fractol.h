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
	double			x_move;
	double			y_move;
	double			zoom;
	int				iter;
	int				start;
	int				end;
	int				cursor;
	int				cursor_x;
	int				cursor_y;
}					t_fractol;

/* main */
void		error_message(void);

/* f_setting */
void		f_color(t_fractol *m, int x, int y, int n);
void		init_mlx(t_fractol *m);
void		init_env(t_fractol *m);

/* f_hooks */
int			keyfunction(int key, t_fractol *m);
int			cursorfunction(int x, int y, t_fractol *m);
//int			mousefunction(int key, int x, int y, t_fractol *m);

/* f_sets*/
void		*julia(void *thread);
void		*mandelbrot(void *thread);
void		f_multithrd(t_fractol *m);

#endif
