/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:47:04 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/11 20:47:28 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	boom_file(char **file)
{
	int	i;

	i = 0;
	if (!file)
		return ;
	while (file[i])
	{
		free(file[i]);
		file[i] = NULL;
		i += 1;
	}
	free(file);
	file = NULL;
}

void	boom_textures(t_data *data)
{
	if (data->no.ptr)
		mlx_destroy_image(data->mlx.ptr, data->no.ptr);
	if (data->so.ptr)
		mlx_destroy_image(data->mlx.ptr, data->so.ptr);
	if (data->ea.ptr)
		mlx_destroy_image(data->mlx.ptr, data->ea.ptr);
	if (data->we.ptr)
		mlx_destroy_image(data->mlx.ptr, data->we.ptr);
}

void	boom(t_data *data)
{
	if (!data)
		return ;
	boom_textures(data);
	if (data->img.ptr)
		mlx_destroy_image(data->mlx.ptr, data->img.ptr);
	if (data->mlx.win)
		mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	if (data->mlx.ptr)
	{
		mlx_destroy_display(data->mlx.ptr);
		free(data->mlx.ptr);
	}
	if (data->map)
		boom_file(data->map);
}

int	write_error(char *msg)
{
	if (msg)
		ft_putendl_fd(msg, STDERR_FILENO);
	return (0);
}

void	error_msg(char *msg, t_data *data)
{
	if (data)
		boom(data);
	write_error(msg);
	exit(1);
}