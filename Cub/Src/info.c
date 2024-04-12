/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:01:57 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/11 21:34:05 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
		if (only_spaces(line) == 1)
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

int	is_empty(char *file)
{
	int		value;
	char	*temp;
	int		fd;

	value = 0;
	fd = open(file, O_RDONLY);
	if (!fd)
		return (write_error(MAP_INE));
	temp = get_next_line(fd);
	if (temp == NULL)
		value = 1;
	free(temp);
	close(fd);
	return (value);
}

int	info(t_data *data, char *file)
{
	int		value;
	int		fd;
	char	**textures;
	char	**map;

	value = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1 || is_empty(file) == 1)
		return (write_error(MAP_INE));
	textures = get_textures(fd);
	if (info_textures(data, textures) == 1)
		value = 1;
	// if (value != 1)
	// {
	// 	map = get_map(file, fd);
	// 	if (!parse_map(map, data))
	// 	{
	// 		boom_file(map);
	// 		value = 1;
	// 	}
	// }
	// if (value != 1)
	// 	data->map = map;
	close(fd);
	return (value);
}