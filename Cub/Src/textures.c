/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:07:54 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/19 13:47:35 by lugoncal         ###   ########.fr       */
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
			|| data->file[j][i] == '/')
		{
			start = i;
			while (data->file[j][i] && !is_spaces(data->file[j][i]) \
				&& data->file[j][i] != '\n')
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

void	init_rgb(t_data *data, int *rgb, int j, int z)
{
	int		index;
	int		start;
	char	*tmp;

	index = 0;
	while (data->file[j][z++] && index < 3)
	{
		if (ft_isdigit(data->file[j][z]))
		{
			start = z;
			while (ft_isdigit(data->file[j][z]))
				z++;
			tmp = ft_substr(data->file[j], start, z - start);
			rgb[index] = ft_atoi(tmp);
			free(tmp);
			index++;
		}
	}
}

void	rgb_text(t_data *data, int j, int z)
{
	if (data->file[j][z] == 'C')
	{
		if (!check_rgb(data, j, z))
			error_msg("RGB ERROR", data);
		init_rgb(data, data->ceiling_rgb, j, z);
	}
	else if (data->file[j][z] == 'F')
	{
		if (!check_rgb(data, j, z))
			error_msg("RGB ERROR", data);
		init_rgb(data, data->floor_rgb, j, z);
	}
	if ((data->file[j][z] == 'N' && data->no.path == NULL) || 
		(data->file[j][z] == 'S' && data->so.path == NULL) || 
		(data->file[j][z] == 'W' && data->we.path == NULL) || 
		(data->file[j][z] == 'E' && data->ea.path == NULL))
		init_textures(data, j, z);
	else if ((data->file[j][z] == 'N' && data->no.path != NULL) || 
		(data->file[j][z] == 'S' && data->so.path != NULL) || 
		(data->file[j][z] == 'W' && data->we.path != NULL) || 
		(data->file[j][z] == 'E' && data->ea.path != NULL))
		error_msg("Texture Dup", data);
}
