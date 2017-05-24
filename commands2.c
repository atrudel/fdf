/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:31:28 by atrudel           #+#    #+#             */
/*   Updated: 2017/02/08 16:11:43 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	escape(t_interface *inter)
{
	destroy_grid(inter);
	mlx_destroy_image(inter->mlx, inter->img);
	mlx_destroy_window(inter->mlx, inter->win);
	exit(0);
}

void	zoom(int keycode, t_interface *inter)
{
	if (keycode == 78)
	{
		inter->scale *= 0.75;
		inter->scale_z *= 0.75;
		scaling(inter, 0.75, 0.75);
	}
	else if (keycode == 69)
	{
		inter->scale *= 1.25;
		inter->scale_z *= 1.25;
		scaling(inter, 1.25, 1.25);
	}
	else if (keycode == 27)
	{
		inter->scale_z *= 0.75;
		scaling(inter, 1, 0.75);
		set_altitudes(inter);
	}
	else if (keycode == 24)
	{
		inter->scale_z *= 1.25;
		scaling(inter, 1, 1.25);
		set_altitudes(inter);
	}
}

void	switch_projection(int keycode, t_interface *inter)
{
	if (keycode == 34)
		inter->projection = ISO;
	else if (keycode == 35)
		inter->projection = LINEAR;
}

void	rotate(int keycode, t_interface *inter)
{
	float	dx;
	float	dy;

	center(inter, &dx, &dy);
	if (keycode == 47)
		rotation(inter, M_PI_4 / 2);
	else
		rotation(inter, -M_PI_4 / 2);
	translation(inter, dx, dy, 0);
}

void	move(int keycode, t_interface *inter)
{
	if (inter->projection == LINEAR)
	{
		if (keycode == 123)
			translation(inter, -10, 0, 0);
		else if (keycode == 124)
			translation(inter, 10, 0, 0);
		else if (keycode == 125)
			translation(inter, 0, -10, 0);
		else if (keycode == 126)
			translation(inter, 0, 10, 0);
	}
	else
	{
		if (keycode == 123)
			translation(inter, -10, -10, 0);
		else if (keycode == 124)
			translation(inter, 10, 10, 0);
		else if (keycode == 125)
			translation(inter, 10, -10, 0);
		else if (keycode == 126)
			translation(inter, -10, 10, 0);
	}
}
