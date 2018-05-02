/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 19:18:38 by htkachuk          #+#    #+#             */
/*   Updated: 2018/04/14 19:18:45 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				define_ch(t_all *ev)
{
	ev->c_re = -0.8;
	ev->c_im = 0.156;
	ev->xmin = -2;
	ev->xmax = 2;
	ev->ymax = 2;
	ev->ymin = -2;
	ev->metka = 1;
	ev->dy = (ev->ymax - ev->ymin) / 2;
	ev->dx = (ev->xmax - ev->xmin) / 2;
	ev->max_iter = 100;
	ev->x_center = ev->xmax - ev->dx;
	ev->y_center = ev->ymax - ev->dy;
	ev->color = 1;
	ev->r = 1;
}

static unsigned int	wh_color(int t, t_all ev)
{
	if (ev.color == 1)
		return ((pow(t, 2) * 16) * (pow(t, 2) * 16));
	if (ev.color == 2)
		return (t * 16 * pow(255, 5));
	if (ev.color == 3)
		return (pow(t, 6) / 32);
	if (ev.color == 4)
		return ((t * 16 * pow(255, 3)) / 100);
	if (ev.color == 5)
		return (pow(t, 8) / 64);
	return (0);
}

static int			which_fractal(t_thr *ev, int x)
{
	int	t;

	t = 0;
	if (ev->all->wh == 1)
		t = iteration_m(x, ev->start, *(ev));
	if (ev->all->wh == 2)
		t = iteration_j(x, ev->start, *(ev));
	if (ev->all->wh == 3)
		t = iteration_c(x, ev->start, *(ev));
	if (ev->all->wh == 4)
		t = iteration_h(x, ev->start, *(ev));
	if (ev->all->wh == 5)
		t = iteration_b_sh(x, ev->start, *(ev));
	if (ev->all->wh == 6)
		t = iteration_c_h(x, ev->start, *(ev));
	if (ev->all->wh == 7)
		t = iteration_buf(x, ev->start, *(ev));
	if (ev->all->wh == 8)
		t = iteration_pen_m(x, ev->start, *(ev));
	return (t);
}

static void			*draw_fract(void *thr)
{
	int				x;
	int				t;
	t_thr			*ev;
	unsigned int	color;

	ev = (t_thr *)thr;
	x = -1;
	while (++x < ev->all->img[ev->all->n].size_x)
	{
		t = which_fractal(ev, x);
		color = wh_color(t, *(ev->all));
		if (t == ev->all->max_iter)
			color = 0;
		*(unsigned int *)(ev->all->img[ev->all->n].str + ((x
			+ ev->start * ev->all->img[ev->all->n].size_x) * 4)) = color;
	}
	pthread_exit(0);
}

void				create_thread(t_all *ev)
{
	pthread_t	tid[ev->img[ev->n].size_y];
	t_thr		thr[ev->img[ev->n].size_y];
	int			i;

	i = 0;
	while (i < ev->img[ev->n].size_y)
	{
		thr[i].start = i;
		thr[i].c_re = ev->c_re;
		thr[i].c_im = ev->c_im;
		thr[i].all = ev;
		pthread_create(&tid[i], NULL, draw_fract, (void *)&(thr[i]));
		i++;
	}
	i = -1;
	while (++i < ev->img[ev->n].size_y)
		pthread_join(tid[i], NULL);
}
