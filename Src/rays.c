/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:10:07 by lugoncal          #+#    #+#             */
/*   Updated: 2024/03/27 15:10:07 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cast_rays(t_data *data)
{
	int	i;

	data->img = new_img(data->mlx.ptr);
	i = 0;
	while (i < WIDTH)
	{
		init_rays(data, i);
		hit_wall(data);
		distance_to_wall(data, data->map);
		wall_height(data);
		wall_pixel(data);
		draw_vertical_line(data, i);
		i += 1;
	}
	draw_minimap(data);
	mlx_clear_window(data->mlx.ptr, data->mlx.win);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->img.ptr, 0, 0);
}

void	hit_wall(t_data	*data)
{
	if (data->ray.dir_x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side_dist_x = (data->player.start_x - \
		data->ray.map_x) * data->ray.delta_dist_x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side_dist_x = (data->ray.map_x + 1.0f - \
		data->player.start_x) * data->ray.delta_dist_x;
	}
	if (data->ray.dir_y > 0)
	{
		data->ray.step_y = -1;
		data->ray.side_dist_y = (data->player.start_y - \
		data->ray.map_y) * data->ray.delta_dist_y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side_dist_y = (data->ray.map_y + 1.0f - \
		data->player.start_y) * data->ray.delta_dist_y;
	}
}

void	distance_to_wall(t_data *data, char **map)
{
	while (!data->ray.hit)
	{
		if (data->ray.side_dist_x < data->ray.side_dist_y)
		{
			data->ray.side_dist_x += data->ray.delta_dist_x;
			data->ray.map_x += data->ray.step_x;
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_dist_y += data->ray.delta_dist_y;
			data->ray.map_y += data->ray.step_y;
			data->ray.side = 1;
		}
		if (map[data->ray.map_y][data->ray.map_x] == '1')
			data->ray.hit = 1;
	}
}

void	wall_height(t_data *data)
{
	if (!data->ray.side)
		data->ray.perp_wall_dist = data->ray.side_dist_x \
		- data->ray.delta_dist_x;
	else
		data->ray.perp_wall_dist = data->ray.side_dist_y \
		- data->ray.delta_dist_y;
	data->ray.line_height = (int)(HEIGHT / data->ray.perp_wall_dist);
	data->ray.draw_start = -data->ray.line_height / 2 + HEIGHT / 2;
	if (data->ray.draw_start < 0)
		data->ray.draw_start = 0;
	data->ray.draw_end = data->ray.line_height / 2 + HEIGHT / 2;
	if (data->ray.draw_end >= HEIGHT)
		data->ray.draw_end = HEIGHT - 1;
}

void	wall_pixel(t_data *data)
{
	if (!data->ray.side)
		data->ray.wall_x = (int)data->player.start_y + \
		data->ray.perp_wall_dist * data->ray.dir_y;
	else
		data->ray.wall_x = (int)data->player.start_x + \
		data->ray.perp_wall_dist * data->ray.dir_x;
	data->ray.wall_x -= floor(data->ray.wall_x);
	data->ray.tex_x = (int)(data->ray.wall_x * (double)TEXTURE_WIDTH);
	if (!data->ray.side && data->ray.dir_x > 0)
		data->ray.tex_x = TEXTURE_WIDTH - data->ray.tex_x - 1;
	if (data->ray.side && data->ray.dir_y < 0)
		data->ray.tex_x = TEXTURE_WIDTH - data->ray.tex_x - 1;
	data->ray.step = 1.0 * TEXTURE_HEIGHT / data->ray.line_height;
	data->ray.tex_pos = (data->ray.draw_start - (HEIGHT / 2) + \
	data->ray.line_height / 2) * data->ray.step;
}
