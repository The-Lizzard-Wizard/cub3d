/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:06:33 by gchauvet          #+#    #+#             */
/*   Updated: 2025/12/03 16:52:21 by gchauvet         ###   ########.fr       */
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
	void *mlx_img;
	int *addr;
	int size_x;
	int size_y;
	int endian;
	int pixels_bits;
	int size_line;
} t_cub_img;

typedef struct s_textures
{
	t_cub_img	*tex_north;
	t_cub_img	*tex_south;
	t_cub_img	*tex_east;
	t_cub_img	*tex_west;
	t_cub_img	*tex_r_key;
	t_cub_img	*tex_y_key;
	t_cub_img	*tex_b_key;
	t_cub_img	*tex_g_key;
} t_textures;

typedef struct s_vec2
{
	double x;
	double y;
} t_vec2;

typedef struct s_int_pos2
{
	int x;
	int y;
} t_int_pos2;

typedef struct s_control
{
	int move_w;
	int move_s;
	int move_d;
	int move_a;
	int move_left;
	int move_right;
} t_control;

//===========================================
//= game state
//=                                       key to switch in game
//=  toggle_collide 1=collide 0=noclip    C
//=  toggle_minimap 1=visible 0=hide      TAB
//=  camera_ctrl_type 1=keyboard 0=mouse  M
//=
//===========================================

typedef struct s_game_state
{
	int toggle_collide;
	int toggle_minimap;
	int camera_ctrl_type;
} t_game_state;

typedef struct s_player
{
	t_vec2		pos;
	t_vec2		view_angle;
	t_vec2		camera_plane;
	t_control	control;
	int			score;
	int			red_key;
	int			yellow_key;
	int			blue_key;
	int			green_key;
} t_player;

typedef struct s_thing
{
	t_vec2			pos;
	int				type;
	t_cub_img		*texture;
	struct s_thing	*next;
	struct s_thing	*prev;
}	t_thing;

typedef struct s_ui
{
	t_cub_img	*wall_img;
	t_cub_img	*y_door;
	t_cub_img	*b_door;
	t_cub_img	*g_door;
	t_cub_img	*r_door;
	t_cub_img	*door;
	t_cub_img	*door_open;
	t_cub_img	*minimap_img;
	t_cub_img	*pl_img;
	t_cub_img	*mimp_frame;
	t_cub_img	*floor_img;
	t_cub_img	*font;
	t_cub_img	*thing;
	char		number_buffer[13];
} t_ui;

typedef struct s_map
{
	char	**grid;
	size_t	width;
	size_t	height;
} t_map;

typedef struct s_raycast
{
	t_vec2		pos; // player coordinates
	t_vec2		dir; // player view angle, where he he's looking
	t_vec2		plane; // view plane, normal vector to dir
	t_vec2		ray_dir; // ray direction vector
	t_vec2		dist_to_side; // the distance from the player to the first x side/y side (rn it's the first step)
	t_vec2		next_step_size; // the distance from the x side / y side to the next one
	t_int_pos2	map; // the square of the map the ray is in
	double		dist_to_plane; // distance of the wall to the plane
	double		camera_pos; // x coordinate of the ray in the "camera"
	t_vec2		step_dir; // the direction of the next step of the ray
	int			side; // which wall was hit? very explicit too
	char		wall_face;
} t_raycast;

typedef struct s_data
{
	t_map			map;
	t_player		player;
	t_textures		textures;
	int				floor_color;
	int				ceiling_color;
	t_cub_img		*screen_img;
	void			*mlx_ptr;
	void			*mlx_win;
	t_ui			ui;
	t_game_state	game_state;
	t_thing			*thing_list;
} t_data;

////////////// EVENT //////////////

void event_listener(t_data *data);
int update();
void move_press(t_data *data, int key);
void move_release(t_data *data, int key);
void move(t_data *data, t_vec2 *move);
int collide(t_data *data, t_vec2 pos, int xy);
void mouse_camera(t_data *data);

//////////// GAMEPLAY /////////////

t_thing	*get_last_thing(t_thing *thing_list);
int		add_thing(t_data *data, t_cub_img *texture, t_vec2 pos, int type);
void	del_thing(t_data *data, t_thing *thing_to_del);
int		collide_with_thing(t_data *data);
void	take_y_key(t_data *data, t_thing *to_del);
void	take_b_key(t_data *data, t_thing *to_del);
void	take_g_key(t_data *data, t_thing *to_del);
void	take_r_key(t_data *data, t_thing *to_del);
void		door_interact(t_data *data);

//////////// GRAPHICS /////////////

void put_text_on_img(t_cub_img *to_img, t_cub_img *font, char *str, t_modify mod);
int free_cub_img(t_data *data, t_cub_img *img, int code);
t_cub_img *new_xpm_img(t_data *data, char *path);
t_cub_img *new_img(t_data *data, int sx, int sy);
int draw_img(t_data *data, t_cub_img *img, int x, int y);
int draw_img_on_img(t_cub_img *to_img, t_cub_img *img, t_modify mod);
void draw_recangle(t_cub_img *to_img, t_color color, int fill, t_modify mod);
t_color get_pixel(t_cub_img *img, int x, int y);
t_color rgba_to_int_color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
void set_pixel(t_cub_img *img, int x, int y, t_color color);
void render(t_data *data);
void init_modify(t_modify *mod);
void raycaster(t_data *data);
void draw_line(t_data *data, int x, int line_height, t_raycast raycast);

/////////////// UI ///////////////

void draw_minimap(t_data *data, int map_size);
int draw_hud(t_data *data);
int update_minimap(t_data *data);

//////////// PARS/INIT ////////////

int init_mlx(t_data *data);
int pars(t_data *data, char **argv);
int init_mini_map(t_data *data);
int init_ui(t_data *data);
int init_data(t_data *data);

/////////////// FREE //////////////

int free_and_exit(t_data *data);
int free_one_and_exit(void *ptr, int code);
int free_too_and_exit(void *ptr1, void *ptr2, int code);
int free_three_and_exit(void *ptr1, void *ptr2, void *ptr3, int code);
int	free_array(char **tab, int code);

//////////////// MAP //////////////

char get_map_id(t_map map, size_t x, size_t y);
int set_map_id(t_map map, char id, size_t x, size_t y);

////////////// UTILS //////////////

int get_tablen(char **tab);
size_t get_long_line_in_array(char **array);
void print_char_array(char **array);
void	itoa_buff(int n, char buff[11]);

////////////// ERROR //////////////

int print_error(int code);

#endif
