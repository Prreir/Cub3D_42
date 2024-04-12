/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:01:57 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/12 22:28:34 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_info2(t_map *map, char *line, int j, int i)
{
	char	*line2;

	if (line[0] == '\n')
	{
		free(line);
		return (1);
	}
	line2 = ft_strdup(line);
	map->map[i] = ft_strtrim(line2, "\n");
	while (line[j])
	{
		if (line[j] == 'N' || line[j] == 'S'
			|| line[j] == 'W' || line[j] == 'E')
		{
			map->player.pos_x = j + 0.5;
			map->player.pos_y = i + 0.5;
			map->player.dir = line[j];
			map->map[i][j] = '0';
		}
		j++;
	}
	free(line2);
	return (0);
}

void	map_info(char *file, t_data *data)
{
	int		i;
	int		j;
	int		fd;
	char	*tmp;

	data->map = malloc(sizeof(char *) * (data->len + 1));
	fd = open(file, O_RDONLY);
	init_textures(data, fd);
	i = 0;
	while (1)
	{
		j = 0;
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		if (map_info2(data, tmp, j, i) == 1)
			continue ;
		free(tmp);
		i++;
	}
	data->map[i] = NULL;
	close(fd);
}

int	valid(char *file)
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
				return (1);
			break ;
		}
		if (line[0] != '\n' && !valid_char(line[0]))
		{
			free(line);
			return (1);
		}
		free(line);
		i++;
	}
	return (close(fd), 0);
}

int info(t_data *data, char *file)
{
	if (valid(file) == 1)
	{
		write_error(INV_MAP);
		return (1);
	}	
	len_file(file, data);
	map_info(file, data);
	return (0);
}
