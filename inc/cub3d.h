/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:06:33 by gchauvet          #+#    #+#             */
/*   Updated: 2025/10/20 16:26:48 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#define WIN_W 1920
#define WIN_H 1080

typedef struct s_textures
{
	void	*tex_north;
	void	*tex_south;
	void	*tex_east;
	void	*tex_west;
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

//////////// PARS/INIT ////////////

int	pars_map(t_data *data, char **argv);
int	init_mlx(t_data *data);


#endif