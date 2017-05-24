/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:32:10 by atrudel           #+#    #+#             */
/*   Updated: 2017/02/08 16:17:53 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_messages1(t_interface *inter)
{
	if (inter->projection == ISO)
		mlx_string_put(inter->mlx, inter->win, 0, 0, 0x0000FFFF,
						"Isometric projection");
	else
		mlx_string_put(inter->mlx, inter->win, 0, 0, 0x0000FFFF,
						"Perspective projection");
}

void	print_messages2(t_interface *inter)
{
	char	*string;

	string = ft_itoa((int)inter->scale);
	mlx_string_put(inter->mlx, inter->win, 0, 20, 0x00FF0000, "Scale: ");
	mlx_string_put(inter->mlx, inter->win, 100, 20, 0x00FFFFFF, string);
	ft_strdel(&string);
	string = ft_itoa((int)inter->scale_z);
	mlx_string_put(inter->mlx, inter->win, 0, 40, 0x00FF0000, "Z-scale: ");
	mlx_string_put(inter->mlx, inter->win, 100, 40, 0x00FFFFFF, string);
	ft_strdel(&string);
	string = ft_itoa((int)(100 * (0.5 + 0.5 * cos(inter->red))));
	mlx_string_put(inter->mlx, inter->win, 0, 60, 0x00FF0000, "Red: ");
	mlx_string_put(inter->mlx, inter->win, 100, 60, 0x00FFFFFF, string);
	ft_strdel(&string);
	string = ft_itoa((int)(100 * (0.5 + 0.5 * cos(inter->blue))));
	mlx_string_put(inter->mlx, inter->win, 0, 80, 0x00FF0000, "Blue: ");
	mlx_string_put(inter->mlx, inter->win, 100, 80, 0x00FFFFFF, string);
	ft_strdel(&string);
	string = ft_itoa((int)(100 * (0.5 + 0.5 * cos(inter->green))));
	mlx_string_put(inter->mlx, inter->win, 0, 100, 0x00FF0000, "Green: ");
	mlx_string_put(inter->mlx, inter->win, 100, 100, 0x00FFFFFF, string);
	ft_strdel(&string);
}

int		display(void *inter)
{
	img_erase((t_interface *)inter);
	if (((t_interface *)inter)->projection == ISO)
		project_isometric(inter);
	else
		project_linear(inter);
	paste_grid((t_interface *)inter);
	mlx_put_image_to_window(((t_interface *)inter)->mlx,
							((t_interface *)inter)->win,
							((t_interface *)inter)->img, 0, 0);
	print_messages1(inter);
	print_messages2(inter);
	return (0);
}

int		main(int argc, const char **argv)
{
	t_interface	inter;

	ft_bzero(&inter, sizeof(inter));
	inter.mlx = mlx_init();
	inter.win = mlx_new_window(inter.mlx, SIZE_SCREEN_X, SIZE_SCREEN_Y, "fdf");
	mlx_hook(inter.win, 2, 1L << 0, keyboard, &inter);
	inter.img = mlx_new_image(inter.mlx, SIZE_SCREEN_X, SIZE_SCREEN_Y);
	inter.img_addr = mlx_get_data_addr(inter.img, &inter.bits_per_pixel,
										&inter.size_line, &inter.endian);
	mlx_loop_hook(inter.mlx, display, &inter);
	parse(argc, argv, &inter);
	set_altitudes(&inter);
	inter.scale = (double)SIZE_SCREEN_X / (double)inter.grid_size_x / 4;
	inter.scale_z = inter.scale;
	inter.distance = inter.grid_size_y * inter.scale;
	inter.focus_height = SIZE_SCREEN_Y / 2;
	set_coordinates(&inter);
	inter.camera_height = inter.z_max * 5;
	inter.gradation = 1;
	mlx_put_image_to_window(inter.mlx, inter.win, inter.img, 0, 0);
	mlx_loop(inter.mlx);
	return (0);
}
