/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:56:19 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/10 12:56:22 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"	

bool	has_valid(bool player)
{
	if (!player)
		return (write_error(NO_START));
	return (true);
}	

void	set_info(t_player *info, int x, int y, char orientation)
{
	info->start_x = (double)x + 0.5;
	info->start_y = (double)y + 0.5;
	info->orientation = orientation;
}

bool	player_info(char **map, t_data *data)
{
	bool	player;
	int		i;
	int		j;

	player = false;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (is_onstr(POS_CHARS, map[i][j]))
			{
				if (player == true)
					return (write_error(INV_POS));
				else
				{
					set_info(&data->player, j, i, map[i][j]);
					player = true;
				}
			}
		}
	}
	return (has_valid(player));
}
