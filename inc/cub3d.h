/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:06:33 by gchauvet          #+#    #+#             */
/*   Updated: 2025/10/21 13:32:43 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#define WIN_W 1920
#define WIN_H 1080

typedef unsigned int t_color;

#include "../libft/libft.h"
#include <linux/limits.h>

typedef struct s_img
{
	void	*mlx_img;
	t_color		*addr;
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
	void		*mlx_ptr;
	void		*mlx_win;
}	t_data;

typedef struct s_pars
{
	char tex_path_no[PATH_MAX];
	char tex_path_so[PATH_MAX];
	char tex_path_ea[PATH_MAX];
	char tex_path_we[PATH_MAX];
	int	ceiling_color;
	int floor_color;
	char *map;
}	t_pars;

////////////// EVENT //////////////

void	event_listener(t_data *data);

//////////// GRAPHICS /////////////

t_img	*new_xpm_img(t_data *data, char *path);
t_img	*new_img(t_data *data, int sx, int sy);
int		draw_img(t_data *data, t_img *img, int x, int y);
t_color		get_pixel(t_img *img, int x, int y);
void	set_pixel(t_img *img, int x, int y, int color);

//////////// PARS/INIT ////////////

int	init_mlx(t_data *data);

/////////////// FREE //////////////

int free_and_exit(t_data *data);


#endif