/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:05:02 by htkachuk          #+#    #+#             */
/*   Updated: 2018/04/04 19:05:04 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_key(int keycode, t_all *ev)
{
	if (keycode == 53)
	{
		system("leaks fractol");
		exit(0);
	}
	if (keycode == 49 && ev->r == 1)
	{
		ev->r = 0;
		return (0);
	}
	if (keycode == 49 && ev->r == 0)
	{
		ev->r = 1;
		return (0);
	}
	if (keycode == 0)
	{
		mlx_destroy_image(ev->mlx, ev->img[0].img);
		ft_create_img(ev, 0);
		if (ev->max_iter != 2147483647)
			ev->max_iter++;
		draw_in(ev, 0);
	}
	return (0);
}
