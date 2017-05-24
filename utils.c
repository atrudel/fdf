/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:33:12 by atrudel           #+#    #+#             */
/*   Updated: 2017/02/07 16:56:17 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*get_central_point(t_interface *inter)
{
	int i;
	int j;
	int decalage;

	i = inter->grid_size_x / 2;
	j = inter->grid_size_y / 2;
	decalage = 0;
	while (decalage <= inter->grid_size_x / 2 &&
			decalage <= inter->grid_size_y / 2)
	{
		if (GRID[i + decalage][j + decalage])
			return (GRID[i + decalage][j + decalage]);
		decalage++;
	}
	ft_putstr_fd("Failed to find the central point\n", 2);
	exit(1);
}

t_point	*get_closest_point(t_interface *inter)
{
	int		i;
	int		j;
	t_point	*closest_point;

	closest_point = get_central_point(inter);
	i = 0;
	j = 0;
	while (i < inter->grid_size_x)
	{
		j = 0;
		while (j < inter->grid_size_y)
		{
			if ((inter->grid)[i][j])
			{
				if (GRID[i][j]->y < closest_point->y)
					closest_point = GRID[i][j];
			}
			j++;
		}
		i++;
	}
	return (closest_point);
}

void	multiply_mtx(t_point *point, float transf_mtx[4][4],
							float (*result_mtx)[4])
{
	(*result_mtx)[0] = point->x * transf_mtx[0][0] + point->y * transf_mtx[0][1]
						+ point->z * transf_mtx[0][2] + 1 * transf_mtx[0][3];
	(*result_mtx)[1] = point->x * transf_mtx[1][0] + point->y * transf_mtx[1][1]
						+ point->z * transf_mtx[1][2] + 1 * transf_mtx[1][3];
	(*result_mtx)[2] = point->x * transf_mtx[2][0] + point->y * transf_mtx[2][1]
						+ point->z * transf_mtx[2][2] + 1 * transf_mtx[2][3];
	(*result_mtx)[3] = point->x * transf_mtx[3][0] + point->y * transf_mtx[3][1]
						+ point->z * transf_mtx[3][2] + 1 * transf_mtx[3][3];
}
