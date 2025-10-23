/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:06:33 by gchauvet          #+#    #+#             */
/*   Updated: 2025/10/23 17:14:48 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#define WIN_W 1920
#define WIN_H 1080

#define NONE_COLOR_XPM 4278190080

typedef unsigned int t_color;

#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"

typedef struct s_modify
{
	int x;
	int y;
	int scale;
} t_modify;

typedef struct s_img
{
	void	*mlx_img;
	int		*addr;
	int		size_x;
	int		size_y;
	int		endian;
	int		pixels_bits;
	int		size_line;
} t_img;

typedef struct s_textures
{
	t_img	*tex_north;
	t_img	*tex_south;
	t_img	*tex_east;
	t_img	*tex_west;
} t_textures;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	int		view_angle;
}	t_player;

typedef struct s_map
{
	char	*grid;
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
	t_img		*screen_img;
	void		*mlx_ptr;
	void		*mlx_win;
	//t_img		*rnd_img;
}	t_data;

////////////// EVENT //////////////

void	event_listener(t_data *data);
int		update();

//////////// GRAPHICS /////////////

t_img	*new_xpm_img(t_data *data, char *path);
t_img	*new_img(t_data *data, int sx, int sy);
int		draw_img(t_data *data, t_img *img, int x, int y);
int		draw_img_on_img(t_img *to_img, t_img *img, t_modify mod);
t_color	get_pixel(t_img *img, int x, int y);
t_color rgba_to_int_color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
void	set_pixel(t_img *img, int x, int y, t_color color);
void	render(t_data *data);

//////////// PARS/INIT ////////////

int	init_mlx(t_data *data);

/////////////// FREE //////////////

int free_and_exit(t_data *data);

//////////////// MAP //////////////

char get_map_id(t_map map, size_t x, size_t y);
int set_map_id(t_map map, char id, size_t x, size_t y);

////////////// UTILS //////////////

int	get_tablen(char **tab);

#endif
