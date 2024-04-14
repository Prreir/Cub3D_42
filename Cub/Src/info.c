/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:01:57 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/14 20:51:04 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_info2(t_data *data, char *tmp, int j, int i)
{
	char	*line;

	if (tmp[0] == '\n')
	{
		free(tmp);
		return (1);
	}
	line = ft_strdup(tmp);
	data->map[i] = ft_strtrim(line, "\n");
	while (tmp[j])
	{
		if (tmp[j] == 'N' || tmp[j] == 'S'
			|| tmp[j] == 'W' || tmp[j] == 'E')
		{
			data->player.start_x = j + 0.5;
			data->player.start_x = i + 0.5;
			data->player.orientation = tmp[j];
			data->map[i][j] = '0';
		}
		j++;
	}
	free(line);
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
	textures_info(data, fd);
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
