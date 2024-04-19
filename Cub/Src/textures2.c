/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:19:57 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/19 10:50:22 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_texture_img(t_data *map, t_texture *image, char *path)
{
	int	size;

	image->ptr = mlx_xpm_file_to_image(map->mlx.ptr, path, &size, &size);
	image->addr = mlx_get_data_addr(image->ptr,
			&image->bitpp, &image->length_line, &image->endian);
	return ;
}

void	textures(t_data *data)
{
	init_texture_img(data, &data->no, data->no.path);
	init_texture_img(data, &data->so, data->so.path);
	init_texture_img(data, &data->we, data->we.path);
	init_texture_img(data, &data->ea, data->ea.path);
}
