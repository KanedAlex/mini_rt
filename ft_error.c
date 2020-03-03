/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:14:41 by alienard          #+#    #+#             */
/*   Updated: 2020/03/02 20:00:51 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	ft_error_save(int error)
{
	if (error == -5)
		ft_printf(" : error during open.\n");
	if (error == -2)
		ft_printf(" : error during file header writing.\n");
	if (error == -3)
		ft_printf(" : error during info header writing.\n");
	if (error == -4)
		ft_printf(" : error during .bmp writing.\n");
	if (error == 2)
		ft_printf(" : close not ok.\n");
	if (error == 4)
		ft_printf(" : shape line invalid.\n");
	if (error == 5)
		ft_printf(" : wrong shape id.\n");
	if (error == 6)
		ft_printf(" : malloc error in lst_shape.\n");
	if (error == 39)
		ft_printf(" : error in saving.\n");
}

void	ft_shape_error(int error)
{
	if (error == 17)
		ft_printf(" : error in shape creation.\n");
	if (error == 20)
		ft_printf(" : invalid parameter, negative shape height.\n");
	if (error == 25)
		ft_printf(" : too much square param.\n");
	if (error == 26)
		ft_printf(" : too much triangle param.\n");
	if (error == 27)
		ft_printf(" : too much sphere param.\n");
	if (error == 28)
		ft_printf(" : too much plane param.\n");
	if (error == 29)
		ft_printf(" : too much cylinder param.\n");
	if (error == 34)
		ft_printf(" : not enough square param.\n");
	if (error == 35)
		ft_printf(" : not enough triangle param.\n");
	if (error == 36)
		ft_printf(" : not enough sphere param.\n");
	if (error == 37)
		ft_printf(" : not enough plane param.\n");
	if (error == 38)
		ft_printf(" : not enough cylinder param.\n");
}

void	ft_light_error(int error)
{
	if (error == 9)
		ft_printf(" : ambiant light line parameters invalid.\n");
	if (error == 10)
		ft_printf(" : too much ambiant light parameters.\n");
	if (error == 18)
		ft_printf(" : error in light creation.\n");
	if (error == 19)
		ft_printf(" : light ratio invalid.\n");
	if (error == 21)
		ft_printf(" : no ambiant light parameters.\n");
	if (error == 22)
		ft_printf(" : no ambiant light ratio.\n");
	if (error == 24)
		ft_printf(" : too much light param.\n");
	if (error == 33)
		ft_printf(" : not enough light param.\n");
	if (error == 31)
		ft_printf(" : not enough ambiant light parameters.\n");
}

void	ft_cam_error(int error)
{
	if (error == 14)
		ft_printf(" : invalid camera.\n");
	if (error == 15)
		ft_printf(" : invalid camera orientation value(s).\n");
	if (error == 16)
		ft_printf(" : invalid camera fov value.\n");
	if (error == 23)
		ft_printf(" : too much cam param.\n");
	if (error == 32)
		ft_printf(" : not enough cam param.\n");
	if (error == 8)
		ft_printf(" : resoltion line parameters invalid.\n");
	if (error == 11)
		ft_printf(" : point parameters invalids/non-existants.\n");
	if (error == 12)
		ft_printf(" : missing color component(s), line invalid.\n");
	if (error == 13)
		ft_printf(" : invalid color value(s).\n");
	if (error == 30)
		ft_printf(" : not enough resoltion line parameters.\n");
}

int		ft_error(int error)
{
	static int i = 0;

	if (i == -1)
		return (-1);
	ft_printf("Error \n%d", error);
	ft_error_save(error);
	ft_shape_error(error);
	ft_light_error(error);
	if (error == -1)
		ft_printf(" : shape could not init.\n");
	if (error == 0)
		ft_printf(" : invalid number of arguments.\n");
	if (error == 1)
		ft_printf(" : malloc error in window struc init.\n");
	if (error == 3)
		ft_printf(" : miniLibX function failed to proceed.\n");
	if (error == 7)
		ft_printf(" : too much resoltion line parameters.\n");
	i = -1;
	return (-1);
}
