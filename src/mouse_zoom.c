/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:02:33 by htkachuk          #+#    #+#             */
/*   Updated: 2018/04/12 13:02:36 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_calculate(double x, double y, t_all *ev, double zoom)
{
	if (x <= 0 || x >= SIZE_X || y <= 0 || y >= SIZE_Y)
		return ;
	x = ev->xmin + (ev->dx / (((double)SIZE_X / 2) / x));
	y = ev->ymin + (ev->dy / (((double)SIZE_Y / 2) / y));
	if (zoom == 0.95 && ev->max_iter != 250)
		ev->max_iter++;
	if (zoom == 0.95 && ev->n != 50)
		ev->max_iter--;
	if ((ev->xmin <= -243.26 || ev->xmax >= 244) && zoom == 1.05)
		return ;
	ev->xmin = (ev->x_center - ev->dx) * zoom + x * (1 - zoom);
	ev->ymin = (ev->y_center - ev->dy) * zoom + y * (1 - zoom);
	ev->xmax = (ev->x_center + ev->dx) * zoom + x * (1 - zoom);
	ev->ymax = (ev->y_center + ev->dy) * zoom + y * (1 - zoom);
	ev->dx = (ev->xmax - ev->xmin) / 2;
	ev->dy = (ev->ymax - ev->ymin) / 2;
	ev->x_center = ev->xmax - ev->dx;
	ev->y_center = ev->ymax - ev->dy;
}

int			mouse_scrol(int x, int y, t_all *ev)
{
	double	sizex;
	double	sizey;

	sizex = (double)SIZE_X;
	sizey = (double)SIZE_Y;
	if (ev->wh == 2 && x >= 0 && x <= SIZE_X && y >= 0 &&
		y <= SIZE_Y && ev->r == 1)
	{
		ev->c_re = -1 + (1 / ((sizex / 2) / (double)x));
		ev->c_im = -1 + (1 / ((sizey / 2) / (double)y));
		mlx_destroy_image(ev->mlx, ev->img[0].img);
		ft_create_img(ev, 0);
		draw_in(ev, 0);
	}
	return (0);
}

static void	change_main(int keycode, int n, t_all *ev)
{
	if (keycode == 1)
	{
		mlx_destroy_image(ev->mlx, ev->img[0].img);
		ft_create_img(ev, 0);
		define_ch(ev);
		ev->wh = n;
		draw_in(ev, 0);
	}
	if (keycode == 2)
	{
		mlx_destroy_image(ev->mlx, ev->img[0].img);
		ft_create_img(ev, 0);
		ev->color = (ev->color < 5 ? (ev->color + 1) : 1);
		draw_in(ev, 0);
	}
}

static void	choose_fractal(int x, int y, int keycode, t_all *ev)
{
	if (x >= 800 && x <= 1000 && y >= 0 && y <= 200)
		change_main(keycode, 1, ev);
	if (x >= 800 && x <= 1000 && y >= 200 && y <= 400)
		change_main(keycode, 2, ev);
	if (x >= 800 && x <= 1000 && y >= 400 && y <= 600)
		change_main(keycode, 3, ev);
	if (x >= 800 && x <= 1000 && y >= 600 && y <= 800)
		change_main(keycode, 4, ev);
	if (x >= 1000 && x <= 1200 && y >= 0 && y <= 200)
		change_main(keycode, 5, ev);
	if (x >= 1000 && x <= 1200 && y >= 200 && y <= 400)
		change_main(keycode, 6, ev);
	if (x >= 1000 && x <= 1200 && y >= 400 && y <= 600)
		change_main(keycode, 7, ev);
	if (x >= 1000 && x <= 1200 && y >= 600 && y <= 800)
		change_main(keycode, 8, ev);
}

int			mouse_zoom(int keycode, int x, int y, t_all *ev)
{
	ev->n = 0;
	if (keycode == 1)
		mlx_hook(ev->win, 6, 0, mouse_scrol, ev);
	if (keycode == 4)
	{
		mlx_destroy_image(ev->mlx, ev->img[0].img);
		ft_create_img(ev, 0);
		ft_calculate((double)x, (double)y, ev, 0.95);
		draw_in(ev, 0);
	}
	if (keycode == 5)
	{
		mlx_destroy_image(ev->mlx, ev->img[0].img);
		ft_create_img(ev, 0);
		ft_calculate((double)x, (double)y, ev, 1.05);
		draw_in(ev, 0);
	}
	choose_fractal(x, y, keycode, ev);
	if (keycode == 2)
		change_main(keycode, ev->wh, ev);
	return (0);
}
