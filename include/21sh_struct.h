/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 03:13:25 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/03 03:16:13 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH21_STRUCT_H
# define SH21_STRUCT_H

# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>

# include "21sh_limits.h"

struct			s_path
{
	char	home_d[FTSH_MAX_PATH];
	char	curr_d[FTSH_MAX_PATH];
};

struct			s_user_info
{
	char	user[FTSH_MAX_NAME];
	char	home_d[FTSH_MAX_PATH];
	pid_t	u_pid;
};

struct			s_start_env
{
	char	shlvl[FTSH_MAX_PATH];
	char	term[FTSH_MAX_PATH];
	char	shell[FTSH_MAX_PATH];
	char	pwd[FTSH_MAX_PATH];
	char	old_pwd[FTSH_MAX_PATH];
	char	path[FTSH_MAX_PATH]; //!Не уверен пока что
	char	home[FTSH_MAX_PATH];
	char	user[FTSH_MAX_PATH];
};

struct			s_shell
{
	int8_t		shlvl;
};

#endif