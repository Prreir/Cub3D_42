/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:16:30 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/18 11:01:19 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// bool	only_spaces(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] != '\t' || str[i] != '\n' || str[i] != '\v'
// 			|| str[i] != '\f' || str[i] != '\r' || str[i] != ' ')
// 			return (false);
// 		i += 1;
// 	}
// 	return (true);
// }

// char	*ft_strncpy(char *dest, const char *src, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (src[i] && i < n)
// 	{
// 		dest[i] = src[i];
// 		i += 1;
// 	}
// 	if (src[i] && i < n)
// 	{
// 		while (i < n)
// 			dest[i++] = '\0';
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

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
