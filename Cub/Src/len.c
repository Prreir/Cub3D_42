/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:02:05 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/14 20:50:09 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	the_last(char *tmp, char c)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (tmp[i])
	{
		if (tmp[i] == c)
			pos = i;
		i++;
	}
	return (pos + 1);
}

int	len_file2(char *tmp, int i, t_data *data)
{
	if (tmp[i] && (tmp[i] == 'N' || tmp[i] == 'S'
			|| tmp[i] == 'W' || tmp[i] == 'E' || tmp[i] == 'F'
			|| tmp[i] == 'C' || tmp[i] == '\n'))
	{
		free(tmp);
		return (1);
	}
	if (tmp[i] == '1')
	{
		if (data->wid < the_last(tmp, '1'))
			data->wid = the_last(tmp, '1');
		return (2);
	}
	return (0);
}

void	len_file(char *file, t_data *data)
{
	int		len;
	int		i;
	char	*tmp;
	int		fd;

	fd = open(file, O_RDONLY);
	len = 0;
	data->wid = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		i = 0;
		while (tmp[i] && is_spaces(tmp[i]))
			i++;
		if (len_file2(tmp, i, data) == 1)
			continue ;
		else if (len_file2(tmp, i, data) == 2)
			len++;
		free(tmp);
	}
	data->len = len;
}
