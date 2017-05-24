/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:15:23 by atrudel           #+#    #+#             */
/*   Updated: 2017/02/07 18:45:22 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*parse_point(char *str, int i, int j)
{
	t_point	*new_point;
	char	*color;

	if (!(new_point = (t_point *)ft_memalloc(sizeof(t_point))))
	{
		ft_putstr_fd("Memory allocation failed during parsing\n", 2);
		exit(1);
	}
	if ((color = ft_strchr(str, ',')))
		new_point->color = ft_atoi_hexa(color);
	new_point->x = i;
	new_point->y = j;
	new_point->z = ft_atoi(str);
	new_point->initial_z = ft_atoi(str);
	return (new_point);
}

t_point		**parse_line(t_interface *inter, char *line, int i)
{
	char	**elements;
	t_point	**point_line;
	int		j;

	elements = ft_strsplit(line, ' ');
	if (!(point_line = (t_point **)ft_memalloc(sizeof(*point_line) *
												(inter->grid_size_y + 1))))
	{
		ft_putstr_fd("Memory allocation failed during parsing\n", 2);
		exit(1);
	}
	j = 0;
	while (elements[j] && i < inter->grid_size_x)
	{
		point_line[j] = parse_point(elements[j], i, j);
		free(elements[j]);
		j++;
	}
	free(elements);
	return (point_line);
}

t_point		***make_grid(t_interface *inter, int fd)
{
	t_point	***new_grid;
	int		i;
	char	*line;

	if (!(new_grid = (t_point ***)ft_memalloc(sizeof(*new_grid) *
											(inter->grid_size_x + 1))))
	{
		ft_putstr_fd("Memory allocation failed during parsing\n", 2);
		exit(1);
	}
	i = 0;
	while (i <= inter->grid_size_x)
	{
		get_next_line(fd, &line);
		new_grid[i] = parse_line(inter, line, i);
		free(line);
		i++;
	}
	return (new_grid);
}

void		get_dimensions(t_interface *inter, const char *file_name)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	**points;

	if (!(fd = open(file_name, O_RDONLY)))
	{
		perror(0);
		exit(1);
	}
	i = 0;
	while (get_next_line(fd, &line) > 0 && ++i)
	{
		points = ft_strsplit(line, ' ');
		free(line);
		j = 0;
		while (points[j])
			j++;
		if (j > inter->grid_size_y)
			inter->grid_size_y = j;
		free(points);
	}
	inter->grid_size_x = (j > 0 ? i : i - 1);
	close(fd);
}

void		parse(int argc, const char **argv, t_interface *inter)
{
	int		fd;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf <file_name>\n", 2);
		exit(1);
	}
	get_dimensions(inter, argv[1]);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		perror(0);
		exit(1);
	}
	inter->grid = make_grid(inter, fd);
	close(fd);
}
