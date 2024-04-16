/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:41:08 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/16 18:57:26 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	create_map(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (data->file[i][0] != '1')
		i++;
	data->len = data->len - i;
	data->map = malloc(sizeof(char *) * (data->len + 1));
	j = 0;
	while (data->file[i] != NULL)
		data->map[j++] = ft_strdup(data->file[i++]);
	data->map[j] = NULL;
	boom_file(data->file);
}

void	get_textures(t_data *data)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	j = 0;
	while(i != 6)
	{
		z = 0;
		if (data->file[j][0] == '1' || data->file[j][0] == '0')
			error_msg("Map Error", data);
		while (is_spaces(data->file[j][z]))
			z++;
		if (data->file[j][z] == 'N' ||  data->file[j][z] == 'S'
		|| data->file[j][z] == 'E' || data->file[j][z] == 'W'
		|| data->file[j][z] == 'C' || data->file[j][z] == 'F')
			i++;
		else
		{
			j++;
			continue ;
		}
		rgb_text(data, j, z);
		j++;
	}
}

void	create_file(t_data *data, char *map)
{
	int		fd;
	size_t		i;
	char	*tmp;

	fd = open(map, O_RDONLY);
	data->file = malloc(sizeof(char *) * (data->len + 1));
	i = 0;
	while (i <= data->len)
	{
		tmp = get_next_line(fd);
		if (!tmp)
		{
			free(tmp);
			break ;
		}
		data->file[i] = ft_strtrim(tmp, "\n");
		free(tmp);
		i++;
	}
	data->file[i] = NULL;
	close(fd);
}

void	get_len(t_data *data, char *map)
{
	int		i;
	int		fd;
	char	*tmp;

	fd = open(map, O_RDONLY);
	if (fd == 1)
		write_error(MAP_INE);
	i = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
		{
			free(tmp);
			break ;
		}
		i++;
		free(tmp);
	}
	close(fd);
	data->len = i;
}

void	get_info(t_data *data, char *file)
{
	if (!valid_map(file))
		write_error(MAP_CHARS);
	get_len(data, file);
	create_file(data, file);
	get_textures(data);
	create_map(data);
}
