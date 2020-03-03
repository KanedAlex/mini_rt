/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:14:29 by alienard          #+#    #+#             */
/*   Updated: 2020/03/02 18:53:51 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ft_check_resol(t_window *win)
{
	if (!win || !win->x || !win->y || win->x < 0 || win->y < 0)
		return (ft_error(8));
	if (win->x > 2560)
		win->x = 2560;
	if (win->y > 1440)
		win->y = 1440;
	return (0);
}

int	ft_check_amb_light(t_window *win)
{
	int check;

	if (!win)
		return (ft_error(21));
	if (!win->ratio)
		return (ft_error(22));
	if (win->ratio < 0.0 || 1.0 < win->ratio)
		return (ft_error(9));
	check = ft_color_check(win->col);
	return ((check == 0) ? check : ft_error(check));
}

int	ft_check_cam_parsing(t_cam *current)
{
	int check;

	if (!current)
		return (ft_error(14));
	if (current->fov < 0 || current->fov > 180)
		return (ft_error(16));
	check = ft_pt_check(current->coord);
	check = ft_ori_check(current->ori);
	return ((check == 0) ? check : ft_error(check));
}

int	ft_check_light_parsing(t_light *current)
{
	int check;

	if (!current)
		return (ft_error(18));
	if (current->light_ratio < 0.0 || current->light_ratio > 1.0)
		return (ft_error(19));
	check = ft_pt_check(current->coord);
	check = ft_color_check(current->col);
	return ((check == 0) ? check : ft_error(check));
}
