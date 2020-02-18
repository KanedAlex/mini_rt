/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:00:43 by alienard          #+#    #+#             */
/*   Updated: 2020/02/18 21:57:55 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	ft_ray(double j, double i, t_window *win, t_cam *cam)
{
	t_argb	color;
	double	size;

	size = tan(cam->fov * M_PI / 180 / 2);
	cam->pij = cam->coord;
	cam->rij.x = j - (win->x / 2);
	cam->rij.y = i - (win->y / 2);
	cam->rij.z = -(win->x / (2 * size));
	cam->rij = ft_normal_vect(cam->rij);
	color = ft_trace_ray(win, cam);
	ft_pix(j, i, win, color);
}

void	ft_init_ray_cam(t_cam *cam, t_ray *ray)
{
	ray->dir = cam->rij;
	ray->orig = cam->pij;
	ray->lenght = -1;
	ray->unit = cam->rij;
}

t_argb	ft_trace_ray(t_window *win, t_cam *cam)
{
	t_shape	*cur_shape;
	t_shape	*min_sh;
	double	min;
	t_ray	ray;
	t_argb	black;

	ft_argb_init(&black);
	cur_shape = win->beg_sh;
	min_sh = NULL;
	min = INFINITY;
	ft_init_ray_cam(cam, &ray);
	while (cur_shape)
	{
		ft_which_shape(cur_shape, &ray);
		if (ray.lenght > 0.0001 && ray.lenght < min)
		{
			min = ray.lenght;
			min_sh = cur_shape;
		}
		cur_shape = cur_shape->next;
	}
	if (min_sh == NULL)
		return (black);
	black = ft_albedo(ft_pre_light(win, min_sh, min, &ray), min_sh->color);
	return (black);
}

t_ray	ft_shoot_ray(t_pt orig, t_pt dir, double t)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = dir;
	ray.lenght = t;
	ray.unit = ft_addition(orig, ft_multi_scal(t, dir));
	ray.unit = ft_normal_vect(ray.unit);
	return (ray);
}
