/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:18:11 by alienard          #+#    #+#             */
/*   Updated: 2020/02/18 14:18:50 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include "libft/libft.h"
# include "libft/libftprintf.h"
# include "libft/get_next_line_bonus.h"

typedef struct	s_pt
{
	double			x;
	double			y;
	double			z;
}				t_pt;

typedef struct	s_ray
{
	t_pt			orig;
	t_pt			dir;
	double			lenght;
	t_pt			ray;
	t_pt			unit;
}				t_ray;

typedef struct	s_mat
{
	t_pt			x;
	t_pt			y;
	t_pt			z;
	t_pt			a;
}				t_mat;

typedef struct	s_argb
{
	double			a;
	double			r;
	double			g;
	double			b;
}				t_argb;

typedef struct	s_cam
{
	t_pt			coord;
	t_pt			ori;
	int				fov;
	t_pt			pij;
	t_pt			rij;
	struct s_cam	*next;
}				t_cam;

typedef struct	s_light
{
	double			light_ratio;
	t_argb			col;
	t_pt			coord;
	struct s_light	*next;
}				t_light;

typedef struct	s_shape
{
	int				id;
	t_argb			color;
	t_pt			pt_0;
	t_pt			pt_1;
	t_pt			pt_2;
	t_pt			ori;
	double			diameter;
	double			height;
	struct s_shape	*next;
}				t_shape;

typedef struct	s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data;
	int				depth;
	int				size_line;
	int				endian;
	int				x;
	int				y;
	double			ratio;
	t_argb			col;
	t_cam			*beg_cam;
	t_shape			*beg_sh;
	t_light			*beg_light;
}				t_window;

int				ft_window_init(t_window *win);
void			ft_argb_init(t_argb *a);
void			ft_pt_init(t_pt *a, double x, double y, double z);
void			ft_swap_pt(t_pt *a, t_pt *b);

int				ft_amb_light_init(t_window *amb_light, char *line);
int				ft_resol_init(t_window *resol, char *line);
int				ft_check_resol(t_window *win);
int				ft_check_amb_light(t_window *win);

int				ft_cam_init(t_cam **begin, char *line);
int				ft_check_cam_parsing(t_cam *current);

int				ft_light_init(t_light **begin, char *line);
int				ft_check_light_parsing(t_light *current);

int				ft_shape_init(t_shape **begin, char *line);

int				ft_color_init(t_argb *col, char **line);
int				ft_color_check(t_argb color);
int				ft_point_init(t_pt *pt, char **line);
int				ft_pt_check(t_pt pt);
int				ft_ori_check(t_pt ori);

int				ft_sphere_init(t_shape **current, char *line);
int				ft_plane_init(t_shape **current, char *line);
int				ft_square_init(t_shape **current, char *line);
int				ft_cylinder_init(t_shape **current, char *line);
int				ft_triangle_init(t_shape **current, char *line);

int				ft_sphere_check(t_shape **current);
int				ft_plane_check(t_shape **current);
int				ft_square_check(t_shape **current);
int				ft_cylinder_check(t_shape **current);
int				ft_triangle_check(t_shape **current);

int				ft_which_id(char *line);
void			ft_iterate_in_line(char **line);
int				ft_error(int error);
int				ft_close(t_window *win);
int				ft_free_lst_cam(t_window *win);
int				ft_free_lst_light(t_window *win);
int				ft_free_lst_sh(t_window *win);

int				ft_key(int keycode, t_window *param);
int				ft_mouse(int button, int x, int y, t_window *param);
int				ft_expose(t_window *win);

double			ft_sqr(double d);
double			ft_dot_product(t_pt a, t_pt b);
double			ft_lenght(t_pt *a);
t_pt			ft_normal_vect(t_pt a);
void			ft_orthogonality(t_pt a, t_pt b);
t_pt			ft_cross_product(t_pt a, t_pt b);
t_pt			ft_addition(t_pt a, t_pt b);
void			ft_add_scal(double a, t_pt *b);
t_pt			ft_subtraction(t_pt a, t_pt b);
void			ft_sub_scal(double a, t_pt *b);
t_pt			ft_multi_vect(t_pt a, t_pt b);
t_pt			ft_multi_scal(double a, t_pt b);
t_pt			ft_div_scal(double a, t_pt b);
void			ft_inv_pt(t_pt *dir);
t_pt			ft_translation(t_pt coord, t_pt m1);
t_pt			ft_rotation(t_pt ori, t_pt m1);
t_pt			ft_rot_arr_x(double angle);
t_pt			ft_rot_arr_y(double angle);
t_pt			ft_rot_arr_z(double angle);
t_pt			ft_point_matrix_transl(t_pt p, t_mat m);

t_pt			ft_pre_light(t_window *win, t_shape *sh, double clos,
		t_ray *ray);
t_pt			ft_light(t_window *win, t_pt n, t_pt p, t_shape *sh);
double			ft_shadow(t_window *win, t_pt n, t_pt p, t_shape *sh);
int				ft_lstsize_light(t_window *win);
t_argb			ft_albedo(t_pt a, t_argb col);
t_argb			ft_multi_argb(t_argb a, t_argb col);
void			ft_pix(int x, int y, t_window *w, t_argb color);
void			ft_db_mult_to_add_pt(t_pt *a, double b, t_argb c);

int				ft_aff(t_window *win);
void			ft_ray(double x, double y, t_window *win, t_cam *cur_cam);
t_argb			ft_trace_ray(t_window *win, t_cam *cam);
t_ray			ft_shoot_ray(t_pt orig, t_pt dir, double t);
t_ray			ft_no_ray(void);
void			ft_init_ray_cam(t_cam *cam, t_ray *ray);

void			ft_which_shape(t_shape *sh, t_ray *ray);

void			ft_intersect_ray_sphere(t_shape *sh, t_ray *ray);
void			ft_intersect_ray_plan(t_shape *sh, t_ray *ray);
void			ft_intersect_ray_square(t_shape *sh, t_ray *ray);
void			ft_intersect_ray_cylinder(t_shape *sh, t_ray *ray);
void			ft_intersect_ray_triangle(t_shape *sh, t_ray *ray);

t_pt			ft_shape_norm(t_shape *sh, t_ray *ray);
t_pt			ft_triangle_norm(t_shape *sh);

double			ft_is_in_triangle(t_pt ray, t_shape *sh, t_pt n);
double			ft_is_in_square(t_ray *ray, t_shape *sh, t_pt n);

int				ft_aff_sq(t_shape *cur_shape, t_window *win);
double			ft_aff_sp(t_shape *sh, t_cam *cam, t_pt v);
int				ft_aff_pl(t_shape *cur, t_window *win);
void			ft_droite(int x1, int y1, int x2, int y2, t_window *w);

#endif
