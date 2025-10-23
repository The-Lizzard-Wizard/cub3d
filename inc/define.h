/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:59:21 by gchauvet          #+#    #+#             */
/*   Updated: 2025/10/23 17:48:44 by gchauvet         ###   ########.fr       */
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

#define NB_ERROR_CODE 10

//init error
#define RM_INIT_TEX "RM_INIT_TEX"
#define RM_INIT_MLX "RM_INIT_MLX"
#define RM_INIT_WIN "RM_INIT_WIN"

//map and info parsing
#define RM_WRONG_ARG "RM_WRONG_ARG"
#define RM_MAP_TEX_PATH "RM_MAP_TEX_PATH"
#define RM_MAP_COLOR "RM_MAP_COLOR"
#define RM_MAP_DONT_CLOSE "RM_MAP_DONT_CLOSE"
#define RM_MAP_NO_PLAYER_FOUND "RM_MAP_NO_PLAYER_FOUND"
#define RM_MAP_UNEXPECTED_CHAR "RM_MAP_UNEXPECTED_CHAR"
#define RM_MAP_NO_TEX_FOUND "RM_MAP_NO_TEX_FOUND"
#define RM_MAP_NO_COLOR_FOUND "RM_MAP_NO_COLOR_FOUND"//10

typedef enum e_error_code
{
    ER_INIT_TEX,
    ER_INIT_MLX,
    ER_INIT_WIN,
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