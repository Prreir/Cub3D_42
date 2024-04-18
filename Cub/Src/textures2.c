/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:19:57 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/18 14:24:38 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	load_img(t_data *map, t_texture *image, char *path)
{
	int	size;

	size = 64;
	image->ptr = mlx_xpm_file_to_image(map->mlx.ptr, path, &size,
			&size);
	image->addr = mlx_get_data_addr(image->ptr,
			&image->bitpp, &image->length_line, &image->endian);
	return ;
}

void	textures(t_data *data)
{
	if (data->no.path && data->so.path && 
		data->we.path && data->ea.path )
	{
		load_img(data->mlx.ptr, &data->no, data->no.path);
		load_img(data->mlx.ptr, &data->so, data->so.path);
		load_img(data->mlx.ptr, &data->we, data->we.path);
		load_img(data->mlx.ptr, &data->ea, data->ea.path);
	}
}
