/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triangle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:00:15 by alienard          #+#    #+#             */
/*   Updated: 2020/03/02 18:11:50 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		ft_triangle_init(t_shape **current, char *line)
{
	int check;

	(*current)->id = 't';
	while ((ft_isspace(*line)) == 1 || (ft_isalpha(*line)) == 1)
		line++;
	check = (ft_isnum(line) == 1) ? ft_point_init(&(*current)->pt_0, &line)
		: ft_error(35);
	check = (ft_isnum(line) == 1) ? ft_point_init(&(*current)->pt_1, &line)
		: ft_error(35);
	check = (ft_isnum(line) == 1) ? ft_point_init(&(*current)->pt_2, &line)
		: ft_error(35);
	check = (ft_isdigit(*line) == 1) ? ft_color_init(&(*current)->color, &line)
		: ft_error(35);
	if (check == 0)
		check = (*line == '\0') ? ft_triangle_check(current) : ft_error(26);
	return (check);
}

int		ft_triangle_check(t_shape **current)
{
	int check;

	if (!current || !(*current))
		return (ft_error(17));
	check = ft_pt_check((*current)->pt_0);
	check = ft_pt_check((*current)->pt_1);
	check = ft_pt_check((*current)->pt_2);
	check = ft_color_check((*current)->color);
	return (check);
}

void	ft_intersect_ray_triangle(t_shape *sh, t_ray *ray)
{
	double	d;
	double	t;
	t_pt	r;

	ft_triangle_norm(sh);
	d = -ft_dot_product(sh->n, sh->pt_0);
	t = -(ft_dot_product(sh->n, ray->orig) + d) \
		/ ft_dot_product(sh->n, ray->dir);
	if (t < 0.0001)
	{
		ray->lenght = -1;
		return ;
	}
	r = ft_addition(ray->orig, ft_multi_scal(t, ray->dir));
	if ((d = ft_is_in_triangle(r, sh, ray)) == 0)
		ray->lenght = t;
	else
		ray->lenght = -1;
}

void	ft_triangle_norm(t_shape *sh)
{
	t_pt	u;
	t_pt	v;

	u = ft_subtraction(sh->pt_1, sh->pt_0);
	v = ft_subtraction(sh->pt_2, sh->pt_0);
	sh->n = ft_cross_product(u, v);
	sh->n = ft_normal_vect(sh->n);
}

double	ft_is_in_triangle(t_pt r, t_shape *sh, t_ray *ray)
{
	t_mat	edge;
	t_mat	c;

	edge.x = ft_subtraction(sh->pt_1, sh->pt_0);
	edge.y = ft_subtraction(sh->pt_2, sh->pt_1);
	edge.z = ft_subtraction(sh->pt_0, sh->pt_2);
	c.x = ft_subtraction(r, sh->pt_0);
	c.y = ft_subtraction(r, sh->pt_1);
	c.z = ft_subtraction(r, sh->pt_2);
	if (ft_dot_product(sh->n, ft_cross_product(edge.x, c.x)) < 0
		|| ft_dot_product(sh->n, ft_cross_product(edge.y, c.y)) < 0
		|| ft_dot_product(sh->n, ft_cross_product(edge.z, c.z)) < 0)
		return (-1);
	sh->n = c.x;
	sh->n = ft_normal_vect(sh->n);
	ft_triangle_norm(sh);
	if (ft_dot_product(ft_subtraction(sh->pt_0, ray->orig), sh->n) > 0.001)
		ft_inv_norm(&sh->n);
	return (0);
}
