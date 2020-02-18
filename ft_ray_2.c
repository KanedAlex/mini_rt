/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:56:28 by alienard          #+#    #+#             */
/*   Updated: 2020/02/18 21:57:38 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_ray	ft_no_ray(void)
{
	t_ray	ray;

	ray.lenght = -1;
	return (ray);
}

void	ft_which_shape(t_shape *sh, t_ray *ray)
{
	if (sh->id == 's')
		ft_intersect_ray_sphere(sh, ray);
	else if (sh->id == 'p')
		ft_intersect_ray_plan(sh, ray);
	else if (sh->id == 'q')
		ft_intersect_ray_square(sh, ray);
	else if (sh->id == 'y')
		ft_intersect_ray_cylinder(sh, ray);
	else if (sh->id == 't')
		ft_intersect_ray_triangle(sh, ray);
}

void	ft_inv_pt(t_pt *dir)
{
	dir->x = 1 / dir->x;
	dir->y = 1 / dir->y;
	dir->z = 1 / dir->z;
}

void	ft_shape_norm(t_shape *sh, t_ray *ray)
{
	if (sh->id == 's')
		ft_sphere_norm(sh, ray);
	else if (sh->id == 'p')
		ft_plane_norm(sh);
	else if (sh->id == 'q')
		ft_square_norm(sh);
	else if (sh->id == 'y')
		ft_cylinder_norm(sh, ray);
	else if (sh->id == 't')
		ft_triangle_norm(sh);
}
