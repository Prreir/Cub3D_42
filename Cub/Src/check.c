/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:27:49 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/11 21:43:40 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_onstr(const char *str, int ch)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			return (1);
		i += 1;
	}
	return (0);
}

int	load_img(void *mlx, t_texture *tex, char **coord)
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
	return (1);
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

int	check_cmp(char *str1, char *str2)
{
	size_t	i;

	if ((str1 && !str2) || (!str1 && str2))
		return (1);
	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (1);
		i += 1;
	}
	return (0);
}

int	check(char **argv)
{
	size_t	id;

	id = ft_strlen(argv[1]) - 4;
	if (check_cmp(&argv[1][id], ".cub") == 1)
	{
		write_error(INV_MAP);
		return (1);
	}
	return (0);
}