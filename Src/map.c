/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:33:58 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/10 12:04:45 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	valid_surroundings(char **map, size_t i, size_t j)
{
	return (is_onstr(VALID_ELE, map[i - 1][j - 1])
				&& is_onstr(VALID_ELE, map[i - 1][j])
				&& is_onstr(VALID_ELE, map[i - 1][j + 1])
				&& is_onstr(VALID_ELE, map[i][j - 1])
				&& is_onstr(VALID_ELE, map[i][j + 1])
				&& is_onstr(VALID_ELE, map[i + 1][j - 1])
				&& is_onstr(VALID_ELE, map[i + 1][j])
				&& is_onstr(VALID_ELE, map[i + 1][j + 1]));
}

bool	valid_content(char **map)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (map[i + 1])
	{
		j = 1;
		while (map[i][j] && j < get_line_last(map[i - 1])
			&& j < get_line_last(map[i + 1]))
		{
			if (is_onstr(VALID_MAP, map[i][j])
				&& !valid_surroundings(map, i, j))
				return (write_error(INV_COMP));
			j += 1;
		}
		while (map[i][j])
		{
			if (map[i][j] != '1')
				return (write_error(INV_COMP));
			j += 1;
		}
		i += 1;
	}
	return (true);
}

size_t	get_line_last(char *map)
{
	size_t	i;

	i = ft_strlen(map) - 1;
	while (is_spaces(map[i]))
		i -= 1;
	i += 1;
	return (i);
}

bool	walls(char **map)
{
	int	i;
	int	j;

	j = -1;
	while (map[0][++j])
		if (!is_onstr(" 1", map[0][j]))
			return (write_error(NOT_WALLS));
	j = -1;
	i = ft_len(map) - 1;
	while (map[i][++j])
		if (!is_onstr(" 1", map[i][j]))
			return (write_error(NOT_WALLS));
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (is_spaces(map[i][j]))
			j += 1;
		if (map[i][j] != '1')
			return (write_error(NOT_WALLS));
		j = get_line_last(map[i]) - 1;
		if (map[i][j] != '1')
			return (write_error(NOT_WALLS));
	}
	return (true);
}

bool	parse_map(char **map, t_data *data)
{
	if (!walls(map) || !valid_content(map)
		|| !player_info(map, data))
		return (false);
	init_player(data);
	data->len = ft_len(map);
	return (true);
}
