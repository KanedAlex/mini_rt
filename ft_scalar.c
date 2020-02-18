/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scalar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:04:12 by alienard          #+#    #+#             */
/*   Updated: 2020/02/13 19:05:49 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_pt	ft_multi_scal(double a, t_pt b)
{
	t_pt	c;

	c.x = (a * b.x);
	c.y = (a * b.y);
	c.z = (a * b.z);
	return (c);
}

t_pt	ft_div_scal(double a, t_pt b)
{
	t_pt	c;

	c.x = (b.x / a);
	c.y = (b.y / a);
	c.z = (b.z / a);
	return (c);
}

void	ft_add_scal(double a, t_pt *b)
{
	b->x += a;
	b->y += a;
	b->z += a;
}

void	ft_sub_scal(double a, t_pt *b)
{
	b->x -= a;
	b->y -= a;
	b->z -= a;
}
