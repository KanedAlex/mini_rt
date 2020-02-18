/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:06:42 by alienard          #+#    #+#             */
/*   Updated: 2020/02/13 19:05:49 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

// /*
// 		matrice
// 		[c00, c01, c02, 0] -> x axis
// 		[c10, c11, c12, 0] -> y axis
// 		[c20, c21, c22, 0]	-> z axis
//		[c30, c31, c32, 1]	->obj

// 		when we rotate arround an axis, its coord are 
// 		left untouched
// */

t_pt	ft_point_matrix_transl(t_pt p, t_mat m)
{
	t_pt	n;
	t_pt	t;

	t.x = 1;
	t.y = 1;
	t.z = -1;

	n.x = p.x * m.x.x + p.y * m.y.x + p.z * m.z.x + t.x;
	n.y = p.x * m.x.y + p.y * m.y.y + p.z * m.z.y + t.y;
	n.z = p.x * m.x.z + p.y * m.y.z + p.z * m.z.z + t.z;
	return (n);
}

void	ft_ray_transf(t_pt *src, t_pt *dst, double **m)
{
	dst->x = src->x * m[0][0] + src->y * m[1][0] + src->z * m[2][0];
	dst->y = src->x * m[0][1] + src->y * m[1][1] + src->z * m[2][1];
	dst->z = src->x * m[0][2] + src->y * m[1][2] + src->z * m[2][2];
}
