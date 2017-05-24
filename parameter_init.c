/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:00:06 by atrudel           #+#    #+#             */
/*   Updated: 2017/02/08 16:05:25 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_z_stats(t_interface *inter)
{
	int	i;
	int	j;

	if (GRID[0][0])
	{
		inter->z_min = GRID[0][0]->z;
		inter->z_max = GRID[0][0]->z;
	}
	i = 0;
	while (i < inter->grid_size_x)
	{
		j = 0;
		while (j < inter->grid_size_y)
		{
			if (GRID[i][j])
			{
				if (GRID[i][j]->z > inter->z_max)
					inter->z_max = GRID[i][j]->z;
				if (GRID[i][j]->z < inter->z_min)
					inter->z_min = GRID[i][j]->z;
			}
			j++;
		}
		i++;
	}
}

void	set_altitudes(t_interface *inter)
{
	int	i;
	int	j;
	int	altitude_range;

	get_z_stats(inter);
	altitude_range = inter->z_max - inter->z_min;
	i = 0;
	while (i < inter->grid_size_x)
	{
		j = 0;
		while (j < inter->grid_size_y)
		{
			if (GRID[i][j])
			{
				if (altitude_range == 0)
					GRID[i][j]->altitude = 1;
				else
					GRID[i][j]->altitude = (float)(GRID[i][j]->z -
											inter->z_min) / altitude_range;
			}
			j++;
		}
		i++;
	}
}

void	set_coordinates(t_interface *inter)
{
	int		i;
	int		j;
	float	central_x;
	float	central_y;

	i = 0;
	j = 0;
	central_x = get_central_point(inter)->x;
	central_y = get_central_point(inter)->y;
	while (i < inter->grid_size_x)
	{
		j = 0;
		while (j < inter->grid_size_y)
		{
			if ((inter->grid)[i][j])
			{
				GRID[i][j]->x = (GRID[i][j]->x - central_x) * inter->scale;
				GRID[i][j]->y = (GRID[i][j]->y - central_y) * inter->scale;
				GRID[i][j]->z = GRID[i][j]->z * inter->scale_z;
			}
			j++;
		}
		i++;
	}
}
