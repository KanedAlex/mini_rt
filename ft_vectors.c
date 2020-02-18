/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:49:45 by alienard          #+#    #+#             */
/*   Updated: 2020/02/18 19:02:17 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

double	ft_sqr(double d)
{
	return (d * d);
}

double	ft_lenght(t_pt a)
{
	double len;

	len = ft_sqr(a.x) + ft_sqr(a.y) + ft_sqr(a.z);
	return (len);
}

t_pt	ft_normal_vect(t_pt a)
{
	double	len;
	t_pt	b;

	len = sqrt(ft_lenght(a));
	b = ft_div_scal(len, a);
	return (b);
}

double	ft_dot_product(t_pt a, t_pt b)
{
	double c;

	c = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	return (c);
}

void	ft_orthogonality(t_pt a, t_pt b)
{
	double	ret;

	ret = ft_dot_product(a, b);
	if (ret == 0)
		printf("les deux vecteurs sont perpendiculaires");
	else if (ret == 1)
		printf("les deux vecteurs sont strictement egaux");
	else if (ret == -1)
		printf("les deux vecteurs pointent dans des directions opposees");
}
