/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:46:46 by alienard          #+#    #+#             */
/*   Updated: 2020/02/13 19:05:49 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	ft_pix(int x, int y, t_window *w, t_argb color)
{
	int col;
	int	const_one;

	const_one = ((w->y - y - 1) * w->x + x) * 4;

	col = 0;
	col += (char)color.r >> 16;
	col += (char)color.g >> 8;
	col += (char)color.b;

	// w->data[y * w->size_line + (w->depth / 8) * x] = (char)color.b;
	// w->data[(x + y * w->x) * 4 + 1] = (char)color.g;
	// w->data[y * w->size_line + (w->depth / 8) * x + 2] = (char)color.r;

	w->data[const_one] = col;

	// w->data[(x + y * w->x) * 4] = col; // blue
	// w->data[(x + y * w->x) * 4] = col; // red
	// w->data[(x + y * w->x) * 4] = col; // green

	w->data[((w->y - y - 1) * w->x + x) * 4 + 0] = (char)color.b;
	w->data[((w->y - y - 1) * w->x + x) * 4 + 1] = (char)color.g;
	w->data[((w->y - y - 1) * w->x + x) * 4 + 2] = (char)color.r;
}

t_argb	ft_multi_argb(t_argb a, t_argb col)
{
	t_argb	c;

	c.r = (a.r * col.r);
	c.g = (a.g * col.g);
	c.b = (a.b * col.b);
	return (c);
}

t_argb	ft_albedo(t_pt a, t_argb col)
{
	t_argb	c;

	c.r = (a.x * col.r / 255);
	c.g = (a.y * col.g / 255);
	c.b = (a.z * col.b / 255);
	return (c);
}

void	ft_db_mult_to_add_pt(t_pt *a, double b, t_argb c)
{
	a->x += b * (c.r);
	a->y += b * (c.g);
	a->z += b * (c.b);
}
