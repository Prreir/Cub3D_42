/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:25:12 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/18 14:20:28 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <stdint.h>
# include <stdbool.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "mlx_int.h"

/* -------------------------------------------------------------------------- */
/*                                   Defines                                  */
/* -------------------------------------------------------------------------- */

# define HEIGHT 720
# define WIDTH 1280
# define KEYPRESS_EVENT 2
# define KEYRELEASE_EVENT 3
# define MOTION_NOT_EVENT 6
# define DESTROY_NOT_EVENT 17
# define FOV 60.0
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

# define WHITE 0xFFFAFA
# define BLACK 0x000000
# define YELLOW 0xFFFF00
# define MINIMAP_SQUARES_PADDING 4

# define MARGIN 0.1f
# define MOVESPEED 0.08f

# define INV_ARGS "Error\nInvalid Arguments"
# define INV_MAP "Error\nInvalid Map File"
# define MLX_INIT "Error\nmlx_init() Failed"
# define MAP_INE "Error\nMap File Does Not Exist"
# define MAP_CHARS "Error\nInvalid Map Arguments"
# define WIN_INIT "Error\nmlx_new_window() Failed"
# define INV_NBR "Error\nInvalid Amount Of Element"
# define TEX_ERR "Error\nFailed To Open Texture"
# define ADDR_ERR "Error\nmlx_get_data_addr() Failed"
# define ELE_MIS "Error\nMandatory Scene Element Missing"
# define RGB_VAL "Error\nInvalid RGB Values"
# define RGB_OUT "Error\nRGB Value Out Of Bounds [0, 255]"
# define NOT_WALLS "Error\nScene's Map Is Not Surrounded By Walls ('1')"
# define INV_COMP "Error\nScene's Map Is Wrongly Composed"
# define INV_POS "Error\nMore Than One Player's Start Position"
# define NO_START "Error\nNo Player's Start Position"
# define MUL_START "Error\nMultiple Player's Start Position"

/* -------------------------------------------------------------------------- */
/*                                   Structs                                  */
/* -------------------------------------------------------------------------- */

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
}	t_ray;

typedef struct s_player
{
	double	start_x;
	double	start_y;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	char	orientation;
}	t_player;

typedef struct s_texture
{
	char	*path;
	void	*ptr;
	char	*addr;
	int		bitpp;
	int		length_line;
	int		endian;	
}	t_texture;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}	t_mlx;

typedef struct s_data
{
	size_t			len;
	char			**map;
	char			**file;
	int				movements[4];
	int				ceiling_rgb[3];
	int				floor_rgb[3];
	int				ceiling_hex;
	int				floor_hex;
	t_mlx			mlx;
	t_texture		img;
	t_texture		no;
	t_texture		so;
	t_texture		ea;
	t_texture		we;
	t_player		player;
	t_ray			ray;
}	t_data;

/* -------------------------------------------------------------------------- */
/*                                 Prototypes                                 */
/* -------------------------------------------------------------------------- */

//textures2.c
void	load_img(t_data *map, t_texture *image, char *path);
void	textures(t_data *data);

//rays2.c
void	draw_minimap(t_data *data);
void	draw_square(t_texture *img, int x, int y, int color);
void	draw_vertical_line(t_data *data, int i);
void	init_rays(t_data *data, int i);

//rays.c
void	cast_rays(t_data *data);
void	hit_wall(t_data *data);
void	distance_to_wall(t_data *data, char **map);
void	wall_height(t_data *data);
void	wall_pixel(t_data *data);

//movemets.c
void	player_movement(t_data *data);
void	move_up(t_data *data);
void	move_left(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);

//hooks.c
int		closewin(t_data *data);
int		getkeys_press(int keycode, t_data *data);
int		getkeys_release(int keycode, t_data *data);
bool	mouse_trespass(int x, int y, t_data *data, double *oldx);
int		movemouse(int x, int y, t_data *data);

//init_player.c
void	init_player(t_data *data);

//textures.c
void	loop_textures(t_data *data, int j, int z);
void	init_textures(t_data *data, int j, int z);
void	to_hex(t_data *data);
void	init_rgb(t_data *data, int j, int z);
void	rgb_text(t_data *data, int j, int z);

//player.c
void	has_valid(bool player, t_data *data);
void	set_info(t_player *info, int x, int y, char orientation);
void	get_player(t_data *data, bool player);

//utils.c
int		valid_char(char c);
int		is_spaces(char c);

//valid.c
void	validad_map(t_data *data);
int		valid_map(char *file);

//get.c
void	create_map(t_data *data);
void	get_textures(t_data *data);
void	create_file(t_data *data, char *map);
void	get_len(t_data *data, char *map);
void	get_info(t_data *data, char *map);

//boom.c
void	boom_file(char **file);
void	boom_textures(t_data *data);
void	boom(t_data *data);
void	write_error(char *msg);
void	error_msg(char *msg, t_data *data);

//check.c
size_t	ft_len(char **str);
int		check_nbr_rgb(int n, int lowest, int highest);
int		check_rgb(t_data *data, int j, int z);
bool	check_cmp(char *str1, char *str2);
bool	check(char **argv, char *file);

//main.c
int		show_window(t_data *data);
void	hooks(t_data *data);
void	init(t_data *data);

static inline t_texture	new_img(void *mlx_ptr)
{
	t_texture	new_img;

	new_img.ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	new_img.addr = mlx_get_data_addr(new_img.ptr, &new_img.bitpp,
			&new_img.length_line, &new_img.endian);
	return (new_img);
}

static inline void	put_pixel_in_canvas(t_texture *img, \
	int x, int y, uint32_t color)
{
	char	*dst;

	dst = img->addr + (y * img->length_line + x * (img->bitpp / 8));
	*(uint32_t *)dst = color;
}

static inline int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static inline int	extract_pixel_from_image(t_texture *img,
		int point_x, int point_y)
{
	return (*(uint32_t *)(img->addr
		+ (point_y * img->length_line) + (point_x * img->bitpp / 8)));
}

static inline uint32_t	get_color(t_data *data)
{
	if (!data->ray.side)
	{
		if (data->player.start_x > data->ray.map_x)
		{
			return (extract_pixel_from_image(&data->we,
					data->ray.tex_x, data->ray.tex_y));
		}
		return (extract_pixel_from_image(&data->ea,
				data->ray.tex_x, data->ray.tex_y));
	}
	if (data->player.start_y > data->ray.map_y)
	{
		return (extract_pixel_from_image(&data->no,
				data->ray.tex_x, data->ray.tex_y));
	}
	return (extract_pixel_from_image(&data->so,
			data->ray.tex_x, data->ray.tex_y));
}

#endif