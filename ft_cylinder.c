/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:58:00 by alienard          #+#    #+#             */
/*   Updated: 2020/02/18 22:29:39 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		ft_cylinder_init(t_shape **current, char *line)
{
	int check;

	(*current)->id = 'y';
	while ((ft_isspace(*line)) == 1 || (ft_isalpha(*line)) == 1)
		line++;
	check = (ft_isnum(line) == 1) ? ft_point_init(&(*current)->pt_0, &line)
		: ft_error(38);
	check = (ft_isnum(line) == 1) ? ft_point_init(&(*current)->ori, &line)
		: ft_error(38);
	if (ft_isdigit(*line) == 1)
		(*current)->diameter = ft_atof(line);
	else
		check = ft_error(38);
	ft_iterate_in_line(&line);
	(*current)->height = ((ft_isdigit(*line) == 1) ? ft_atof(line)
		: ft_error(38));
	ft_iterate_in_line(&line);
	check = (ft_isdigit(*line) == 1) ? ft_color_init(&(*current)->color, &line)
		: ft_error(38);
	if (check == 0)
		check = (*line == '\0') ? ft_cylinder_check(current) : ft_error(29);
	return (check);
}

int		ft_cylinder_check(t_shape **current)
{
	int check;

	if (!current || !(*current))
		return (ft_error(17));
	if ((*current)->height < 0.0 || (*current)->diameter < 0.0)
		return (ft_error(20));
	check = ft_pt_check((*current)->pt_0);
	check = ft_color_check((*current)->color);
	check = ft_ori_check((*current)->ori);
	return (check);
}

void	ft_cylinder_norm(t_shape *sh, t_ray *ray)
{
	t_pt	r;

	r = ft_addition(ray->orig, ft_multi_scal(ray->lenght, ray->dir));
	r = ft_subtraction(r, sh->pt_0);
	r = ft_normal_vect(r);
	sh->n = r;
}

void	ft_intersect_ray_cylinder(t_shape *sh, t_ray *ray)
{
	t_pt	pa;
	t_pt	pb;
	double	ra;
	t_pt	ca;
	t_pt	oc;

	double	ca_d_ca;
	double	ca_d_rd;
	double	ca_d_oc;

	double	a;
	double	b;
	double	c;

	double	delta;
	double	t1;
	double	t2;

	double	y;

	pa = sh->pt_0;
	pb = sh->pt_0;
	pb = ft_addition(pb, ft_multi_scal(sh->height, sh->ori));
	ra = sh->diameter / 2;
	ca = ft_subtraction(pb, pa);
	oc = ft_subtraction(ray->orig, pa);
	ca_d_ca = ft_dot_product(ca, ca);
	ca_d_rd = ft_dot_product(ca, ray->dir);
	ca_d_oc = ft_dot_product(ca, oc);

	a = ca_d_ca - ft_sqr(ca_d_rd);
	b = ca_d_ca * ft_dot_product(oc, ray->dir) - ca_d_oc * ca_d_rd;
	c = ca_d_ca * ft_dot_product(oc, oc) - ft_sqr(ca_d_oc) - ft_sqr(ra) * ca_d_ca;
	delta = b * b - a * c;
	if (delta < 0.0001)
	{
		ray->lenght = -1;
		return ;
	}
	delta = sqrt(delta);
	t1 = (-b - delta) / a;
	t2 = (-b + delta) / a;
	if (t2 > 0.0001 && t2 < t1)
		t1 = t2;
	y = ca_d_oc + t1 * ca_d_rd;
	if (y > 0.0001 && y < ca_d_ca)
	{
		ray->lenght = t1;
		ft_cylinder_norm(sh, ray);
		return ;
	}
	y = (y < 0.0001) ? 0 : ca_d_ca;
	t1 = (y - ca_d_oc) / ca_d_rd;
	if ((fabs(b + a * t1)) < delta)
	{
		ray->lenght = t1;
		sh->n = sh->ori;
		return ;
	}
	ray->lenght = -1;
}
