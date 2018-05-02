/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 18:26:03 by htkachuk          #+#    #+#             */
/*   Updated: 2018/04/30 18:26:05 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		all_black(t_all *ev)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SIZE_Y)
	{
		x = -1;
		while (++x < SIZE_X)
			*(unsigned int *)(ev->img[0].str + ((x
				+ y * SIZE_X) * 4)) = 0x000000;
	}
}

static void	ft_useful(t_all *ev, int n, int y, int x)
{
	ev->n = n;
	ev->wh = n;
	ev->img[n].size_x = (SIZE_XW - SIZE_X) / 2;
	ev->img[n].size_y = SIZE_Y / 2 / 2;
	define_ch(ev);
	ft_create_img(ev, n);
	create_thread(ev);
	mlx_put_image_to_window(ev->mlx, ev->win, ev->img[n].img, x, y);
}

void		print_all_fract(t_all *ev)
{
	int	n;

	n = ev->wh;
	ft_useful(ev, 1, 0, 800);
	ft_useful(ev, 2, 200, 800);
	ft_useful(ev, 3, 400, 800);
	ft_useful(ev, 4, 600, 800);
	ft_useful(ev, 5, 0, 1000);
	ft_useful(ev, 6, 200, 1000);
	ft_useful(ev, 7, 400, 1000);
	ft_useful(ev, 8, 600, 1000);
	ev->wh = n;
}
