/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 09:33:32 by alienard          #+#    #+#             */
/*   Updated: 2020/02/19 13:26:29 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		ft_color_init(t_argb *col, char **line)
{
	col->a = -1;
	col->r = -1;
	col->g = -1;
	col->b = -1;
	col->r = ((ft_isdigit(**line) == 1) ? ft_atoi(*line) : ft_error(12));
	while ((ft_isdigit(**line)) == 1 && **line)
		(*line)++;
	(**line == ',') ? (*line)++ : 0;
	col->g = ((ft_isdigit(**line) == 1) ? ft_atoi(*line) : ft_error(12));
	while ((ft_isdigit(**line)) == 1 && **line)
		(*line)++;
	(**line == ',') ? (*line)++ : 0;
	col->b = ((ft_isdigit(**line) == 1) ? ft_atoi(*line) : ft_error(12));
	while ((ft_isdigit(**line)) == 1 && **line)
		(*line)++;
	while ((ft_isspace(**line)) == 1)
		(*line)++;
	return (ft_color_check(*col));
}

int		ft_point_init(t_pt *pt, char **line)
{
	pt->x = ((ft_isnum(*line) == 1) ? ft_atof(*line) : ft_error(11));
	while (((ft_isdigit(**line)) == 1 || **line == '.' || **line == '-')
		&& **line)
		(*line)++;
	(**line == ',') ? (*line)++ : 0;
	pt->y = ((ft_isnum(*line) == 1) ? ft_atof(*line) : ft_error(11));
	while (((ft_isdigit(**line)) == 1 || **line == '.' || **line == '-')
		&& **line)
		(*line)++;
	(**line == ',') ? (*line)++ : 0;
	pt->z = ((ft_isnum(*line) == 1) ? ft_atof(*line) : ft_error(11));
	while (((ft_isdigit(**line)) == 1 || **line == '.' || **line == '-')
		&& **line)
		(*line)++;
	while ((ft_isspace(**line)) == 1)
		(*line)++;
	return (ft_pt_check(*pt));
}

int		ft_shape_init(t_shape **begin, char *line)
{
	int		i;
	int		ret;
	t_shape *current;

	i = 0;
	ret = 0;
	if ((i = ft_which_id(line)) == -1)
		return (ft_error(5));
	if (!(current = ft_calloc(1, sizeof(t_shape))))
		return (ft_error(6));
	ret = (i == 's') ? ft_sphere_init(&current, line) : ret;
	ret = (i == 'p') ? ft_plane_init(&current, line) : ret;
	ret = (i == 'q') ? ft_square_init(&current, line) : ret;
	ret = (i == 'y') ? ft_cylinder_init(&current, line) : ret;
	ret = (i == 't') ? ft_triangle_init(&current, line) : ret;
	current->next = *begin;
	*begin = current;
	if (ret == -1)
		return (ft_error(17));
	return (ret);
}

int		ft_amb_light_init(t_window *amb_light, char *line)
{
	while (*line && ((ft_isspace(*line)) == 1
				|| (ft_isalpha(*line)) == 1))
		line++;
	amb_light->ratio = (((ft_isdigit(*line)) == 1) ? ft_atof(line)
		: ft_error(31));
	while (((ft_isdigit(*line)) == 1 || *line == '.') && *line)
		line++;
	while (*line && (ft_isspace(*line)) == 1)
		line++;
	((ft_isdigit(*line)) == 1) ? ft_color_init(&amb_light->col, &line)
		: ft_error(31);
	return ((*line == '\0') ? ft_check_amb_light(amb_light) : ft_error(10));
}

int		ft_resol_init(t_window *resol, char *line)
{
	while (*line && ((ft_isspace(*line)) == 1
				|| (ft_isalpha(*line)) == 1))
		line++;
	resol->x = ((ft_isdigit(*line) == 1) ? ft_atoi(line) : ft_error(30));
	while ((ft_isdigit(*line)) == 1 && *line)
		line++;
	while (*line && (ft_isspace(*line)) == 1)
		line++;
	resol->y = ((ft_isdigit(*line) == 1) ? ft_atoi(line) : ft_error(30));
	while (((ft_isdigit(*line)) == 1) && *line)
		line++;
	while ((ft_isspace(*line)) == 1)
		line++;
	return ((*line == '\0') ? ft_check_resol(resol) : ft_error(7));
}
