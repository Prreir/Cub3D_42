/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:17:49 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/12 18:55:46 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// int	show_window(t_data *data)
// {
// 	player_movement(data);
// 	cast_rays(data);
// 	mlx_destroy_image(data->mlx.ptr, data->img.ptr);
// 	data->img.ptr = NULL;
// 	return (0);
// }

// void	hooks(t_data *data)
// {
// 	mlx_mouse_move(data->mlx.ptr, data->mlx.win, cos(data->player.dirx) 
// 	+ cos(data->player.diry), (HEIGHT / 2));
// 	mlx_hook(data->mlx.win, KEYPRESS_EVENT, (1L << 0), getkeys_press, data);
// 	mlx_hook(data->mlx.win, KEYRELEASE_EVENT, (1L << 1), getkeys_release, data);
// 	mlx_hook(data->mlx.win, MOTION_NOT_EVENT, (1L << 6), movemouse, data);
// 	mlx_hook(data->mlx.win, DESTROY_NOT_EVENT, (1L << 17), closewin, data);
// 	mlx_loop_hook(data->mlx.ptr, show_window, data);
// 	mlx_loop(data->mlx.ptr);
// }

void	init(t_data *data)
{
	data->mlx.ptr = mlx_init();
	if (!data->mlx.ptr)
		error_msg(MLX_INIT, data);
	data->mlx.win = NULL;
	data->no.ptr = NULL;
	data->so.ptr = NULL;
	data->ea.ptr = NULL;
	data->we.ptr = NULL;
	data->movements[0] = false;
	data->movements[1] = false;
	data->movements[2] = false;
	data->movements[3] = false;
	data->map = NULL;
	data->img.ptr = NULL;
	data->img.addr = NULL;
	data->img.bitpp = 0;
	data->img.length_line = 0;
	data->img.endian = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		if (check(argv, argv[1]) == 1)
			error_msg(NULL, NULL);
		init(&data);
		if (info(&data, argv[1]) == 1)
			error_msg(NULL, &data);
		// data.mlx.win = mlx_new_window(data.mlx.ptr, WIDTH, HEIGHT, "cub3D");
		// if (!data.mlx.win)
		// 	error_msg(WIN_INIT, &data);
		// hooks(&data);
		boom(&data);
	}
	else if (argc != 2)
		error_msg(INV_ARGS, NULL);
	return (0);
}
