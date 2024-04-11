/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:18:01 by lugoncal          #+#    #+#             */
/*   Updated: 2024/03/27 16:18:01 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_rays(t_data *data, int i)
{
	data->ray.camera_x = 2 * i / (double)WIDTH - 1;
	data->ray.dir_x = data->player.dirx + data->player.planex \
	* data->ray.camera_x;
	data->ray.dir_y = data->player.diry + data->player.planey \
	* data->ray.camera_x;
	data->ray.map_x = (int)data->player.start_x;
	data->ray.map_y = (int)data->player.start_y;
	data->ray.delta_dist_x = fabs(1 / data->ray.dir_x);
	data->ray.delta_dist_y = fabs(1 / data->ray.dir_y);
	data->ray.hit = 0;
}

void	draw_vertical_line(t_data *data, int i)
{
	int	y;

	y = -1;
	while (++y < data->ray.draw_start)
	{
		put_pixel_in_canvas(&data->img, i, y, create_trgb(256, \
			data->ceiling_rgb[0], data->ceiling_rgb[1], data->ceiling_rgb[2]));
	}
	y = data->ray.draw_start;
	while (y < data->ray.draw_end)
	{
		data->ray.tex_y = (int)data->ray.tex_pos & (TEXTURE_HEIGHT - 1);
		data->ray.tex_pos += data->ray.step;
		put_pixel_in_canvas(&data->img, i, y, get_color(data));
		y += 1;
	}
	y = data->ray.draw_end;
	while (y < HEIGHT)
	{
		put_pixel_in_canvas(&data->img, i, y, create_trgb(256, \
			data->floor_rgb[0], data->floor_rgb[1], data->floor_rgb[2]));
		y += 1;
	}
}

void	draw_square(t_texture *img, int x, int y, int color)
{
	size_t	i;
	size_t	j;

	i = MINIMAP_SQUARES_PADDING;
	while (i < 4 + MINIMAP_SQUARES_PADDING)
	{
		j = MINIMAP_SQUARES_PADDING;
		while (j < 4 + MINIMAP_SQUARES_PADDING)
		{
			put_pixel_in_canvas(img, (x * 8 + i), (y * 8 + j), color);
			j += 1;
		}
		i += 1;
	}
}

void	draw_minimap(t_data *data)
{
	size_t	x;
	size_t	y;
	size_t	map_length;

	y = 0;
	while (y < data->len)
	{
		x = 0;
		map_length = ft_strlen(data->map[y]);
		while (x < map_length)
		{
			if (x == (size_t)data->player.start_x && y == \
				(size_t)data->player.start_y)
				draw_square(&data->img, x, y, YELLOW);
			else if (data->map[y][x] == '1')
				draw_square(&data->img, x, y, BLACK);
			x += 1;
		}
		y += 1;
	}
}
