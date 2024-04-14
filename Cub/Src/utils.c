/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:28:49 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/14 21:27:16 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_all_digits(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i += 1;
	}
	return (0);
}

int	is_spaces(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	valid_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E'
		|| c == 'F' || c == 'C' || c == '1' || is_spaces(c))
		return (1);
	return (0);
}