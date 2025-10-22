/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:50:06 by gchauvet          #+#    #+#             */
/*   Updated: 2025/10/22 15:50:07 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

// First row
// Q W E R T Y U I O P

# define K_Q	113
# define K_W	119
# define K_E	101
# define K_R	114
# define K_T	116
# define K_Y	121
# define K_U	117
# define K_I	105
# define K_O	111
# define K_P	112

// Second row
// A S D F G H J K L

# define K_A	97
# define K_S	115
# define K_D	100
# define K_F	102
# define K_G	103
# define K_H	104
# define K_J	106
# define K_K	107
# define K_L	108

// Third row
// Z X C V B N M

# define K_Z	122
# define K_X	120
# define K_C	99
# define K_V	118
# define K_B	98
# define K_N	110
# define K_M	109

//Number row
// 1 2 3 4 5 6 7 8 9 0

# define K_1	49
# define K_2	50
# define K_3	51
# define K_4	52
# define K_5	53
# define K_6	54
# define K_7	55
# define K_8	56
# define K_9	57
# define K_0	48

// Special char
// - = [ ] ; ' , . /  

# define K_MINUS		45
# define K_EGUAL		61
# define K_BRAK_OPEN	91
# define K_BRAK_CLOSE	93
# define K_SEMICOLON	59
# define K_QUOTE		39
# define K_COMMA		44
# define K_DOT			46
# define K_SLASH		47
# define K_B_SLASH		92
# define K_SPACE		32

// Number pad
// 1 2 3 4 5 6 7 8 9 0 .

# define P_1	65436
# define P_2	65433
# define P_3	65435
# define P_4	65430
# define P_5	65437
# define P_6	65432
# define P_7	65429
# define P_8	65431
# define P_9	65434
# define P_0	65438
# define P_DOT	65439

// Special key
// enter esc tab Lshift Rshift 

# define K_ENTER	65293
# define K_ESC		65307
# define K_TAB		65289
# define K_LSHIFT	65505
# define K_RSHIFT	65506

// Key arrow

# define K_UP		65362
# define K_DOWN		65364
# define K_LEFT		65361
# define K_RIGHT	65363

// Flag for mlx_hook

# define ON_KEYDOWN		2	//int (*f)(int keycode, void *param)
# define ON_KEYUP		3	//int (*f)(int keycode, void *param)
# define ON_MOUSEDOWN	4	//int (*f)(int button, int x, int y, void *param)
# define ON_MOUSEUP		5	//int (*f)(int button, int x, int y, void *param)
# define ON_MOUSMOVE	6	//int (*f)(int x, int y, void *param)
# define ON_EXPOSE		12	//int (*f)(void *param)
# define ON_DESTROY 	17	//int (*f)(void *param)

// Mouse button

# define LMB			1
# define RMB			3
# define MMB			2
# define SCROLL_UP		4
# define SCROLL_DOWM	5

#endif