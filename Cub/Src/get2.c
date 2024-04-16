/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:19:59 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/15 17:44:25 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_positions(t_data *data)
{
	size_t	i;
	size_t	j;
	char	dir;

	i = 0;
	while (i < data->len)
	{
		j = 0;
		while (data->map[i][j] != '\0' && (data->map[i][j] != 'N' || \
		data->map[i][j] != 'S' || data->map[i][j] != 'E' || \
		data->map[i][j] != 'W'))
		{
			j++;
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || \
			data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				data->player.start_x = j;
				data->player.start_y = i;
                dir = data->map[i][j];
			}
		}
		i++;
	}
    get_dir(data, dir);
}

void	get_dir(t_data *data, char dir)
{
	if (dir == 'N')
	{
		data->player.dirx = 0;
		data->player.diry = 1;
	}
	else if (dir == 'S')
	{
		data->player.dirx = 0;
		data->player.diry = -1;
    }
    else if (dir == 'E')
    {
        data->player.dirx = 1;
        data->player.diry = 0;
    }
    else if (dir == 'W')
    {
        data->player.dirx = -1;
        data->player.diry = 0;
    }
}
