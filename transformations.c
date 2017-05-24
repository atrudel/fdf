/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:33:04 by atrudel           #+#    #+#             */
/*   Updated: 2017/01/31 20:34:25 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation(t_interface *inter, float angle)
{
	float	rotation_mtx[4][4];

	rotation_mtx[0][0] = cos(angle);
	rotation_mtx[0][1] = -sin(angle);
	rotation_mtx[0][2] = 0;
	rotation_mtx[0][3] = 0;
	rotation_mtx[1][0] = sin(angle);
	rotation_mtx[1][1] = cos(angle);
	rotation_mtx[1][2] = 0;
	rotation_mtx[1][3] = 0;
	rotation_mtx[2][0] = 0;
	rotation_mtx[2][1] = 0;
	rotation_mtx[2][2] = 1;
	rotation_mtx[2][3] = 0;
	rotation_mtx[3][0] = 0;
	rotation_mtx[3][1] = 0;
	rotation_mtx[3][2] = 0;
	rotation_mtx[3][3] = 1;
	transform_grid(inter, rotation_mtx);
}

void	translation(t_interface *inter, float x, float y, float z)
{
	float	translation_mtx[4][4];

	translation_mtx[0][0] = 1;
	translation_mtx[0][1] = 0;
	translation_mtx[0][2] = 0;
	translation_mtx[0][3] = x;
	translation_mtx[1][0] = 0;
	translation_mtx[1][1] = 1;
	translation_mtx[1][2] = 0;
	translation_mtx[1][3] = y;
	translation_mtx[2][0] = 0;
	translation_mtx[2][1] = 0;
	translation_mtx[2][2] = 1;
	translation_mtx[2][3] = z;
	translation_mtx[3][0] = 0;
	translation_mtx[3][1] = 0;
	translation_mtx[3][2] = 0;
	translation_mtx[3][3] = 1;
	transform_grid(inter, translation_mtx);
}

void	scaling(t_interface *inter, float coefficient_xy, float coefficient_z)
{
	float	scaling_mtx[4][4];

	scaling_mtx[0][0] = coefficient_xy;
	scaling_mtx[0][1] = 0;
	scaling_mtx[0][2] = 0;
	scaling_mtx[0][3] = 0;
	scaling_mtx[1][0] = 0;
	scaling_mtx[1][1] = coefficient_xy;
	scaling_mtx[1][2] = 0;
	scaling_mtx[1][3] = 0;
	scaling_mtx[2][0] = 0;
	scaling_mtx[2][1] = 0;
	scaling_mtx[2][2] = coefficient_z;
	scaling_mtx[2][3] = 0;
	scaling_mtx[3][0] = 0;
	scaling_mtx[3][1] = 0;
	scaling_mtx[3][2] = 0;
	scaling_mtx[3][3] = 1;
	transform_grid(inter, scaling_mtx);
}

void	adjust_distance(t_interface *inter)
{
	float	distance_closest_point;

	distance_closest_point = get_closest_point(inter)->y + inter->distance;
	if (distance_closest_point <= 0)
		translation(inter, 0, -distance_closest_point + 1, 0);
}

void	center(t_interface *inter, float *dx, float *dy)
{
	*dx = get_central_point(inter)->x;
	*dy = get_central_point(inter)->y;
	translation(inter, -(*dx), -(*dy), 0);
}
