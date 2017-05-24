/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:31:38 by atrudel           #+#    #+#             */
/*   Updated: 2017/02/08 16:07:28 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define SIZE_SCREEN_X	1200
# define SIZE_SCREEN_Y	1200
# define ABS(x) (x >= 0 ? x : -x)
# define MIN(x, y) (x < y ? x : y)
# define GRID (inter->grid)

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
	float		initial_z;
	float		altitude;
	long		screen_x;
	long		screen_y;
	int			color;
}				t_point;

typedef enum	e_proj
{
	ISO, LINEAR
}				t_proj;

typedef enum	e_color_component
{
	BLUE, GREEN, RED
}				t_color_component;

typedef struct	s_interface
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	float		red;
	float		green;
	float		blue;
	int			gradation;
	char		*img_addr;
	t_point		***grid;
	int			grid_size_x;
	int			grid_size_y;
	int			z_stats_switch;
	int			z_min;
	int			z_max;
	float		scale;
	float		scale_z;
	t_proj		projection;
	float		camera_height;
	float		focus_height;
	float		distance;
}				t_interface;

void			parse(int argc, const char **argv, t_interface *inter);

void			img_pixel_put(t_interface *inter, int x, int y, int color);
void			draw_line(t_interface *inter, t_point *p1, t_point *p2);
void			img_erase(t_interface *inter);
int				get_color(t_interface *inter, float coefficient);
int				get_color_pixel(t_interface *inter, t_point *p1, t_point *p2,
				float coefficient);
int				get_color_point(t_interface *inter, t_point *point);

void			set_z_stats(t_interface *inter);
void			set_altitudes(t_interface *inter);
void			set_coordinates(t_interface *inter);

void			paste_grid(t_interface *inter);
void			transform_grid(t_interface *inter, float transf_mtx[4][4]);
void			destroy_grid(t_interface *inter);

void			project_isometric(t_interface *inter);
void			project_linear(t_interface *inter);

int				keyboard(int keycode, t_interface *inter);
void			escape(t_interface *inter);
void			move(int keycode, t_interface *inter);
void			rotate(int keycode, t_interface *inter);
void			zoom(int keycode, t_interface *inter);
void			switch_projection(int keycode, t_interface *inter);
void			change_color(int keycode, t_interface *inter);

void			translate_img(t_interface *inter, int x, int y);
void			center_img(t_interface *inter);
void			translation(t_interface *inter, float x, float y, float z);
void			rotation(t_interface *inter, float angle);
void			scaling(t_interface *inter, float coefficient_xy,
				float coefficient_z);
void			center(t_interface *inter, float *dx, float *dy);
void			adjust_distance(t_interface *inter);

t_point			*get_central_point(t_interface *inter);
t_point			*get_closest_point(t_interface *inter);

void			multiply_mtx(t_point *point, float transf_mtx[4][4],
							float (*result_mtx)[4]);
#endif
