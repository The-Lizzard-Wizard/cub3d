/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:59:21 by gchauvet          #+#    #+#             */
/*   Updated: 2026/01/25 12:54:04 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

//==========================================================

//windows size
# define WIN_W 1920
# define WIN_H 1080

# ifndef BONUS
#  define BONUS 0
# endif
// r:0 g:0 b:0 a:255
# define NONE_COLOR_XPM 4278190080

# define FONT_CHAR_SIZE 16

//draw type for shapes
# define FILL 1
# define LINE 2

# define FOG 5

// thing
typedef enum e_thing_type
{
	THING_COLLECT,
	THING_KIWI,
	THING_CHICKEN,
	THING_BULLET,
	THING_PROPS,
	THING_BANANA,
	THING_MAGIC_ROD,
	THING_Y_KEY,
	THING_R_KEY,
	THING_B_KEY,
	THING_G_KEY
}	t_thing_type;

# define THING_BOX_W 0.3
# define THING_BOX_H 0.3

//================
//= error messages
//=
//=  To add an error message, add +1 to NB_ERROR_CODE.
//=  Define your message with RM_ at the beginning of the name.
//=  Add a code for your message in e_error_code.
//=  Then, in init_error function in error.c, add:
//=      er_list[ER_MESSAGE_CODE] = RM_MESSAGE;
//=
//================

# define NB_ERROR_CODE 17

//init error
# define RM_INIT_TEX "MLX : Failed to load textures."
# define RM_INIT_MLX "MLX : Failed to initialize MLX."
# define RM_INIT_WIN "MLX : Failed to load window."
# define RM_INIT_SC_IMG "MLX : Failed to load screen image."
# define RM_INIT_UI_IMG "UI : Failed to load images."
# define RM_INIT_UI_MIMP "UI : Failed to initialize the minimap."

//map and info parsing
# define RM_MALLOC_ER "Error : Malloc error."
# define RM_WRONG_MAP_FILE "Wrong arg : map not found."
# define RM_WRONG_ARG "Wrong arg : try : ./cub3D <map path>"
# define RM_MAP_TEX_PATH "Map : The path of the textures is not valid."
# define RM_MAP_COLOR "Map : Invalid floor or ceiling color."
# define RM_MAP_NOT_CLOSE "Map : The map is not closed."
# define RM_MAP_NO_PLAYER_FOUND "Map : Player not found."
# define RM_MAP_TOO_MANY_PLAYER "Map : Too many player found."
# define RM_MAP_UNEXPECTED_CHAR "Map : Unexpected character found in the map."
# define RM_MAP_NO_TEX_FOUND "Map : A texture are missing."
# define RM_MAP_NO_COLOR_FOUND "Map : Missing color on ceiling or floor."

typedef enum e_error_code
{
	ER_INIT_TEX,
	ER_INIT_MLX,
	ER_INIT_WIN,
	ER_INIT_SC_IMG,
	ER_MALLOC_ER,
	ER_WRONG_MAP_FILE,
	ER_WRONG_ARG,
	ER_MAP_TEX_PATH,
	ER_MAP_COLOR,
	ER_MAP_NOT_CLOSE,
	ER_MAP_NO_PLAYER_FOUND,
	ER_MAP_UNEXPECTED_CHAR,
	ER_MAP_NO_TEX_FOUND,
	ER_MAP_NO_COLOR_FOUND,
	ER_INIT_UI_IMG,
	ER_INIT_UI_MIMP,
	ER_MAP_TOO_MANY_PLAYER
}	t_error_code;

#endif