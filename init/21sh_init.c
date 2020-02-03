/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 03:10:16 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/03 03:12:47 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh_init.h"

#define USER	curr_user->user
#define HOME	curr_user->home_d
#define PUID	curr_user->u_pid

static void	init_user(struct s_user_info *curr_user)
{
	struct passwd	*pw_user;
	char			*user_name;
	char			*home_dir;
//?Подумать еще
	if (curr_user)
	{
		CLEAN(USER, FTSH_MAX_NAME);
		CLEAN(HOME, FTSH_MAX_PATH);
		PUID = getuid();
		user_name = getenv("USER");
		home_dir = getenv("HOME");
		if (!user_name || !home_dir)
		{
			pw_user = getpwuid(PUID);
			ft_strcpy(USER, pw_user->pw_name);
			ft_strcpy(HOME, pw_user->pw_dir);
		}
		else
		{
			ft_strcpy(USER, user_name);
			ft_strcpy(HOME, home_dir);
		}
	}
}

static void	init_env(void)
{
	if (environ)
		environ = ft_linedup(environ);
	else
	{
		environ = (char **)ft_memalloc(sizeof(char *));
		environ[0] = NULL;
	}
}

static void	init_path(struct s_path *path, char *home_dir)
{
	CLEAN(path->home_d, FTSH_MAX_PATH);
	CLEAN(path->curr_d, FTSH_MAX_PATH);
	getcwd(path->curr_d, FTSH_MAX_PATH);
	ft_strcpy(path->home_d, home_dir);
}

void	ftsh_init(t_init *init)
{
	if (init)
	{
		init_env();
		init_user(&init->u_inf);
		ftsh_init_start_env(&init->env, &init->u_inf);
		init_path(&init->path, init->u_inf.home_d);
		// printf("here\n");
	}
}
