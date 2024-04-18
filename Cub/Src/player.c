/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:56:19 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/18 11:46:28 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"	

void	has_valid(bool player, t_data *data)
{
	if (!player)
		error_msg(NO_START, data);
	return ;
}

void	set_info(t_player *info, int x, int y, char orientation)
{
	info->start_x = (double)x + 0.5;
	info->start_y = (double)y + 0.5;
	info->orientation = orientation;
}

void	get_player(t_data *data, bool player)
{
	int		i;
	int		j;

	i = 0;
	while(data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
			|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				if (player == true)
					error_msg(INV_POS, data);
				else
				{
					set_info(&data->player, j, i, data->map[i][j]);
					player = true;
				}
			}
			j++;
		}
		i++;
	}
	has_valid(player, data);
}
