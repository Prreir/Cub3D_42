/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:27:49 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/14 21:27:02 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		check_rgb(int n, int low, int high)
{
	return (n >= low && n <= high);
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

int	check(char **argv, char *file)
{
	size_t	id;

	id = ft_strlen(argv[1]) - 4;
	if (check_cmp(&argv[1][id], ".cub") == 1)
	{
		write_error(INV_MAP);
		return (1);
	}
	if (open(file, O_RDONLY) == -1)
	{
		write_error(INV_MAP);
		return (1);
	}
	return (0);
}
