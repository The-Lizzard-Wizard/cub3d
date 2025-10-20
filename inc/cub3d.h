/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:06:33 by gchauvet          #+#    #+#             */
/*   Updated: 2025/10/20 19:04:46 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#define WIN_W 1920
#define WIN_H 1080

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
	double pos_x;
	double pos_y;
}	t_player;

typedef struct s_map
{
	int		floor_color[3];
	int		ceiling_color[3];
	char 	**grid;
}	t_map;

typedef struct s_data
{
	t_map		map;
	t_player	player;
	t_textures	textures;
	void		*mlx_ptr;
	void		*mlx_win;
}	t_data;

////////////// EVENT //////////////

void	event_listener(t_data *data);

//////////// GRAPHICS /////////////

t_img	*new_xpm_img(t_data *data, char *path);
t_img	*new_img(t_data *data, int sx, int sy);
int		draw_img(t_data *data, t_img *img, int x, int y);
int		get_pixel(t_img *img, int x, int y);
void	set_pixel(t_img *img, int x, int y, int color);

//////////// PARS/INIT ////////////

int	init_mlx(t_data *data);

/////////////// FREE //////////////

int free_and_exit(t_data *data);


#endif