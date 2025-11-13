/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:06:33 by gchauvet          #+#    #+#             */
/*   Updated: 2025/11/13 15:18:00 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

typedef unsigned int t_color;

#include "define.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"

typedef struct s_modify
{
	int x;
	int y;
	int sc_x;
	int sc_y;
	int quad_x;
	int quad_y;
	int quad_sx;
	int quad_sy;
	int text_space;
} t_modify;

typedef struct s_cub_img
{
	void	*mlx_img;
	int		*addr;
	int		size_x;
	int		size_y;
	int		endian;
	int		pixels_bits;
	int		size_line;
} t_cub_img;

typedef struct s_textures
{
	t_cub_img	*tex_north;
	t_cub_img	*tex_south;
	t_cub_img	*tex_east;
	t_cub_img	*tex_west;
} t_textures;

typedef struct s_vec2
{
	double x;
	double y;
}	t_vec2;

typedef struct s_int_pos2
{
	int x;
	int y;
}	t_int_pos2;

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	view_angle; // faudra faire les fonctions d'angle (rad)
}	t_player;

typedef	struct s_ui
{
	t_cub_img	*wall_img;
	t_cub_img	*minimap_img;
	t_cub_img	*pl_img;
	t_cub_img	*mimp_frame;
	t_cub_img	*floor_img;
	t_cub_img	*font;
} t_ui;

typedef struct s_map
{
	char	**grid;
	size_t	width;
	size_t	height;
}	t_map;

typedef struct s_data
{
	t_map		map;
	t_player	player;
	t_textures	textures;
	int		floor_color;
	int		ceiling_color;
	t_cub_img		*screen_img;
	void		*mlx_ptr;
	void		*mlx_win;
	t_ui		ui;
}	t_data;

////////////// EVENT //////////////

void	event_listener(t_data *data);
int		update();

//////////// GRAPHICS /////////////

void		put_text_on_img(t_cub_img *to_img, t_cub_img *font, char *str, t_modify mod);
int			free_cub_img(t_data *data, t_cub_img *img, int code);
t_cub_img	*new_xpm_img(t_data *data, char *path);
t_cub_img	*new_img(t_data *data, int sx, int sy);
int			draw_img(t_data *data, t_cub_img *img, int x, int y);
int			draw_img_on_img(t_cub_img *to_img, t_cub_img *img, t_modify mod);
void		draw_recangle(t_cub_img *to_img, t_color color, int fill, t_modify mod);
t_color		get_pixel(t_cub_img *img, int x, int y);
t_color 	rgba_to_int_color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
void		set_pixel(t_cub_img *img, int x, int y, t_color color);
void		render(t_data *data);
void		init_modify(t_modify *mod);
void		raycaster(t_data *data);

/////////////// UI ///////////////

void	draw_minimap(t_data *data, int map_size);

//////////// PARS/INIT ////////////

int	init_mlx(t_data *data);
int	pars(t_data *data, char **argv);
int	init_mini_map(t_data *data);
int	init_ui(t_data *data);

/////////////// FREE //////////////

int	free_and_exit(t_data *data);
int	free_one_and_exit(void *ptr, int code);
int	free_too_and_exit(void *ptr1, void *ptr2, int code);
int	free_three_and_exit(void *ptr1, void *ptr2, void *ptr3, int code);

//////////////// MAP //////////////

char	get_map_id(t_map map, size_t x, size_t y);
int		set_map_id(t_map map, char id, size_t x, size_t y);

////////////// UTILS //////////////

int	get_tablen(char **tab);
size_t	get_long_line_in_array(char **array);
void	print_char_array(char **array);

////////////// ERROR //////////////

int	print_error(int code);

#endif
