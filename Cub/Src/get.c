/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:41:08 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/15 17:43:52 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	create_map(t_data *data)
{
	size_t	i;
	size_t	j;

	data->len = data->len - 8;
	data->map = malloc(sizeof(char *) * (data->len + 1));
	i = 0;
	j = 8;
	while (i <= data->len)
		data->map[i++] = data->file[j++];
}

// void	get_textures(t_data *data)
// {
// 	if (strncmp(data->file[0], "NO ", 3) == 0)
// 		data->no = ft_strtrim(data->file[0], "NO ");
// 	if (strncmp(data->file[1], "SO ", 3) == 0)
// 		data->so = ft_strtrim(data->file[1], "SO ");
// 	if (strncmp(data->file[2], "WE ", 3) == 0)
// 		data->we = ft_strtrim(data->file[2], "WE ");
// 	if (strncmp(data->file[3], "EA ", 3) == 0)
// 		data->ea = ft_strtrim(data->file[3], "EA ");
	// if (strncmp(data->file[5], "F ", 2) == 0)
	// 	data->mlx.floor = ft_strtrim(data->file[5], "F ");
	// if (strncmp(data->file[6], "C ", 2) == 0)
	// 	data->mlx.ceiling = ft_strtrim(data->file[6], "C ");
	// rgb_color(data->mlx.floor, data->mlx.floor_rgb);
	// rgb_color(data->mlx.ceiling, data->mlx.ceiling_rgb);
// }

void	create_file(t_data *data, char *map)
{
	int		fd;
	size_t		i;
	char	*tmp;

	fd = open(map, O_RDONLY);
	data->file = malloc(sizeof(char *) * (data->len + 1));
	i = -1;
	while (++i <= data->len)
	{
		tmp = get_next_line(fd);
		if (!tmp)
		{
			free(tmp);
			break ;
		}
		data->file[i] = ft_strtrim(tmp, "\n");
		free(tmp);
	}
	close(fd);
}

void	get_len(t_data *data, char *map)
{
	int		i;
	int		fd;
	char	*tmp;

	fd = open(map, O_RDONLY);
	if (fd == 1)
		write_error(ERROR_OP);
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
		write_error(INV_CHARS);
	get_len(data, file);
	create_file(data, file);
	// get_textures(data);
	// if (data->mlx.no_file == NULL || data->mlx.so_file == NULL || 
	// 	data->mlx.we_file == NULL || data->mlx.floor == NULL || 
	// 	data->mlx.ea_file == NULL || data->mlx.ceiling == NULL)
	// 	error_msg(TEXT_INV, data);
	create_map(data);
}
