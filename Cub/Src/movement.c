/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassa-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:51:56 by mmassa-r          #+#    #+#             */
/*   Updated: 2024/03/20 12:51:57 by mmassa-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_up(t_data *data)
{
	float	target_y_xaxis;
	float	target_x_xaxis;
	float	target_y_yaxis;
	float	target_x_yaxis;

	target_y_xaxis = data->player.start_y;
	target_x_xaxis = data->player.start_x + data->player.dirx * MARGIN;
	target_y_yaxis = data->player.start_y - data->player.diry * MARGIN;
	target_x_yaxis = data->player.start_x;
	if (data->map[(int)target_y_xaxis][(int)target_x_xaxis] != '1')
		data->player.start_x += data->player.dirx * MOVESPEED;
	if (data->map[(int)target_y_yaxis][(int)target_x_yaxis] != '1')
		data->player.start_y -= data->player.diry * MOVESPEED;
}

void	move_left(t_data *data)
{
	float	target_y_xaxis;
	float	target_x_xaxis;
	float	target_y_yaxis;
	float	target_x_yaxis;

	target_y_xaxis = data->player.start_y;
	target_x_xaxis = data->player.start_x - data->player.diry * MARGIN;
	target_y_yaxis = data->player.start_y - data->player.dirx * MARGIN;
	target_x_yaxis = data->player.start_x;
	if (data->map[(int)target_y_xaxis][(int)target_x_xaxis] != '1')
		data->player.start_x -= data->player.diry * MOVESPEED;
	if (data->map[(int)target_y_yaxis][(int)target_x_yaxis] != '1')
		data->player.start_y -= data->player.dirx * MOVESPEED;
}

void	move_down(t_data *data)
{
	float	target_y_xaxis;
	float	target_x_xaxis;
	float	target_y_yaxis;
	float	target_x_yaxis;

	target_y_xaxis = data->player.start_y;
	target_x_xaxis = data->player.start_x - data->player.dirx * MARGIN;
	target_y_yaxis = data->player.start_y + data->player.diry * MARGIN;
	target_x_yaxis = data->player.start_x;
	if (data->map[(int)target_y_xaxis][(int)target_x_xaxis] != '1')
		data->player.start_x -= data->player.dirx * MOVESPEED;
	if (data->map[(int)target_y_yaxis][(int)target_x_yaxis] != '1')
		data->player.start_y += data->player.diry * MOVESPEED;
}

void	move_right(t_data *data)
{
	float	target_y_xaxis;
	float	target_x_xaxis;
	float	target_y_yaxis;
	float	target_x_yaxis;

	target_y_xaxis = data->player.start_y;
	target_x_xaxis = data->player.start_x + data->player.diry * MARGIN;
	target_y_yaxis = data->player.start_y + data->player.dirx * MARGIN;
	target_x_yaxis = data->player.start_x;
	if (data->map[(int)target_y_xaxis][(int)target_x_xaxis] != '1')
		data->player.start_x += data->player.diry * MOVESPEED;
	if (data->map[(int)target_y_yaxis][(int)target_x_yaxis] != '1')
		data->player.start_y += data->player.dirx * MOVESPEED;
}

void	player_movement(t_data *data)
{
	if (data->movements[0])
		move_up(data);
	else if (data->movements[1])
		move_left(data);
	else if (data->movements[2])
		move_down(data);
	else if (data->movements[3])
		move_right(data);
}
