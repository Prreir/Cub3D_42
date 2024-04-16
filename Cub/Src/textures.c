/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:07:54 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/16 12:58:00 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	loop_textures(t_data *data, int j, int z)
{
	int	i;
	int	start;

	i = z + 2;
	while (data->file[j][i])
	{
		if (ft_isalpha(data->file[j][i]) || data->file[j][i] == '.'
			|| data->file[j][i] == '/' || data->file[j][i] == '.' || data->file[j][i] == '/')
		{
			start = i;
			while (data->file[j][i] && !is_spaces(data->file[j][i]) && data->file[j][i] != '\n')
				i++;
			if (data->file[j][z] == 'N')
				data->no.path = ft_substr(data->file[j], start, i - start);
			else if (data->file[j][z] == 'S')
				data->so.path = ft_substr(data->file[j], start, i - start);
			else if (data->file[j][z] == 'W')
				data->we.path = ft_substr(data->file[j], start, i - start);
			else
				data->ea.path = ft_substr(data->file[j], start, i - start);
			break ;
		}
		i++;
	}
}

void	init_textures(t_data *data, int j, int z)
{
	if (data->file[j][z] == 'N' || data->file[j][z] == 'S')
	{
		if (data->file[j][z + 1] == 'O')
			loop_textures(data, j, z);
	}
	else if (data->file[j][z] == 'W' && data->file[j][z + 1] == 'E')
		loop_textures(data, j, z);
	else if (data->file[j][z] == 'E' && data->file[j][z + 1] == 'A')
		loop_textures(data, j, z);
}

void	to_hex(t_data *data)
{
	int				r;
	int				g;
	int				b;

	r = data->ceiling_rgb[0];
	g = data->ceiling_rgb[1];
	b = data->ceiling_rgb[2];
	data->ceiling_hex = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	r = data->floor_rgb[0];
	g = data->floor_rgb[1];
	b = data->floor_rgb[2];
	data->floor_hex = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void	init_rgb(t_data *data, int j, int z)
{
	int		index;
	int		start;
	char	*temp;
	int		i;

	index = 0;
	i = z;
	while (data->file[j][++z] && index < 3)
	{
		if (ft_isdigit(data->file[j][z]))
		{
			start = z;
			while (ft_isdigit(data->file[j][z]))
				z++;
			temp = ft_substr(data->file[j], start, z - start);
			if (data->file[j][i] == 'C')
				data->ceiling_rgb[index++] = ft_atoi(temp);
			else if (data->file[j][i] == 'F')
				data->floor_rgb[index++] = ft_atoi(temp);
			free(temp);
		}
	}
	if (index == 2)
		error_msg("Missing RGB.", data);
	to_hex(data);
}

void	rgb_text(t_data *data, int j, int z)
{
	if (data->file[j][z] == 'C' || data->file[j][z] == 'F')
		init_rgb(data, j, z);
	else if (data->file[j][z] == 'N' || data->file[j][z] == 'S'
		|| data->file[j][z] == 'E' || data->file[j][z] == 'W')
		init_textures(data, j, z);
}