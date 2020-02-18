/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:52:09 by alienard          #+#    #+#             */
/*   Updated: 2020/02/13 19:05:49 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ft_key(int keycode, t_window *param)
{
	ft_printf("keycode:%d\n", keycode);
	if (keycode == 53)
	{
		ft_close(param);
		exit(0);
	}
	return (0);
}

int	ft_mouse(int button, int x, int y, t_window *param)
{
	ft_printf("button:%d\n", button);
	ft_printf("x:%d\n", x);
	ft_printf("y:%d\n", y);
	(void)param;
	return (0);
}

int	ft_expose(t_window *win)
{
	ft_check_amb_light(win);
	return (0);
}
