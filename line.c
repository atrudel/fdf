/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:32:01 by atrudel           #+#    #+#             */
/*   Updated: 2017/02/08 16:18:37 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_horiz(t_interface *inter, t_point *p1, t_point *p2)
{
	int x;
	int y;
	int dx;
	int dy;
	int error;

	dx = p2->screen_x - p1->screen_x;
	dy = p2->screen_y - p1->screen_y;
	x = p1->screen_x;
	y = p1->screen_y;
	error = 0;
	while (x <= p2->screen_x)
	{
		img_pixel_put(inter, x, y, get_color_pixel(inter, p1, p2,
					(float)(x - p1->screen_x) / dx));
		error += ABS(dy);
		if (error >= dx)
		{
			dy >= 0 ? y++ : y--;
			error -= dx;
		}
		x++;
	}
}

void	draw_line_vertic(t_interface *inter, t_point *p1, t_point *p2)
{
	int x;
	int y;
	int dx;
	int dy;
	int error;

	dx = p2->screen_x - p1->screen_x;
	dy = p2->screen_y - p1->screen_y;
	x = p1->screen_x;
	y = p1->screen_y;
	error = 0;
	while (y <= p2->screen_y)
	{
		img_pixel_put(inter, x, y, get_color_pixel(inter, p1, p2,
					(float)(y - p1->screen_y) / dy));
		error += ABS(dx);
		if (error >= dy)
		{
			dx >= 0 ? x++ : x--;
			error -= dy;
		}
		y++;
	}
}

void	draw_line(t_interface *inter, t_point *p1, t_point *p2)
{
	int dx;
	int dy;

	dx = p2->screen_x - p1->screen_x;
	dy = p2->screen_y - p1->screen_y;
	if (ABS(dx) >= ABS(dy))
	{
		if (dx >= 0)
			draw_line_horiz(inter, p1, p2);
		else
			draw_line_horiz(inter, p2, p1);
	}
	else
	{
		if (dy >= 0)
			draw_line_vertic(inter, p1, p2);
		else
			draw_line_vertic(inter, p2, p1);
	}
}
