/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 03:10:16 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 18:27:34 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh_init.h"

static void	init_user(struct s_user_info *curr_user)
{
	struct passwd	*pw_user;
	char			*user_name;
	char			*home_dir;

	if (curr_user)
	{
		CLEAN(curr_user->user, SH21_MAX_NAME);
		CLEAN(curr_user->home_d, SH21_MAX_PATH);
		curr_user->u_pid = getuid();
		user_name = getenv("USER");
		home_dir = getenv("HOME");
		if (!user_name || !home_dir)
		{
			pw_user = getpwuid(curr_user->u_pid);
			ft_strcpy(curr_user->user, pw_user->pw_name);
			ft_strcpy(curr_user->home_d, pw_user->pw_dir);
		}
		else
		{
			ft_strcpy(curr_user->user, user_name);
			ft_strcpy(curr_user->home_d, home_dir);
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

void		sh21_init(t_init *init, char **env)
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
