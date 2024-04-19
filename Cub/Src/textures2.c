/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:19:57 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/19 14:00:09 by lugoncal         ###   ########.fr       */
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

void	check_xpm(char *path, t_data *data)
{
	size_t	id;

	id = ft_strlen(path) - 4;
	if (!check_cmp(&path[id], ".xpm"))
		error_msg("Not XPM", data);
}

void	textures(t_data *data)
{
	check_xpm(data->no.path, data);
	check_xpm(data->so.path, data);
	check_xpm(data->we.path, data);
	check_xpm(data->ea.path, data);
	init_texture_img(data, &data->no, data->no.path);
	init_texture_img(data, &data->so, data->so.path);
	init_texture_img(data, &data->we, data->we.path);
	init_texture_img(data, &data->ea, data->ea.path);
}
