/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:32:58 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/14 22:16:16 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// void	get_rgb(char *tmp, t_data *data, int j)
// {
// 	int		i;
// 	int		index;
// 	char	*line;

// 	index = 0;
// 	while (tmp[++j] && index < 3)
// 	{
// 		if (ft_isdigit(tmp[j]))
// 		{
// 			i = j;
// 			line = ft_substr(line, i, j - i);
// 			printf("%s\n", tmp);
// 			if (tmp[0] == 'C')
// 			{
// 				data->ceiling_rgb[index++] = ft_atoi(tmp);
// 				printf("C[%d]: %d\n", index, data->ceiling_rgb[index]);
// 			}
// 			else
// 			{
// 				data->floor_rgb[index++] = ft_atoi(tmp);
// 				printf("F[%d]: %d\n", index, data->floor_rgb[index]);
// 			}
// 			free(line);
// 		}
// 	}
// }

bool	assign_rgb(int *element, char **rgb)
{
	size_t	i;

	i = 0;
	if (ft_len(rgb) != 3)
		return (write_error(RGB_VAL));
	while (rgb[i])
	{
		if (!is_all_digits(rgb[i]))
			return (write_error(RGB_VAL));
		element[i] = ft_atoi(rgb[i]);
		if (!fits_in_intrange(element[i], 0, 255))
			return (write_error(RGB_OUT));
		i += 1;
	}
	return (true);
}

void	get_rgb(char *tmp, t_data *data, int j)
{
	int		index;
	char	**rgb;

	i = 0;
	while (line[++j] && index < 3)
	{
		rgb = ft_split(temp[1], ',');
		if (!assign_rgb(tmp, rgb))
		boom_file(rgb);
		boom_file(temp);
	}
	error_msg(ELE_MIS, data);
}

void	textures_info2(t_data *data, char *tmp, int j)
{
	if (tmp[j] == 'C' || tmp[j] == 'F')
		get_rgb(tmp, data, j);
	// else if (tmp[j] == 'N' || tmp[j] == 'S'
	// 	|| tmp[j] == 'E' || tmp[j] == 'W')
	// 	get_textures(tmp, data, tmp[j], j);
}

void	textures_info(t_data *data, int fd)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < 6)
	{
		j = 0;
		tmp = get_next_line(fd);
		if (tmp[0] == '1' || tmp[0] == '0')
			error_msg("Map can't come first.", data);
		while (is_spaces(tmp[j]))
			j++;
		if (tmp[j] != '\n')
			i++;
		else
		{
			free(tmp);
			continue ;
		}
		textures_info2(data, tmp, j);
		free(tmp);
	}
}
