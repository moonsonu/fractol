/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 17:38:13 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/27 18:27:13 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int				*data;
	void			*image;
	int				fractal;
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
	int				r;
	int				g;
	int				b;
	double			offset_x;
	double			offset_y;
	int				message;
	int				color;
}					t_fractol;

typedef struct		s_set
{
	double			zx;
	double			zy;
	double			tmp;
	double			x0;
	double			y0;
	int				x;
	int				y;
	int				i;
}					t_set;

/*
** main
*/
void				help_message(void);
void				f_mlx_message(t_fractol *m);
void				error_message(void);
void				win_set(t_fractol *m);
int					main(int ac, char **av);

/*
**f_setting
*/
void				f_multithrd_set(t_fractol *thread, t_fractol *m);
void				f_multithrd(t_fractol *m);
void				init_mlx(t_fractol *m);
void				init_env(t_fractol *m);
int					init_fractal(t_fractol *m, char *av);

/*
**f_color
*/
void				f_color(t_fractol *m, int x, int y, int n);
int					key_color(int key, t_fractol *m);

/*
**f_hooks
*/
int					keyfunction(int key, t_fractol *m);
int					cursorfunction(int x, int y, t_fractol *m);
int					mousefunction(int key, int x, int y, t_fractol *m);

/*
**f_sets
*/
void				*newt(void *thread);
void				*pho(void *thread);
void				*bur(void *thread);
void				*jul(void *thread);
void				*man(void *thread);

/*
**f_setset
*/
void				f_setset(t_set *s, t_fractol *m);
void				f_new_iter(t_set *s, t_fractol *m);
void				f_pho_iter(t_set *s, t_fractol *m);
void				f_bur_iter(t_set *s, t_fractol *m);
void				f_man_iter(t_set *s, t_fractol *m);

#endif
