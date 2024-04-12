/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:13:28 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/12 22:22:40 by lugoncal         ###   ########.fr       */
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

# define VALID_MAP "0NSEW"
# define VALID_ELE "01NSEW"
# define POS_CHARS "NSEW"

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
	int				len;
	int				wid;
	char			**map;
	int				movements[4];
	int				ceiling_rgb[3];
	int				floor_rgb[3];
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

//MOVEMENT.C
void	player_movement(t_data *data);

//RAYS2.C
void	draw_minimap(t_data *data);
void	draw_square(t_texture *img, int x, int y, int color);
void	draw_vertical_line(t_data *data, int i);
void	init_rays(t_data *data, int i);

//RAYS.C
void	wall_pixel(t_data *data);
void	wall_height(t_data *data);
void	distance_to_wall(t_data *data, char **map);
void	hit_wall(t_data	*data);
void	cast_rays(t_data *data);

//HOOKS.C
int		closewin(t_data *data);
int		getkeys_press(int keycode, t_data *data);
int		getkeys_release(int keycode, t_data *data);
bool	mouse_trespass(int x, int y, t_data *data, double *oldx);
int		movemouse(int x, int y, t_data *data);

//INIT_PLAYER.C
void	init_player(t_data *data);

//PLAYER.C
bool	has_valid(bool player);
void	set_info(t_player *info, int x, int y, char orientation);
bool	player_info(char **map, t_data *data);

//MAP.C
size_t	get_line_last(char *map);
bool	walls(char **map);
bool	parse_map(char **map, t_data *data);

//LEN.C
int		the_last(char *tmp, char c);
int		len_file2(char *tmp, int i, t_data *data);
void	len_file(char *file, t_data *data);

//INFO.C
int		info(t_data *data, char *file);

//BOOM.C
int		write_error(char *error_msg);
void	error_msg(char *msg, t_data *data);
void	boom_file(char **file);
void	boom_textures(t_data *data);
void	boom(t_data *data);

//UTILS.C
int		is_spaces(char c);
int		valid_char(char c);

//CHECK.C
int		check_cmp(char *str1, char *str2);
int		check(char **argv, char *file);

//MAIN.C
int		show_window(t_data *data);
void	hooks(t_data *data);
void	init(t_data *data);

#endif