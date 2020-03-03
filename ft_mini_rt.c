/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_rt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:17:00 by alienard          #+#    #+#             */
/*   Updated: 2020/03/02 19:51:51 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		ft_aff(t_window *win)
{
	double	i;
	double	j;
	t_cam	*cam;

	win->img_ptr = mlx_new_image(win->mlx_ptr, win->x, win->y);
	win->data = mlx_get_data_addr(win->img_ptr, &(win->depth),
								&(win->size_line), &(win->endian));
	cam = win->cur_cam;
	j = 0;
	while (j != win->y)
	{
		i = 0;
		while (i != win->x)
		{
			ft_ray(i, j, win, cam);
			i += win->resol;
		}
		j += win->resol;
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

	while ((ret = get_next_line(fd, &line)) >= 0)
	{
		if (line[0] == 'R' && (ft_isspace(line[1])) == 1 && *check != -1)
			*check = ft_resol_init(win, line);
		else if (line[0] == 'A' && (ft_isspace(line[1])) == 1 && *check != -1)
			*check = ft_amb_light_init(win, line);
		else if (line[0] == 'c' && (ft_isspace(line[1])) == 1 && *check != -1)
			*check = ft_cam_init(&win->beg_cam, line);
		else if (line[0] == 'l' && (ft_isspace(line[1])) == 1 && *check != -1)
			*check = ft_light_init(&win->beg_light, line);
		else if ((ft_isalpha(line[0])) == 1 && *check != -1)
			*check = ft_shape_init(&win->beg_sh, line);
		free(line);
		if (ret == 0 || *check == -1)
			break ;
	}
	if (ret == -1)
		*check = -1;
}

void	ft_mlx_init(t_window *win, int ac, char **av)
{
	int		ret;

	mlx_key_hook(win->win_ptr, &ft_key, win);
	mlx_mouse_hook(win->win_ptr, &ft_mouse, win);
	if (ac == 3 && ft_strncmp("-save", av[2], ft_strlen(av[2])) == 0)
	{
		ret = ft_save(win);
		ret == 0 ? ft_close(win) : ft_error(ret);
	}
	mlx_hook(win->win_ptr, 17, 0, &ft_close, win);
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
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (ft_error(-5));
	ft_parse(&check, &win, fd);
	(check == -1) ? ft_close(&win) : check;
	if (close(fd) < 0)
		return (ft_error(2));
	check = (check != -1) ? ft_check_resol(&win) : check;
	check = (check != -1) ? ft_check_amb_light(&win) : check;
	check = (check != -1) ? ft_check_cam_parsing(win.beg_cam) : check;
	win.cur_cam = win.beg_cam;
	(check == -1) ? ft_close(&win) : 0;
	if (!(win.mlx_ptr = mlx_init()))
		return (check = ft_error(3));
	(check == -1) ? ft_close(&win) : 0;
	win.win_ptr = mlx_new_window(win.mlx_ptr, win.x, win.y, "miniRT");
	check = ft_aff(&win);
	(check == -1) ? ft_close(&win) : ft_mlx_init(&win, ac, av);
	return (0);
}
