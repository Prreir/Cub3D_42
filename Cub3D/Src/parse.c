/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:51:06 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/15 14:19:23 by lugoncal         ###   ########.fr       */
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
		line = ft_strtrim(get_next_line(fd), "\n");
		map[i] = line;
		free(line);
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
	i = -1;
	while (++i < 6)
	{
		line = ft_strtrim(get_next_line(fd), "\n");
		if (line[0] == '1' || line[0] == '0')
		{
			finish_gnl(line, fd);
			error_msg("Map can't come first.", NULL);
		}
		if (only_spaces(line))
		{
			free(line);
			continue ;
		}
		scene[i] = line;
		free(line);
	}
	scene[i] = NULL;
	free(get_next_line(fd));
	return (scene);
}

int	valid_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E'
		|| c == 'F' || c == 'C' || c == '1' || is_spaces(c))
		return (1);
	return (0);
}

bool	valid_parse(char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			if (i == 0)
				return (false);
			break ;
		}
		if (line[0] != '\n' && !valid_char(line[0]))
		{
			free(line);
			return (false);
		}
		free(line);
		i++;
	}
	return (close(fd), true);
}

bool	parse(t_data *data, char *file)
{
	bool	value;
	int		fd;
	char	**textures;
	char	**map;

	value = true;
	if (!valid_parse(file))
		return(write_error(INV_MAP));
	fd = open(file, O_RDONLY);
	textures = get_textures(fd);
	int	i;
	i = -1;
	while (textures[++i] != NULL)
		printf("%s\n", textures[i]);
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
