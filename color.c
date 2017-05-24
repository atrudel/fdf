/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:31:20 by atrudel           #+#    #+#             */
/*   Updated: 2017/02/08 16:08:35 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_color(int keycode, t_interface *inter)
{
	if (keycode == 15)
		inter->red += M_PI_4 / 8;
	if (keycode == 11)
		inter->blue += M_PI_4 / 8;
	if (keycode == 5)
		inter->green += M_PI_4 / 8;
}

int		get_color_point(t_interface *inter, t_point *point)
{
	float	coefficient;
	int		color;
	int		mask;

	if (point->color)
		return (point->color);
	coefficient = inter->gradation ? point->altitude : 1;
	if (coefficient < 0.5)
		coefficient += 0.2;
	color = 0;
	mask = (int)(0xFF * coefficient * (0.5 * cos(inter->blue) + 0.5));
	color = color & 0xFFFFFF00;
	color = color | mask;
	mask = (int)(0xFF * coefficient * (0.5 * cos(inter->green) + 0.5));
	mask = mask << 8;
	color = color & 0xFFFF00FF;
	color = color | mask;
	mask = (int)(0xFF * coefficient * (0.5 * cos(inter->red) + 0.5));
	mask = mask << 16;
	color = color & 0x0000FFFF;
	color = color | mask;
	if (color > 0x00FFFFFF)
		color = 0x00FFFFFFFF;
	return (color);
}

int		get_color_component(int color, t_color_component rgb)
{
	unsigned char	component;

	component = color >> (8 * rgb);
	return ((int)component);
}

int		set_color_component(int initial_color, t_color_component rgb, int value)
{
	int	final_color;

	final_color = initial_color;
	if (rgb == BLUE)
	{
		final_color = initial_color & 0x00FFFF00;
		final_color = final_color | value;
	}
	else if (rgb == GREEN)
	{
		final_color = initial_color & 0x00FF00FF;
		final_color = final_color | (value << 8);
	}
	else if (rgb == RED)
	{
		final_color = initial_color & 0x0000FFFF;
		final_color = final_color | (value << 16);
	}
	return (final_color);
}

int		get_color_pixel(t_interface *inter, t_point *p1, t_point *p2,
						float coefficient)
{
	int					color1;
	int					color2;
	int					final_color;
	int					component_value;
	t_color_component	rgb;

	final_color = 0;
	color1 = get_color_point(inter, p1);
	color2 = get_color_point(inter, p2);
	rgb = BLUE;
	while (rgb <= RED)
	{
		component_value = get_color_component(color1, rgb) +
						(int)(coefficient * (get_color_component(color2, rgb)
						- get_color_component(color1, rgb)));
		final_color = set_color_component(final_color, rgb, component_value);
		rgb++;
	}
	return (final_color);
}
