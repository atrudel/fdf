/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:31:54 by atrudel           #+#    #+#             */
/*   Updated: 2017/02/08 16:13:11 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_erase(t_interface *inter)
{
	ft_bzero(inter->img_addr, inter->bits_per_pixel / 8
			* SIZE_SCREEN_X * SIZE_SCREEN_Y);
}

void	img_pixel_put(t_interface *inter, int x, int y, int color)
{
	char			*pixel_addr;
	int				bytes_per_pixel;
	unsigned int	color_code;
	int				i;
	int				j;

	if (x >= 0 && x < SIZE_SCREEN_X && y >= 0 && y < SIZE_SCREEN_Y)
	{
		bytes_per_pixel = inter->bits_per_pixel / 8;
		pixel_addr = inter->img_addr;
		pixel_addr += y * inter->size_line;
		pixel_addr += x * bytes_per_pixel;
		color_code = mlx_get_color_value(inter->mlx, color);
		i = 0;
		j = inter->endian ? bytes_per_pixel : 0;
		while (i < bytes_per_pixel)
		{
			ft_memcpy(pixel_addr + i, (char *)&color_code + j, 1);
			i++;
			inter->endian ? j-- : j++;
		}
	}
}
