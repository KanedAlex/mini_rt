/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:25:37 by alienard          #+#    #+#             */
/*   Updated: 2020/07/17 14:59:39 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ft_close(t_window *win)
{
	get_next_line(win->fd, &win->line, 1);
	if (win->line){
		free(win->line);
		win->line = NULL;
	}
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
	close(win->fd);
	exit(0);
	return (0);
}

int	ft_free_lst_cam(t_window *win)
{
	t_cam	*tmp_c;

	tmp_c = win->beg_cam;
	while (win->beg_cam)
	{
		tmp_c = win->beg_cam->next;
		if ( win->beg_cam)
		{
			free(win->beg_cam);
			win->beg_cam = NULL;
		}
		win->beg_cam = tmp_c;
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
		tmp_l = win->beg_light->next;
		if (win->beg_light)
		{
			free(win->beg_light);
			win->beg_light = NULL;
		}
		win->beg_light = tmp_l;
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
		tmp_s = win->beg_sh->next;
		if (win->beg_sh)
		{
			free(win->beg_sh);
			win->beg_sh = NULL;
		}
		win->beg_sh = tmp_s;
	}
	win->beg_light = NULL;
	tmp_s = NULL;
	return (0);
}
