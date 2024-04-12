/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:32:58 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/11 21:36:11 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	is_all_digits(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		i += 1;
	}
	return (true);
}

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

bool	parse_rgb(char *id, int *rgb_arr, char **map)
{
	int		i;
	bool	value;
	char	**temp;
	char	**rgb;

	i = -1;
	value = true;
	while (++i < 6)
	{
		temp = ft_split(map[i], ' ');
		if (check_cmp(id, temp[0]))
		{
			if (ft_len(temp) != 2)
				value = write_error(INV_NBR);
			rgb = ft_split(temp[1], ',');
			if (value == true && !assign_rgb(rgb_arr, rgb))
				value = false;
			boom_file(rgb);
			boom_file(temp);
			return (value);
		}
		boom_file(temp);
	}
	return (write_error(ELE_MIS));
}

int	info_coord(char *coord, void *mlx, t_texture *texture, char **map)
{
	size_t		i;
	char		**temp;
	t_texture	tex;

	i = 0;
	while (i < 6)
	{
		temp = ft_split(map[i], ' ');
		if (check_cmp(coord, temp[0]))
		{
			if (ft_len(temp) != 2)
			{
				boom_file(temp);
				return (write_error(INV_NBR));
			}
			if (!load_img(mlx, &tex, temp))
				return (0);
			*texture = tex;
			return (1);
		}
		i += 1;
		boom_file(temp);
	}
	return (0);
}

int	info_textures(t_data *data, char **textures)
{
	int	value;

	value = 0;
	if (parse_coord("NO", data->mlx.ptr,
			&data->no, textures)
		&& parse_coord("SO", data->mlx.ptr,
			&data->so, textures)
		&& parse_coord("EA", data->mlx.ptr,
			&data->ea, textures)
		&& parse_coord("WE", data->mlx.ptr,
			&data->we, textures)
		&& parse_rgb("C", data->ceiling_rgb, textures)
		&& parse_rgb("F", data->floor_rgb, textures))
		value = 1;
	boom_file(textures);
	return (value);
}