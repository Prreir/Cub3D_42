/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:56:05 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/15 16:51:28 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	closewin(t_data *data)
{
	boom(data);
	exit(0);
	return (0);
}

int	getkeys_press(int keycode, t_data *data)
{
	if (keycode == 65307)
		closewin(data);
	else if (keycode == 119 || keycode == 65362)
		data->movements[0] = 1;
	else if (keycode == 65361 || keycode == 97)
		data->movements[1] = 1;
	else if (keycode == 115 || keycode == 65364)
		data->movements[2] = 1;
	else if (keycode == 65363 || keycode == 100)
		data->movements[3] = 1;
	return (0);
}

int	getkeys_release(int keycode, t_data *data)
{
	if (keycode == 119 || keycode == 65362)
		data->movements[0] = 0;
	else if (keycode == 65361 || keycode == 97)
		data->movements[1] = 0;
	else if (keycode == 115 || keycode == 65364)
		data->movements[2] = 0;
	else if (keycode == 65363 || keycode == 100)
		data->movements[3] = 0;
	return (0);
}

bool	mouse_trespass(int x, int y, t_data *data, double *oldx)
{
	if (x < 100 || x >= WIDTH - 100)
	{
		*oldx = WIDTH / 2;
		mlx_mouse_move(data->mlx.ptr, data->mlx.win, WIDTH / 2, y);
		return (true);
	}
	return (false);
}

int	movemouse(int x, int y, t_data *data)
{
	double			old_dirx;
	double			old_planex;
	double			distance;
	static double	oldx = 0;

	old_dirx = data->player.dirx;
	old_planex = data->player.planex;
	if (mouse_trespass(x, y, data, &oldx))
		return (0);
	distance = (oldx - x) * 0.002;
	oldx = x;
	data->player.dirx = data->player.dirx * cos(distance) - \
			data->player.diry * sin(distance);
	data->player.diry = old_dirx * sin(distance) + \
			data->player.diry * cos(distance);
	data->player.planex = data->player.planex * cos(distance) - \
			data->player.planey * sin(distance);
	data->player.planey = old_planex * sin(distance) + \
			data->player.planey * cos(distance);
	return (0);
}
