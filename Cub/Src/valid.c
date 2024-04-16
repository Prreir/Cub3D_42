/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:56:02 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/15 17:45:05 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// void	valid_lines(t_data *data)
// {
// 	int	line;
// 	int	len;

// 	line = 1;
// 	while (line < data->mlen - 1)
// 	{
// 		len = ft_strlen(data->map[line]) - 1;
// 		if (data->map[line][0] != '1' || data->map[line][len] != '1')
// 		{
// 			free_all(data);
// 			print_error(INV_CHAR);
// 		}
// 		line++;
// 	}
// }

// void	valid_ends(t_data *data, int line)
// {
// 	int	len;

// 	len = ft_strlen(data->map[line]) - 1;
// 	while (len >= 0)
// 	{
// 		if (data->map[line][len] == '1' || data->map[line][len] == ' ')
// 			len--;
// 		else if (data->map[line][len] != '1' && data->map[line][len] != ' ')
// 		{
// 			free_all(data);
// 			print_error(INV_CHAR);
// 		}
// 	}
// }

// void	valid_char(t_data *data)
// {
// 	int	i;
// 	int	j;
// 	int	len;

// 	i = -1;
// 	while (++i < data->mlen - 1)
// 	{
// 		len = ft_strlen(data->map[i]);
// 		j = -1;
// 		while (++j < len)
// 		{
// 			if (data->map[i][j] != '1' && data->map[i][j] != '0' && 
// 			data->map[i][j] != 'N' && data->map[i][j] != 'S' && 
// 			data->map[i][j] != 'E' && data->map[i][j] != 'W' &&
// 			data->map[i][j] != ' ')
// 			{
// 				free_all(data);
// 				print_error(INV_CHAR);
// 			}
// 			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || 
// 			data->map[i][j] == 'E' || data->map[i][j] == 'W')
// 				data->start++;
// 		}
// 	}
// }

// void	valid_map(t_data *data)
// {
// 	int	i;
// 	int	len;

// 	valid_char(data);
// 	if (data->start != 1)
// 	{
// 		free_all(data);
// 		print_error(MULT_STA);
// 	}
// 	i = -1;
// 	while (++i < data->mlen)
// 	{
// 		len = ft_strlen(data->map[i]) - 1;
// 		while (len >= 0)
// 		{
// 			if (data->map[i][len] == ' ')
// 				data->map[i][len] = '1';
// 			len--;
// 		}
// 	}
// 	valid_ends(data, 0);
// 	valid_ends(data, data->mlen - 1);
// 	valid_lines(data);
// }

int	valid_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E'
		|| c == 'F' || c == 'C' || c == '1' || is_spaces(c))
		return (1);
	return (0);
}

int	valid_map(char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			if (i == 0)
				return (0);
			break ;
		}
		if (line[0] != '\n' && !valid_char(line[0]))
		{
			free(line);
			return (0);
		}
		free(line);
		i++;
	}
	return (close(fd), 1);
}