/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:43:25 by atrudel           #+#    #+#             */
/*   Updated: 2017/02/08 16:16:49 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	adjust_linear_projection(int keycode, t_interface *inter)
{
	if (inter->projection == LINEAR)
	{
		if (keycode == 116)
			inter->camera_height += 5;
		else if (keycode == 121)
			inter->camera_height -= 5;
		else if (keycode == 115)
			inter->focus_height -= 20;
		else if (keycode == 119)
			inter->focus_height += 20;
	}
}

int		keyboard(int keycode, t_interface *inter)
{
	float dx;
	float dy;

	if (keycode == 116 || keycode == 121 || keycode == 115 || keycode == 119)
		adjust_linear_projection(keycode, inter);
	else if (keycode == 53 || keycode == 12)
		escape(inter);
	else if (keycode == 15 || keycode == 5 || keycode == 11)
		change_color(keycode, inter);
	else if (keycode == 49)
		inter->gradation = inter->gradation ? 0 : 1;
	else if (keycode >= 123 && keycode <= 126)
		move(keycode, inter);
	else if (keycode == 47 || keycode == 43)
		rotate(keycode, inter);
	else if (keycode == 8)
		center(inter, &dx, &dy);
	else if (keycode == 78 || keycode == 69 || keycode == 24 || keycode == 27)
		zoom(keycode, inter);
	else if (keycode == 34 || keycode == 35)
		switch_projection(keycode, inter);
	mlx_do_key_autorepeaton(inter->mlx);
	return (0);
}
