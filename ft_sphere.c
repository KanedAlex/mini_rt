/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:56:45 by alienard          #+#    #+#             */
/*   Updated: 2020/03/02 18:15:19 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		ft_sphere_init(t_shape **current, char *line)
{
	int	check;

	(*current)->id = 's';
	while ((ft_isspace(*line)) == 1 || (ft_isalpha(*line)) == 1)
		line++;
	check = (ft_isnum(line) == 1) ? ft_point_init(&(*current)->pt_0, &line)
		: ft_error(36);
	if (ft_isdigit(*line) == 1)
		(*current)->diameter = ft_atof(line);
	else
		check = ft_error(36);
	while ((ft_isdigit(*line)) == 1 || *line == '.')
		line++;
	while ((ft_isspace(*line)) == 1)
		line++;
	check = (ft_isdigit(*line) == 1) ? ft_color_init(&(*current)->color, &line)
		: ft_error(36);
	if (check == 0)
		check = (*line == '\0') ? ft_sphere_check(current) : ft_error(27);
	return (check);
}

int		ft_sphere_check(t_shape **current)
{
	int check;

	if (!current || !(*current))
		return (ft_error(17));
	if ((*current)->diameter < 0.0)
		return (ft_error(20));
	check = ft_pt_check((*current)->pt_0);
	check = ft_color_check((*current)->color);
	return (check);
}

void	ft_sphere_norm(t_shape *sh, t_ray *ray)
{
	t_pt	r;

	r = ft_addition(ray->orig, ft_multi_scal(ray->lenght, ray->dir));
	r = ft_subtraction(r, sh->pt_0);
	r = ft_normal_vect(r);
	sh->n = r;
}

void	ft_intersect_ray_sphere(t_shape *sh, t_ray *ray)
{
	double	b;
	double	c;
	t_pt	calc;
	t_pt	oc;

	sh->in = 0;
	oc = ft_subtraction(ray->orig, sh->pt_0);
	if (ft_lenght(oc) < sh->diameter)
		ft_multi_scal(-1, oc);
	b = 2 * ft_dot_product(oc, ray->dir);
	c = ft_dot_product(oc, oc) - ft_sqr(sh->diameter / 2);
	calc.x = (b * b) - (4 * c);
	if (calc.x < 0 && (ray->lenght = -1))
		return ;
	calc.y = (-b - sqrt(calc.x)) / 2;
	calc.z = (-b + sqrt(calc.x)) / 2;
	if (calc.z > 0.0001 && calc.z < calc.y)
		calc.y = calc.z;
	else if (calc.z > 0.0001 && calc.y < 0.0001)
		calc.y = calc.z;
	ray->lenght = calc.y;
	ft_sphere_norm(sh, ray);
	if (ft_dot_product(ray->dir, sh->n) > 0.001)
		ft_inv_norm(&sh->n);
}
