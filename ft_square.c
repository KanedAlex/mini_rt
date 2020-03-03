/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:15:20 by alienard          #+#    #+#             */
/*   Updated: 2020/03/02 18:16:37 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		ft_square_init(t_shape **current, char *line)
{
	int check;

	(*current)->id = 'q';
	while ((ft_isspace(*line)) == 1 || (ft_isalpha(*line)) == 1)
		line++;
	check = (ft_isnum(line) == 1) ? ft_point_init(&(*current)->pt_0, &line)
		: ft_error(34);
	check = (ft_isnum(line) == 1) ? ft_point_init(&(*current)->ori, &line)
		: ft_error(34);
	if (ft_isdigit(*line) == 1)
		(*current)->height = ft_atof(line);
	else
		check = ft_error(34);
	while ((ft_isdigit(*line)) == 1 || *line == '.')
		line++;
	while ((ft_isspace(*line)) == 1)
		line++;
	check = (ft_isdigit(*line) == 1) ? ft_color_init(&(*current)->color, &line)
		: ft_error(34);
	if (check == 0)
		check = (*line == '\0') ? ft_square_check(current) : ft_error(25);
	return (check);
}

int		ft_square_check(t_shape **current)
{
	int check;

	if (!current || !(*current))
		return (ft_error(17));
	if ((*current)->height < 0.0)
		return (ft_error(20));
	check = ft_pt_check((*current)->pt_0);
	check = ft_color_check((*current)->color);
	check = ft_ori_check((*current)->ori);
	return (check);
}

void	ft_square_norm(t_shape *sh)
{
	sh->n = sh->ori;
}

void	ft_intersect_ray_square(t_shape *sh, t_ray *ray)
{
	double	d;
	double	t;
	t_pt	r;

	sh->n = sh->ori;
	t = -ft_dot_product(sh->n, sh->pt_0);
	t = -(ft_dot_product(sh->n, ray->orig) + t) \
		/ ft_dot_product(sh->n, ray->dir);
	if (t < 0.0001)
	{
		ray->lenght = -1;
		return ;
	}
	r = ft_addition(ray->orig, ft_multi_scal(t, ray->dir));
	if ((d = ft_is_in_square(ray, sh, r)) == 0)
	{
		ray->lenght = t;
		ft_square_norm(sh);
		if (ft_dot_product(ft_subtraction(sh->pt_0, ray->orig), sh->n) > 0.001)
			ft_inv_norm(&sh->n);
	}
	else
		ray->lenght = -1;
}

double	ft_is_in_square(t_ray *ray, t_shape *sh, t_pt r)
{
	t_pt	tmp;
	double	h;

	(void)ray;
	h = sh->height / 2;
	tmp.x = fabs(r.x - sh->pt_0.x);
	tmp.y = fabs(r.y - sh->pt_0.y);
	tmp.z = fabs(r.z - sh->pt_0.z);
	if (tmp.x > h || tmp.y > h || tmp.z > h)
		return (-1);
	return (0);
}
