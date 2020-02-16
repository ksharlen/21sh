/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 03:10:16 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 16:01:42 by ksharlen         ###   ########.fr       */
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
		CLEAN(USER, SH21_MAX_NAME);
		CLEAN(HOME, SH21_MAX_PATH);
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

static void	init_path(struct s_path *path, char *home_dir)
{
	CLEAN(path->home_d, SH21_MAX_PATH);
	CLEAN(path->curr_d, SH21_MAX_PATH);
	getcwd(path->curr_d, SH21_MAX_PATH);
	ft_strcpy(path->home_d, home_dir);
}

void	sh21_init(t_init *init, char **env)
{
	if (init)
	{
		init_env(env);
		init_user(&init->u_inf);
		sh21_init_start_env(&init->env, &init->u_inf);
		init_path(&init->path, init->u_inf.home_d);
		init->inp.hist = history_init();
		init->inp.u_info = init->u_inf;
		init->inp.buf = NULL;
		input_init(&init->inp);
	}
}
