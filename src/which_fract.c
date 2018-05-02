/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 19:19:34 by htkachuk          #+#    #+#             */
/*   Updated: 2018/04/14 19:19:36 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iteration_m(double x, double y, t_thr ev)
{
	int		i;
	double	twoab;
	double	im;
	double	re;

	ev.c_re = ev.all->xmin + (ev.all->dx /
		(((double)ev.all->img[ev.all->n].size_x / 2) / x));
	ev.c_im = ev.all->ymin + (ev.all->dy /
		(((double)ev.all->img[ev.all->n].size_y / 2) / y));
	i = 0;
	re = ev.c_re;
	im = ev.c_im;
	while (i < ev.all->max_iter && (pow(re, 2) + pow(im, 2)) < 4)
	{
		twoab = 2 * re * im;
		re = pow(re, 2) - pow(im, 2) + ev.c_re;
		im = twoab + ev.c_im;
		i++;
	}
	return (i);
}

int	iteration_j(double x, double y, t_thr ev)
{
	int		i;
	double	twoab;
	double	im;
	double	re;

	i = 0;
	re = ev.all->xmin + (ev.all->dx /
		(((double)ev.all->img[ev.all->n].size_y / 2) / x));
	im = ev.all->ymin + (ev.all->dy /
		(((double)ev.all->img[ev.all->n].size_y / 2) / y));
	while (i < ev.all->max_iter && (pow(re, 2) + pow(im, 2)) < 4)
	{
		twoab = 2 * re * im;
		re = pow(re, 2) - pow(im, 2) + ev.c_re;
		im = twoab + ev.c_im;
		i++;
	}
	return (i);
}

int	iteration_c(double x, double y, t_thr ev)
{
	int		i;
	double	twoab;
	double	im;
	double	re;

	ev.c_re = ev.all->xmin + (ev.all->dx /
		(((double)ev.all->img[ev.all->n].size_x / 2) / x));
	ev.c_im = ev.all->ymin + (ev.all->dy /
		(((double)ev.all->img[ev.all->n].size_y / 2) / y));
	i = 0;
	re = ev.c_re;
	im = ev.c_im;
	while (i < ev.all->max_iter && (pow(re, 2) + pow(im, 2)) < 4)
	{
		twoab = 2 * re * im;
		re = fabs(pow(re, 2) - pow(im, 2)) + ev.c_re;
		im = twoab + ev.c_im;
		i++;
	}
	return (i);
}
