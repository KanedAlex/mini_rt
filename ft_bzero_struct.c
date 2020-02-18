/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 20:35:36 by alienard          #+#    #+#             */
/*   Updated: 2020/02/13 19:05:49 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		ft_window_init(t_window *win)
{
	win->beg_sh = NULL;
	win->beg_cam = NULL;
	win->beg_light = NULL;
	win->mlx_ptr = NULL;
	win->win_ptr = NULL;
	win->img_ptr = NULL;
	win->data = NULL;
	win->endian = -1;
	win->x = -1;
	win->y = -1;
	win->ratio = -1;
	return (0);
}

void	ft_pt_init(t_pt *a, double x, double y, double z)
{
	a->x = x;
	a->y = y;
	a->z = z;
}

void	ft_argb_init(t_argb *a)
{
	a->a = 0;
	a->r = 0;
	a->g = 0;
	a->b = 0;
}
