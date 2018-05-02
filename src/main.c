/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 15:39:36 by htkachuk          #+#    #+#             */
/*   Updated: 2018/04/02 15:39:39 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	exit_x(void)
{
	exit(0);
}

static int	choose(char **av, t_all *ev)
{
	ev->wh = 0;
	ev->wh = (!ft_strcmp(av[1], "mandelbrot")) ? 1 : 0;
	if (ev->wh == 0)
		ev->wh = (!(ft_strcmp(av[1], "julia"))) ? 2 : 0;
	if (ev->wh == 0)
		ev->wh = (!(ft_strcmp(av[1], "celtic"))) ? 3 : 0;
	if (ev->wh == 0)
		ev->wh = (!(ft_strcmp(av[1], "heart"))) ? 4 : 0;
	if (ev->wh == 0)
		ev->wh = (!(ft_strcmp(av[1], "burning_ship"))) ? 5 : 0;
	if (ev->wh == 0)
		ev->wh = (!(ft_strcmp(av[1], "celtic_heart"))) ? 6 : 0;
	if (ev->wh == 0)
		ev->wh = (!(ft_strcmp(av[1], "buffalo"))) ? 7 : 0;
	if (ev->wh == 0)
		ev->wh = (!(ft_strcmp(av[1], "perpendicular_man"))) ? 8 : 0;
	return (ev->wh);
}

void		draw_in(t_all *ev, int n)
{
	all_black(ev);
	mlx_put_image_to_window(ev->mlx, ev->win, ev->img[n].img, 0, 0);
	create_thread(ev);
	mlx_put_image_to_window(ev->mlx, ev->win, ev->img[n].img, 0, 0);
}

int			main(int c, char **av)
{
	t_all			ev;

	ev.n = 0;
	if (c != 2 || !(choose(av, &ev)))
	{
		ft_putstr_fd("usage: ./fractol mandelbrot\n\t./fractol julia\n\t", 2);
		ft_putstr_fd("./fractol celtic\n\t./fractol heart\n\t", 2);
		ft_putstr_fd("./fractol celtic_heart\n\t./fractol buffalo\n\t", 2);
		ft_putstr_fd("./fractol perpendicular_man\n\t", 2);
		ft_putstr_fd("./fractol burning_ship\n", 2);
		return (1);
	}
	ev.img = (t_imges*)malloc(sizeof(t_imges) * 9);
	ev.img[0].size_x = SIZE_X;
	ev.img[0].size_y = SIZE_Y;
	ft_create(&ev, 0);
	define_ch(&ev);
	draw_in(&ev, 0);
	print_all_fract(&ev);
	mlx_hook(ev.win, 4, 1L << 2, mouse_zoom, &ev);
	mlx_hook(ev.win, 2, 5, ft_key, &ev);
	mlx_hook(ev.win, 17, 1L << 17, exit_x, &ev);
	mlx_loop(ev.mlx);
	return (0);
}
