/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 03:13:25 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/19 18:24:55 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_STRUCT_H
# define SH_STRUCT_H

# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <termios.h>

# include "libft.h"
# include "gap_buf.h"
# include "sh_limits.h"

/*
**ENUMS
*/
enum		e_greet_mode
{
	MODE_DFLT,
	MODE_QUOTE,
	MODE_DQUOTE,
	MODE_BQUOTE,
};

enum		e_key
{
	KEY_LEFT_ARROW = 1000,
	KEY_RIGHT_ARROW,
	KEY_UP_ARROW,
	KEY_DOWN_ARROW,
	KEY_HOME,
	KEY_END,
	KEY_DEL,
	KEY_PAGE_UP,
	KEY_PAGE_DOWN,
	KEY_SHIFT_L_ARROW,
	KEY_SHIFT_R_ARROW,
	KEY_SHIFT_U_ARROW,
	KEY_SHIFT_D_ARROW,
	KEY_CTR_L_ARROW,
	KEY_CTR_R_ARROW,
	KEY_CTR_U_ARROW,
	KEY_CTR_D_ARROW,
	KEY_BCKSPACE = 127,
	KEY_NEW_LINE = 13
};

/*
**GLOBAL
*/
typedef struct			s_term_var
{
	char 				*tty_name;							// храниет адрес терминала //Раньше было path_name
	int 				exec_status;						// хранит статус последней запущеной команды
	pid_t				pid_last;							// хранит pid последней запущеной команды
}						t_term_var;

/*
**PARSER
*/
typedef struct			s_red_stream
{
	struct s_red_stream	*next;
	struct s_red_stream	*left;
	int					stream_a;						// какой поток будет перенаправлен или закрыт, при соответствующем флаге
	int					stream_in;						// в какой поток будет перенаправлен
	char				stream_name[BUFSIZ];			// в какой файл будет направлен поток
	int					fd_file;						// дескриптор открытого файла (по умолчанию -1, будет заполнено в exec)
	int					flag_file;						// флаг файла: ">" = "1", ">>" = "2", "<" = "-1" (по умолчанию 0)
	int					flag_close;						// флаг о закрытии дескриптора (по умолчанию 0)
	int 				save_std;						// запоминает дублированный дескриптор стандартного вывода (по умолчанию -1)
}						t_red_stream;

typedef struct			s_pars_list
{
	struct s_pars_list	*right;
	struct s_pars_list	*left;
	char				*name_func;						// имя запускаемой программы
	char				name_run_func[BUFSIZ];			// имя запускаемой программы с путём запуска
	char				**pars_args;					// разбитые аргументы строки
	int					status;							// статус завершения вызванной программы (заполню)
	pid_t				pid;
	t_red_stream		*stream_list;					// структура для перенаправления потоков
	int 				f_delimiter;					// флаг разделителей команд
	unsigned short		nbr_ampersant;
	char				**str_status;					// строки в которых нужно вставить статус
	char 				**str_lastpid;
}						t_pars_list;

/*
**HISTORY
*/
typedef struct	s_history_list
{
	char					*comand;
	struct s_history_list	*next;
	struct s_history_list	*prev;
	size_t					location;
}				t_history_list;

typedef struct	s_history
{
	t_history_list			*h_list;
	t_history_list			*beg;
	t_history_list			*end;
	size_t					size;
	int						fd;
}				t_history;

/*
**INPUT_STRUCT
*/
typedef struct	s_greet
{
	char		time[SIZE_TIME + 1];
	char		user[SIZE_NAME + 1];
	char		curr_d[SIZE_DIR + 1];
	char		mode;
	int			len;
}				t_greet;

struct			s_user_info
{
	char	user[SH21_MAX_NAME];
	char	home_d[SH21_MAX_PATH];
	pid_t	u_pid;
};

struct			s_cursor
{
	int32_t	x;
	int32_t	y;
};

struct			s_win
{
	int	cols;
	int	rows;
};

struct			s_input
{
	t_gapbuf			gap;
	char				*buf;
	char				*str_for_parse;
	struct termios		cfg_cpy;
	struct s_cursor		cr;
	struct s_cursor		save_refresh_pos;
	struct s_win		win;
	struct s_user_info	u_info;
	t_history			*hist;
	t_greet				greet;
	t_key				key;
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
	char	path[SH21_MAX_PATH];
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
