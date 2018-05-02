/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 18:50:04 by htkachuk          #+#    #+#             */
/*   Updated: 2018/04/07 18:50:12 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_create_img(t_all *ev, int n)
{
	ev->img[n].bits = sizeof(int) * 8;
	ev->img[n].size = sizeof(int) * ev->img[n].size_x;
	ev->img[n].end = 0;
	ev->img[n].img = mlx_new_image(ev->mlx, ev->img[n].size_x,
		ev->img[n].size_y);
	ev->img[n].str = mlx_get_data_addr(ev->img[n].img, &(ev->img[n].bits),
		&(ev->img[n].size), &(ev->img[n].end));
}

void	ft_create(t_all *ev, int n)
{
	ev->mlx = mlx_init();
	ev->win = mlx_new_window(ev->mlx, SIZE_XW, SIZE_Y, "Fractol");
	ft_create_img(ev, n);
}
