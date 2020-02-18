/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:04:12 by alienard          #+#    #+#             */
/*   Updated: 2020/02/18 12:43:42 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		ft_which_id(char *line)
{
	if (line[0] == 's' && (ft_isalpha(line[1])) == 1)
	{
		if (line[1] == 'q' && (ft_isspace(line[2])) == 1)
			return ('q');
		if (line[1] == 'p' && (ft_isspace(line[2])) == 1)
			return ('s');
	}
	if (line[0] == 'c' && line[1] == 'y' && (ft_isspace(line[2])) == 1)
		return ('y');
	if (line[0] == 't' && line[1] == 'r' && (ft_isspace(line[2])) == 1)
		return ('t');
	if (line[0] == 'p' && line[1] == 'l' && (ft_isspace(line[2])) == 1)
		return ('p');
	return (-1);
}

void	ft_iterate_in_line(char **line)
{
	while ((ft_isdigit(**line)) == 1 || **line == '.' || **line == ',')
		(*line)++;
	while ((ft_isspace(**line)) == 1)
		(*line)++;
}

int		ft_cam_init(t_cam **begin, char *line)
{
	t_cam *current;

	if (!(current = ft_calloc(1, sizeof(t_cam))))
		return (ft_error(6));
	while ((ft_isspace(*line)) == 1 || (ft_isalpha(*line)) == 1)
		line++;
	(ft_isnum(line) == 1) ? ft_point_init(&(*current).coord, &line)
		: ft_error(32);
	(ft_isnum(line) == 1) ? ft_point_init(&(*current).ori, &line)
		: ft_error(32);
	current->fov = ((ft_isdigit(*line) == 1) ? ft_atoi(line) : ft_error(32));
	while ((ft_isdigit(*line)) == 1)
		line++;
	while ((ft_isspace(*line)) == 1)
		line++;
	current->next = *begin;
	*begin = current;
	return ((*line == '\0') ? ft_check_cam_parsing(current) : ft_error(23));
}

int		ft_light_init(t_light **begin, char *line)
{
	t_light *current;

	if (!(current = ft_calloc(1, sizeof(t_light))))
		return (ft_error(6));
	while ((ft_isspace(*line)) == 1 || (ft_isalpha(*line)) == 1)
		line++;
	(ft_isnum(line) == 1) ? ft_point_init(&(*current).coord, &line)
		: ft_error(33);
	(*current).light_ratio = ((ft_isdigit(*line) == 1) ? ft_atof(line)
		: ft_error(33));
	while ((ft_isdigit(*line)) == 1 || *line == '.')
		line++;
	while ((ft_isspace(*line)) == 1)
		line++;
	(ft_isdigit(*line) == 1) ? ft_color_init(&(*current).col, &line)
		: ft_error(33);
	current->next = *begin;
	*begin = current;
	return ((*line == '\0') ? ft_check_light_parsing(current) : ft_error(24));
}

