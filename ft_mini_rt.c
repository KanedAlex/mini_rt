/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_rt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:17:00 by alienard          #+#    #+#             */
/*   Updated: 2020/02/18 21:46:56 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		ft_aff(t_window *win)
{
	double		i;
	double		j;
	t_cam		*cam;

	win->img_ptr = mlx_new_image(win->mlx_ptr, win->x, win->y);
	win->data = mlx_get_data_addr(win->img_ptr, &(win->depth),
				&(win->size_line), &(win->endian));
	cam = win->beg_cam;
	j = 0;
	while (j != win->y)
	{
		i = -1;
		while (++i != win->x)
			ft_ray(i, j, win, cam);
		j++;
	}
	if (!(mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
		win->img_ptr, 0, 0)))
		return (ft_error(3));
	return (0);
}

void	ft_parse(int *check, t_window *win, int fd)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(fd, &line)) >= 0 && *check != -1)
	{
		if (line[0] == 'R' && (ft_isspace(line[1])) == 1)
			*check = ft_resol_init(win, line);
		else if (line[0] == 'A' && (ft_isspace(line[1])) == 1)
			*check = ft_amb_light_init(win, line);
		else if (line[0] == 'c' && (ft_isspace(line[1])) == 1)
			*check = ft_cam_init(&win->beg_cam, line);
		else if (line[0] == 'l' && (ft_isspace(line[1])) == 1)
			*check = ft_light_init(&win->beg_light, line);
		else if ((ft_isalpha(line[0])) == 1)
			*check = ft_shape_init(&win->beg_sh, line);
		free(line);
		if (ret == 0)
			break ;
	}
	if (ret == -1)
		*check = -1;
}

void	ft_mlx_init(t_window *win)
{
	mlx_key_hook(win->win_ptr, &ft_key, &win);
	mlx_mouse_hook(win->win_ptr, &ft_mouse, &win);
	mlx_expose_hook(win->win_ptr, &ft_expose, &win);
	mlx_hook(win->win_ptr, 17, 0, &ft_close, &win);
	mlx_loop(win->mlx_ptr);
}

int		main(int ac, char **av)
{
	t_window	win;
	int			fd;
	int			check;

	if (ac > 3 || !av[1])
		return (ft_error(0));
	ft_window_init(&win);
	fd = open(av[1], O_RDONLY);
	check = 0;
	ft_parse(&check, &win, fd);
	(check == -1) ? ft_close(&win) : 0;
	if (close(fd) < 0)
		return (ft_error(2));
	check = (check != -1) ? ft_check_resol(&win) : check;
	check = (check != -1) ? ft_check_amb_light(&win) : check;
	check = (check != -1) ? ft_check_cam_parsing(win.beg_cam) : check;
	(check == -1) ? ft_close(&win) : 0;
	if (!(win.mlx_ptr = mlx_init()))
		return (check = ft_error(3));
	(check == -1) ? ft_close(&win) : 0;
	win.win_ptr = mlx_new_window(win.mlx_ptr, win.x, win.y, "test");
	check = ft_aff(&win);
	(check == -1) ? ft_close(&win) : 0;
	ft_mlx_init(&win);
	return (0);
}
