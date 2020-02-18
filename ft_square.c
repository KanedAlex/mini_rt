/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:15:20 by alienard          #+#    #+#             */
/*   Updated: 2020/02/18 13:58:36 by alienard         ###   ########.fr       */
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

void	ft_intersect_ray_square(t_shape *sh, t_ray *ray)
{
	t_pt	n;
	double	d;
	double	t;
	t_pt	r;

	n = sh->ori;
	d = -ft_dot_product(n, sh->pt_0);
	t = -(ft_dot_product(n, ray->orig) + d) / ft_dot_product(n, ray->dir);
	if (t < 0.0001)
	{
		ray->lenght = -1;
		return ;
	}
	r = ft_addition(ray->orig, ft_multi_scal(t, ray->dir));
	if ((d = ft_is_in_square(ray, sh, n)) == 0)
		ray->lenght = t;
	else
		ray->lenght = -1;
}

double	ft_is_in_square(t_ray *ray, t_shape *sh, t_pt n)
{
	t_pt	t_min;
	t_pt	t_max;

	sh->pt_1 = ft_addition(ft_multi_scal(sh->height, n), sh->pt_0);
	t_min.x = (sh->pt_0.x - ray->orig.x) / ray->dir.x;
	t_max.x = (sh->pt_1.x - ray->orig.x) / ray->dir.x;
	if (t_min.x > t_max.x)
		ft_swap_double(&t_min.x, &t_max.x);
	t_min.y = (sh->pt_0.y - ray->orig.y) / ray->dir.y;
	t_max.y = (sh->pt_1.y - ray->orig.y) / ray->dir.y;
	if (t_min.y > t_max.y)
		ft_swap_double(&t_min.y, &t_max.y);
	if (t_min.x > t_max.y || t_min.y > t_max.x)
		return (-1);
	t_min.z = (sh->pt_0.z - ray->orig.z) / ray->dir.z;
	t_max.z = (sh->pt_1.z - ray->orig.z) / ray->dir.z;
	if (t_min.z < t_max.z)
		ft_swap_double(&t_min.z, &t_max.z);
	if (t_min.x > t_max.z || t_min.z > t_max.x
		|| t_min.y > t_max.z || t_min.z > t_max.y)
		return (-1);
	return (0);
}

// double	ft_is_in_square(t_cam *cam, t_shape *sh, t_pt outnorm)
// {
// 	t_pt	m;
// 	t_pt	n;
// 	t_pt	k;
// 	t_pt	t1;
// 	t_pt	t2;
// 	t_pt	tmp;
// 	double	t_n;
// 	double	t_f;

// 	(void)outnorm;
// 	m = cam->rij;
// 	ft_inv_pt(&m);
// 	n = ft_multi_vect(m, cam->pij);
// 	ft_pt_init(&tmp, -1, -1, -1);
// 	k.x = fabs(m.x) * sh->height;
// 	k.y = fabs(m.y) * sh->height;
// 	k.z = fabs(m.z) * sh->height;
// 	t1 = ft_subtraction(ft_multi_vect(tmp, n), k);
// 	t2 = ft_addition(ft_multi_vect(tmp, n), k);
// 	t_n = fmax(fmax(t1.x, t1.y), t1.z);
// 	t_f = fmax(fmax(t2.x, t2.y), t2.z);
// 	if (t_n > t_f || t_f < 0.0 )
// 		return (-1);
// 	return (0);
// }
