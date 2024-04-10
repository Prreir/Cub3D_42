/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:51:06 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/10 11:45:07 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

size_t	get_lines(char *file)
{
	int		fd;
	size_t	i;
	size_t	count;
	char	*line;

	fd = open(file, O_RDONLY);
	i = 0;
	count = 0;
	line = get_next_line(fd);
	while (i < 6)
	{
		free(line);
		line = get_next_line(fd);
		if (!only_spaces(line))
			i += 1;
	}
	while (line)
	{
		if (!only_spaces(line))
			count += 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**get_map(char *file, int fd)
{
	size_t	i;
	size_t	lines;
	char	**map;
	char	*line;

	lines = get_lines(file);
	map = malloc((lines + 1) * sizeof(char *));
	i = 0;
	while (i < lines)
	{
		line = trim_free(get_next_line(fd), "\n");
		map[i] = line;
		i += 1;
	}
	map[i] = NULL;
	return (map);
}

char	**get_textures(int fd)
{
	char	**scene;
	size_t	i;
	char	*line;

	scene = malloc((6 + 1) * sizeof(char *));
	i = 0;
	while (i < 6)
	{
		line = trim_free(get_next_line(fd), "\n");
		if (only_spaces(line))
		{
			free(line);
			continue ;
		}
		scene[i] = line;
		i += 1;
	}
	scene[i] = NULL;
	free(get_next_line(fd));
	return (scene);
}

bool	is_empty(char *file)
{
	bool	return_value;
	char	*temp;
	int		fd;

	return_value = false;
	fd = open(file, O_RDONLY);
	if (!fd)
		return (write_error(MAP_INE));
	temp = get_next_line(fd);
	if (temp == NULL)
		return_value = true;
	free(temp);
	close(fd);
	return (return_value);
}

bool	parse(t_data *data, char *file)
{
	bool	value;
	int		fd;
	char	**textures;
	char	**map;

	value = true;
	fd = open(file, O_RDONLY);
	if (fd == -1 || is_empty(file))
		return (write_error(MAP_INE));
	textures = get_textures(fd);
	if (!parse_textures(data, textures))
		value = false;
	if (value != false)
	{
		map = get_map(file, fd);
		if (!parse_map(map, data))
		{
			boom_file(map);
			value = false;
		}
	}
	if (value != false)
		data->map = map;
	close(fd);
	return (value);
}