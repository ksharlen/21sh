/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:24:48 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/03 22:04:34 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_STRUCT_H
# define INPUT_STRUCT_H

# include <unistd.h>
# include <sys/types.h>
# include <limits.h>
# include <stdlib.h>
# include <termios.h>

# include "libft.h"
# include "gap_buf.h"
# include "input_macros.h"

enum	e_key
{
	KEY_LEFT_ARROW = 1000,
	KEY_RIGHT_ARROW,
	KEY_UP_ARROW,
	KEY_DOWN_ARROW,
	KEY_HOME,
	KEY_END,
	KEY_DEL,
	KEY_PAGE_UP, //?option + arrow_up (on_func keyboard)
	KEY_PAGE_DOWN,//?option + arrow_down (on func keyboard)
	KEY_BCKSPACE = 127,
	KEY_NEW_LINE = 13
};

struct s_key
{
	char	read_key[5];
	int		key;
	ssize_t	nread;
};

struct s_cursor
{
	int32_t	x;
	int32_t	y;
};

// struct s_line
// {
// 	size_t	rest_line;
// 	size_t	size_line;
// };

struct s_win
{
	int	cols;
	int	rows;
};

struct s_input
{
	t_gapbuf		gap;
	struct termios	cfg_cpy;
	struct s_cursor	cr;
	struct s_win	win;
};

#endif
