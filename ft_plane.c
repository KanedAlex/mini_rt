/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:57:37 by alienard          #+#    #+#             */
/*   Updated: 2020/03/02 18:12:08 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		ft_plane_init(t_shape **current, char *line)
{
	int	check;

	(*current)->id = 'p';
	while ((ft_isspace(*line)) == 1 || (ft_isalpha(*line)) == 1)
		line++;
	check = (ft_isnum(line) == 1) ? ft_point_init(&(*current)->pt_0, &line)
		: ft_error(37);
	check = (ft_isnum(line) == 1) ? ft_point_init(&(*current)->ori, &line)
		: ft_error(37);
	check = (ft_isdigit(*line) == 1) ? ft_color_init(&(*current)->color, &line)
		: ft_error(37);
	if (check == 0)
		check = (*line == '\0') ? ft_plane_check(current) : ft_error(28);
	return (check);
}

int		ft_plane_check(t_shape **current)
{
	int check;

	if (!current || !(*current))
		return (ft_error(17));
	check = ft_pt_check((*current)->pt_0);
	check = ft_color_check((*current)->color);
	check = ft_ori_check((*current)->ori);
	return (check);
}

void	ft_plane_norm(t_shape *sh)
{
	sh->n = sh->ori;
	sh->n = ft_rot_angle(sh->n, M_PI_2);
}

void	ft_intersect_ray_plan(t_shape *sh, t_ray *ray)
{
	double	t;
	double	d;

	d = -ft_dot_product(sh->ori, sh->pt_0);
	t = -(ft_dot_product(sh->ori, ray->orig) + d) \
		/ ft_dot_product(sh->ori, ray->dir);
	if (t > 0.0001)
	{
		ray->lenght = t;
		ft_plane_norm(sh);
		if (ft_dot_product(ft_subtraction(sh->pt_0, ray->orig), sh->n) > 0.001)
			ft_inv_norm(&sh->n);
	}
	else
		ray->lenght = -1;
}
