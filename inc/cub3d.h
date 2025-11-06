/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:06:33 by gchauvet          #+#    #+#             */
/*   Updated: 2025/11/04 17:20:29 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

typedef unsigned int t_color;

#include "define.h"
#include "cub_math.h"
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

typedef struct s_vec2
{
	double x;
	double y;
}	t_vec2;

typedef struct s_textures
{
	t_cub_img	*tex_north;
	t_cub_img	*tex_south;
	t_cub_img	*tex_east;
	t_cub_img	*tex_west;
} t_textures;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	t_vec2	view_angle; // faudra faire les fonctions d'angle (rad)
}	t_player;

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
	t_cub_img	*rnd_img;
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
t_color		get_pixel(t_cub_img *img, int x, int y);
t_color 	rgba_to_int_color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
void		set_pixel(t_cub_img *img, int x, int y, t_color color);
void		render(t_data *data);

//////////// PARS/INIT ////////////

int	init_mlx(t_data *data);
int	pars(t_data *data, char **argv);

/////////////// FREE //////////////

int free_and_exit(t_data *data);

//////////////// MAP //////////////

char get_map_id(t_map map, size_t x, size_t y);
int set_map_id(t_map map, char id, size_t x, size_t y);

////////////// UTILS //////////////

int	get_tablen(char **tab);

////////////// ERROR //////////////

int	print_error(int code);

#endif
