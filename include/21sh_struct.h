/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 03:13:25 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/04 01:05:53 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH21_STRUCT_H
# define SH21_STRUCT_H

# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <termios.h>

# include "libft.h"
# include "gap_buf.h"
# include "21sh_limits.h"

/*
**ENUMS
*/
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
	KEY_SHIFT_L_ARROW,
	KEY_SHIFT_R_ARROW,
	KEY_BCKSPACE = 127,
	KEY_NEW_LINE = 13
};

/*
**INPUT_STRUCT
*/
typedef struct	s_greet
{
	char		time[SIZE_TIME + 1];
	char		user[SIZE_NAME + 1];
	char		curr_d[SIZE_DIR + 1];
}				t_greet;


struct			s_user_info
{
	char	user[SH21_MAX_NAME];
	char	home_d[SH21_MAX_PATH];
	pid_t	u_pid;
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

struct s_win
{
	int	cols;
	int	rows;
};

struct s_input
{
	t_gapbuf			gap;
	struct termios		cfg_cpy;
	struct s_cursor		cr;
	struct s_cursor		save_refresh_pos;
	struct s_win		win;
	struct s_user_info	u_info;
	int					key;
};

/*
**INIT_STRUCT
*/
struct			s_path
{
	char	home_d[SH21_MAX_PATH];
	char	curr_d[SH21_MAX_PATH];
};

struct			s_start_env
{
	char	shlvl[SH21_MAX_PATH];
	char	term[SH21_MAX_PATH];
	char	shell[SH21_MAX_PATH];
	char	pwd[SH21_MAX_PATH];
	char	old_pwd[SH21_MAX_PATH];
	char	path[SH21_MAX_PATH]; //!Не уверен пока что
	char	home[SH21_MAX_PATH];
	char	user[SH21_MAX_PATH];
};

struct			s_shell
{
	int8_t		shlvl;
};

typedef struct	s_init
{
	struct s_path		path;
	struct s_start_env	env;
	struct s_user_info	u_inf;
	struct s_shell		shell;
	struct s_input		inp;
}				t_init;

#endif