/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 15:43:57 by htkachuk          #+#    #+#             */
/*   Updated: 2018/04/02 15:43:59 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define SIZE_Y 800
# define SIZE_X 800
# define SIZE_XW 1200

# include "mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct		s_imges
{
	int				size_x;
	int				size_y;
	char			*str;
	void			*img;
	int				bits;
	int				size;
	int				end;
}					t_imges;

typedef	struct		s_all
{
	void			*mlx;
	void			*win;
	t_imges			*img;
	double			ymin;
	double			xmin;
	double			ymax;
	double			xmax;
	double			dx;
	double			dy;
	int				wh;
	int				max_iter;
	double			x_center;
	double			y_center;
	double			c_re;
	double			c_im;
	int				x;
	int				y;
	int				metka;
	int				n;
	int				color;
	int				r;
}					t_all;

typedef struct		s_thr
{
	unsigned int	color;
	int				start;
	int				finish;
	double			c_re;
	double			c_im;
	t_all			*all;
}					t_thr;

void				draw_in(t_all *ev, int n);
int					ft_key(int keycode, t_all *ev);
int					ft_atoi_16(char *str);
void				ft_create(t_all *ev, int n);
void				ft_create_img(t_all *ev, int n);
int					iteration_j(double x, double y, t_thr ev);
int					iteration_m(double x, double y, t_thr ev);
int					mouse_zoom(int	keycode, int x, int y, t_all *ev);
void				define_ch(t_all *ev);
void				create_thread(t_all *ev);
int					mouse_scrol(int x, int y, t_all *ev);
void				print_all_fract(t_all *ev);
int					iteration_c(double x, double y, t_thr ev);
int					iteration_h(double x, double y, t_thr ev);
int					iteration_b_sh(double x, double y, t_thr ev);
int					iteration_c_h(double x, double y, t_thr ev);
int					iteration_buf(double x, double y, t_thr ev);
int					iteration_pen_m(double x, double y, t_thr ev);
void				all_black(t_all *ev);

#endif
