/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:01:33 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/10 12:05:35 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	north_pov(t_data *data)
{
	data->player.planex = 0.66;
	data->player.planey = 0;
	data->player.dirx = 0.0f;
	data->player.diry = 1.0f;
}

static void	south_pov(t_data *data)
{
	data->player.planex = -0.66;
	data->player.planey = 0;
	data->player.dirx = 0.0f;
	data->player.diry = -1.0f;
}

static void	east_pov(t_data *data)
{
	data->player.planex = 0;
	data->player.planey = -0.66;
	data->player.dirx = 1.0f;
	data->player.diry = 0.0f;
}

static void	west_pov(t_data *data)
{
	data->player.planex = 0;
	data->player.planey = 0.66;
	data->player.dirx = -1.0f;
	data->player.diry = 0.0f;
}

void	init_player(t_data *data)
{
	if (data->player.orientation == 'N')
		north_pov(data);
	else if (data->player.orientation == 'S')
		south_pov(data);
	else if (data->player.orientation == 'E')
		east_pov(data);
	else if (data->player.orientation == 'W')
		west_pov(data);
}