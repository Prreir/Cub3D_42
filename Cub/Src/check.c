/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:13:59 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/18 14:02:33 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

int	check_nbr_rgb(int n, int lowest, int highest)
{
	if (n >= lowest && n <= highest)
		return (1);
	return (0);
}

int	check_rgb(t_data *data, int j, int z)
{
	int	i;

	i = 0;
	while (data->file[j][z])
	{
		if (data->file[j][z] == ',' && ft_isdigit(data->file[j][z - 1]) \
			&& ft_isdigit(data->file[j][z + 1]))
			i++;
		z++;
	}
	if (i == 2)
		return (1);
	return (0);
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

bool	check(char **argv, char *file)
{
	size_t	id;

	id = ft_strlen(argv[1]) - 4;
	if (!check_cmp(&argv[1][id], ".cub"))
	{
		write_error(INV_MAP);
		return (false);
	}
	if (open(file, O_RDONLY) == -1)
	{
		write_error(MAP_INE);
		return (false);
	}
	return (true);
}
