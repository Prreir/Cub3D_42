/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:16:30 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/11 11:21:31 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	is_spaces(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (true);
	return (false);
}

bool	fits_in_intrange(int n, int lowest, int highest)
{
	return (n >= lowest && n <= highest);
}

bool	only_spaces(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\t' || str[i] != '\n' || str[i] != '\v'
			|| str[i] != '\f' || str[i] != '\r' || str[i] != ' ')
			return (false);
		i += 1;
	}
	return (true);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i += 1;
	}
	if (src[i] && i < n)
	{
		while (i < n)
			dest[i++] = '\0';
	}
	dest[i] = '\0';
	return (dest);
}

char	*trim_free(char *s1, char const *set)
{
	size_t	beg;
	size_t	end;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	beg = 0;
	while (s1[beg] != '\0' && ft_strchr(set, s1[beg]) != NULL)
		beg += 1;
	end = ft_strlen(s1 + beg);
	while (end > beg && ft_strchr(set, s1[(beg + end) - 1]) != NULL)
		end -= 1;
	trim = malloc((end + 1) * sizeof(char));
	if (!trim)
		return (NULL);
	ft_strncpy(trim, (s1 + beg), end);
	free(s1);
	return (trim);
}
