/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:54:29 by alienard          #+#    #+#             */
/*   Updated: 2020/02/13 19:05:49 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_pt	ft_translation(t_pt coord, t_pt m1)
{
	t_pt	m2;

	m2 = m1;
	if (coord.x != 0)
		m2.x += coord.x;
	if (coord.y != 0)
		m2.y += coord.y;
	if (coord.x != 0)
		m2.z += coord.z;
	return (m2);
}

t_pt	ft_rotation(t_pt ori, t_pt m1)
{
	t_pt	m2;

	m2 = m1;
	if (ori.x != 0)
		m2 = ft_multi_vect(m1, ft_rot_arr_x(ori.x * (M_PI / 180)));
	if (ori.y != 0)
		m2 = ft_multi_vect(m1, ft_rot_arr_x(ori.y * (M_PI / 180)));
	if (ori.z != 0)
		m2 = ft_multi_vect(m1, ft_rot_arr_x(ori.z * (M_PI / 180)));
	return (m2);
}

t_pt	ft_rot_arr_x(double angle)
{
	t_pt	m;

	m.x = 1;
	m.y = cos(angle) - sin(angle);
	m.z = sin(angle) + cos(angle);
	return (m);
}

t_pt	ft_rot_arr_y(double angle)
{
	t_pt	m;

	m.x = cos(angle) + sin(angle);
	m.y = 1;
	m.z = cos(angle) - sin(angle);
	return (m);
}

t_pt	ft_rot_arr_z(double angle)
{
	t_pt	m;

	m.x = cos(angle) - sin(angle);
	m.y = cos(angle) + sin(angle);
	m.z = 1;
	return (m);
}
