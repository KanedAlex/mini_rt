/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parsing_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:38:06 by alienard          #+#    #+#             */
/*   Updated: 2020/02/13 19:05:49 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		ft_pt_check(t_pt pt)
{
	pt.x = pt.x;
	return (0);
}

int		ft_ori_check(t_pt ori)
{
	if (-1 > ori.x || ori.x > 1)
		return (15);
	if (ori.y < -1 || ori.y > 1)
		return (15);
	if (ori.z < -1 || ori.z > 1)
		return (15);
	return (0);
}

int		ft_color_check(t_argb color)
{
	if (0 > color.r || color.r > 255)
		return (13);
	if (0 > color.g || color.g > 255)
		return (13);
	if (0 > color.b || color.b > 255)
		return (13);
	return (0);
}
