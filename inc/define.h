/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:59:21 by gchauvet          #+#    #+#             */
/*   Updated: 2025/10/28 13:04:38 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
#define DEFINE_H

//==========================================================

//windows size
#define WIN_W 1920
#define WIN_H 1080

// r:0 g:0 b:0 a:255
#define NONE_COLOR_XPM 4278190080

#define FONT_CHAR_SIZE 16

//math define
#define PI 3.14159

#define DEG_TO_RAD(d) (d * PI / 180)

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

#define NB_ERROR_CODE 11

//init error
#define RM_INIT_TEX "Failed to load textures."
#define RM_INIT_MLX "Failed to initialize MLX."
#define RM_INIT_WIN "Failed to load window."

//map and info parsing
#define RM_WRONG_MAP_FILE "Wrong arg : map argument not found."
#define RM_WRONG_ARG "Wrong arg : try : ./cub3D <map path>"
#define RM_MAP_TEX_PATH "Map : The path of the textures is not valid."
#define RM_MAP_COLOR "Map : The colors for the ceiling or the floor are not valid."
#define RM_MAP_DONT_CLOSE "Map : The map is not closed."
#define RM_MAP_NO_PLAYER_FOUND "Map : Player not found."
#define RM_MAP_UNEXPECTED_CHAR "Map : Unexpected characher found in the map."
#define RM_MAP_NO_TEX_FOUND "Map : A texture are missing."
#define RM_MAP_NO_COLOR_FOUND "Map : Color are missing for the ciling or the floor."//11

typedef enum e_error_code
{
    ER_INIT_TEX,
    ER_INIT_MLX,
    ER_INIT_WIN,
    ER_WRONG_MAP_FILE,
    ER_WRONG_ARG,
    ER_MAP_TEX_PATH,
    ER_MAP_COLOR,
    ER_MAP_DONT_CLOSE,
    ER_MAP_NO_PLAYER_FOUND,
    ER_MAP_UNEXPECTED_CHAR,
    ER_MAP_NO_TEX_FOUND,
    ER_MAP_NO_COLOR_FOUND
} t_error_code;

//================

//==========================================================

#endif