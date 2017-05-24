/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:31:46 by atrudel           #+#    #+#             */
/*   Updated: 2017/02/08 16:16:15 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	traverse_grid(t_interface *inter,
						void (*f)(t_point *, t_interface *, void *), void *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < inter->grid_size_x)
	{
		j = 0;
		while (j < inter->grid_size_y)
		{
			if (GRID[i][j])
				f(GRID[i][j], inter, data);
			j++;
		}
		i++;
	}
}

void	paste_grid(t_interface *inter)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < inter->grid_size_x)
	{
		j = 0;
		while (j < inter->grid_size_y)
		{
			if (GRID[i][j] && GRID[i][j + 1])
				draw_line(inter, GRID[i][j], GRID[i][j + 1]);
			if (GRID[i][j] && GRID[i + 1][j])
				draw_line(inter, GRID[i][j], GRID[i + 1][j]);
			j++;
		}
		i++;
	}
}

void	transform_grid(t_interface *inter, float transf_mtx[4][4])
{
	int		i;
	int		j;
	float	resultant_mtx[4];

	i = 0;
	j = 0;
	while (i < inter->grid_size_x)
	{
		j = 0;
		while (j < inter->grid_size_y)
		{
			if ((inter->grid)[i][j])
			{
				multiply_mtx(GRID[i][j], transf_mtx, &resultant_mtx);
				GRID[i][j]->x = resultant_mtx[0];
				GRID[i][j]->y = resultant_mtx[1];
				GRID[i][j]->z = resultant_mtx[2];
			}
			j++;
		}
		i++;
	}
}

void	destroy_grid(t_interface *inter)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < inter->grid_size_x)
	{
		j = 0;
		while (j < inter->grid_size_y)
		{
			free(GRID[i][j]);
			j++;
		}
		free(GRID[i]);
		i++;
	}
	free(GRID);
}
