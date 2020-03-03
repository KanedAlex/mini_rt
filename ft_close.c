/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:25:37 by alienard          #+#    #+#             */
/*   Updated: 2020/03/03 10:00:12 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ft_close(t_window *win)
{
	ft_free_lst_cam(win);
	ft_free_lst_light(win);
	ft_free_lst_sh(win);
	if (win->mlx_ptr && win->img_ptr)
	{
		mlx_destroy_image(win->mlx_ptr, win->img_ptr);
	}
	if (win->mlx_ptr && win->win_ptr)
	{
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	}
	exit(0);
	return (0);
}

int	ft_free_lst_cam(t_window *win)
{
	t_cam	*tmp_c;

	tmp_c = win->beg_cam;
	while (win->beg_cam)
	{
		win->beg_cam = win->beg_cam->next;
		if (tmp_c)
		{
			free(tmp_c);
			tmp_c = NULL;
		}
		tmp_c = win->beg_cam;
	}
	win->beg_cam = NULL;
	tmp_c = NULL;
	return (0);
}

int	ft_free_lst_light(t_window *win)
{
	t_light	*tmp_l;

	tmp_l = win->beg_light;
	while (win->beg_light)
	{
		win->beg_light = win->beg_light->next;
		if (tmp_l)
		{
			free(tmp_l);
			tmp_l = NULL;
		}
		tmp_l = win->beg_light;
	}
	win->beg_light = NULL;
	tmp_l = NULL;
	return (0);
}

int	ft_free_lst_sh(t_window *win)
{
	t_shape	*tmp_s;

	tmp_s = win->beg_sh;
	while (win->beg_sh)
	{
		win->beg_sh = win->beg_sh->next;
		if (tmp_s)
		{
			free(tmp_s);
			tmp_s = NULL;
		}
		tmp_s = win->beg_sh;
	}
	win->beg_light = NULL;
	tmp_s = NULL;
	return (0);
}
