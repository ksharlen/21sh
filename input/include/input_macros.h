/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_macros.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:28:43 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/03 03:03:30 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_MACROS_H
# define INPUT_MACROS_H

# include <limits.h>
# include <sys/types.h>


# define INP_MAX_PATH	PATH_MAX
# define INP_MAX_NAME	NAME_MAX

/*
**KEY_PART
*/
# define CTR_KEY(key) ((key) & 0x1f)
# define ONE_SYM	1
# define ESC		'\x1b'
# define KEY_ARROW(key) ((key) >= 'A' && (key) <= 'D')
# define KEY_HOME_END(key) ((key) == 'H' || (key) == 'F')

/*
**BUF_INPUT
*/
# define INP_SIZE_GAP	20
# define INP_SIZE_BUF	(1024 * 32 - 1) - INP_SIZE_GAP

/*
**ESCAPE_CMD
*/
# define GET_POS_CURSOR	"\e[6n", 4

/*
**TERMCAP
*/
# define T_BUFFER	NULL

//!if CTR_KEY('q') если это истина

#endif
