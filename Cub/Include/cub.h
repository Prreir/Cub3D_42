/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:25:12 by lugoncal          #+#    #+#             */
/*   Updated: 2024/04/15 17:41:27 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include "libft.h"
#include "get_next_line.h"
#include "mlx.h"
#include "mlx_int.h"

/* -------------------------------------------------------------------------- */
/*                                   Defines                                  */
/* -------------------------------------------------------------------------- */

# define INV_ARGS "Error\nInvalid Arguments"
# define INV_MAP "Error\nInvalid Map File"
# define MAP_INE "Error\nMap File Does Not Exist"
# define INV_CHARS "Error\nInvalid Chars"
# define TEXT_INV "Error\nInvalid Elements"
# define ERROR_OP "Error\nCouldn't Open The File"
# define MULT_STA "Error\nMultiple Start Positions"
# define INV_CHAR "Error\nInvalid Map Composition"
# define INIT_MLX "Error\nCouldn't Initialize Mlx"
# define OPEN_WIN "Error\nCouldn't Open Window"

# define WSIZE 64
# define HEIGHT 720
# define WIDTH 1280
# define KEYPRESS_EVENT 2
# define KEYRELEASE_EVENT 3
# define MOTION_NOT_EVENT 6
# define DESTROY_NOT_EVENT 17
# define FOV 60.0
# define TEXTURE_WIDTH 2048
# define TEXTURE_HEIGHT 2048

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
	size_t			len;
	char			**map;
	char			**file;
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

//rays2.c
void	draw_square(t_texture *img, int x, int y, int color);
void	draw_minimap(t_data *data);
int		extract_pixel_from_image(t_texture *img, int x, int y);
void	draw_vertical_line(t_data *data, int i);

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

//get2.c
void	get_positions(t_data *data);
void	get_dir(t_data *data, char dir);

//hooks.c
int		closewin(t_data *data);
int		getkeys_press(int keycode, t_data *data);
int		getkeys_release(int keycode, t_data *data);
bool	mouse_trespass(int x, int y, t_data *data, double *oldx);
int		movemouse(int x, int y, t_data *data);

//utils.c
int		is_spaces(char c);

//valid.c
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
int		write_error(char *msg);
void	error_msg(char *msg, t_data *data);

//check.c
bool	check_cmp(char *str1, char *str2);
bool	check(char **argv, char *file);

//main.c
int		show_window(t_data *data);
void	hooks(t_data *data);
void	init(t_data *data);

#endif