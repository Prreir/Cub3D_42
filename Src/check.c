/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:13:59 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/10 11:37:35 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	is_onstr(const char *str, int ch)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			return (true);
		i += 1;
	}
	return (false);
}

bool	load_img(void *mlx, t_texture *tex, char **coord)
{
	int	size;

	tex->ptr = mlx_xpm_file_to_image(mlx, coord[1], &size, &size);
	boom_file(coord);
	if (!tex->ptr)
		return (write_error(TEX_ERR));
	tex->addr = mlx_get_data_addr(tex->ptr, &tex->bitpp,
			&tex->length_line, &tex->endian);
	if (!tex->addr)
		return (write_error(ADDR_ERR));
	return (true);
}

size_t	ft_len(char **str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i += 1;
	return (i);
}

bool	check_cmp(char *str1, char *str2)
{
	size_t	i;

	if ((str1 && !str2) || (!str1 && str2))
		return (false);
	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (false);
		i += 1;
	}
	return (true);
}

bool	check(int argc, char **argv)
{
	size_t	id;

	if (argc != 2)
	{
		write_error(INV_ARGS);
		return (false);
	}
	id = ft_strlen(argv[1]) - 4;
	if (!check_cmp(&argv[1][id], ".cub"))
	{
		write_error(INV_MAP);
		return (false);
	}
    return (true);
}
