/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 03:13:25 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/03 21:24:12 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH21_STRUCT_H
# define SH21_STRUCT_H

# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>

# include "21sh_limits.h"
# include "input_struct.h"

struct			s_path
{
	char	home_d[SH21_MAX_PATH];
	char	curr_d[SH21_MAX_PATH];
};

struct			s_user_info
{
	char	user[SH21_MAX_NAME];
	char	home_d[SH21_MAX_PATH];
	pid_t	u_pid;
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