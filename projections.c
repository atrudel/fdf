/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:32:46 by atrudel           #+#    #+#             */
/*   Updated: 2017/02/08 16:10:38 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	project_isometric(t_interface *inter)
{
	int		i;
	int		j;
	double	radical3;

	i = 0;
	j = 0;
	radical3 = sqrt(3);
	while (i < inter->grid_size_x)
	{
		j = 0;
		while (j < inter->grid_size_y)
		{
			if ((inter->grid)[i][j])
			{
				GRID[i][j]->screen_x = SIZE_SCREEN_X / 2 + (int)((GRID[i][j]->x
										+ GRID[i][j]->y) * radical3);
				GRID[i][j]->screen_y = SIZE_SCREEN_Y / 2 + (int)((GRID[i][j]->x
										- GRID[i][j]->y) - GRID[i][j]->z);
			}
			j++;
		}
		i++;
	}
}

void	project_linear(t_interface *inter)
{
	int		i;
	int		j;
	float	lf;

	i = -1;
	j = 0;
	lf = 50;
	adjust_distance(inter);
	while (++i < inter->grid_size_x)
	{
		j = 0;
		while (j < inter->grid_size_y)
		{
			if ((inter->grid)[i][j])
			{
				GRID[i][j]->screen_x = (GRID[i][j]->x) * inter->scale * lf /
						(GRID[i][j]->y + inter->distance)
						+ SIZE_SCREEN_X / 2;
				GRID[i][j]->screen_y = -(GRID[i][j]->z - inter->camera_height) *
						inter->scale * lf / (GRID[i][j]->y + inter->distance) +
						inter->focus_height;
			}
			j++;
		}
	}
}
