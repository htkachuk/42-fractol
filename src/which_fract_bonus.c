/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_fract_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:28:29 by htkachuk          #+#    #+#             */
/*   Updated: 2018/05/01 16:28:31 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iteration_h(double x, double y, t_thr ev)
{
	int		i;
	double	twoab;
	double	im;
	double	re;

	ev.c_re = ev.all->xmin + (ev.all->dx /
		(((double)ev.all->img[ev.all->n].size_x / 2) / x)) + ev.all->x_center;
	ev.c_im = ev.all->ymin + (ev.all->dy /
		(((double)ev.all->img[ev.all->n].size_y / 2) / y)) + ev.all->y_center;
	i = 0;
	re = ev.c_re;
	im = ev.c_im;
	while (i < ev.all->max_iter && (pow(re, 2) + pow(im, 2)) < 4)
	{
		twoab = 2 * fabs(re) * im;
		re = pow(re, 2) - pow(im, 2) + ev.c_re;
		im = twoab + ev.c_im;
		i++;
	}
	return (i);
}

int	iteration_b_sh(double x, double y, t_thr ev)
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
		twoab = -2 * fabs(re * im);
		re = pow(re, 2) - pow(im, 2) + ev.c_re;
		im = twoab + ev.c_im;
		i++;
	}
	return (i);
}

int	iteration_c_h(double x, double y, t_thr ev)
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
		twoab = 2 * fabs(re) * im;
		re = fabs(pow(re, 2) - pow(im, 2)) + ev.c_re;
		im = twoab + ev.c_im;
		i++;
	}
	return (i);
}

int	iteration_buf(double x, double y, t_thr ev)
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
		twoab = -2 * fabs(re * im);
		re = fabs(pow(re, 2) - pow(im, 2)) + ev.c_re;
		im = twoab + ev.c_im;
		i++;
	}
	return (i);
}

int	iteration_pen_m(double x, double y, t_thr ev)
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
		twoab = -2 * fabs(re) * im;
		re = pow(re, 2) - pow(im, 2) + ev.c_re;
		im = twoab + ev.c_im;
		i++;
	}
	return (i);
}
