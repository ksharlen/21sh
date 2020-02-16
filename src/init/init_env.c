/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:28:46 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 18:33:05 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh_init.h"

static void	clean_garbage(struct s_start_env *env)
{
	ft_bzero(env->shlvl, SH21_MAX_PATH);
	ft_bzero(env->term, SH21_MAX_PATH);
	ft_bzero(env->shell, SH21_MAX_PATH);
	ft_bzero(env->old_pwd, SH21_MAX_PATH);
	ft_bzero(env->pwd, SH21_MAX_PATH);
	ft_bzero(env->path, SH21_MAX_PATH);
	ft_bzero(env->home, SH21_MAX_PATH);
	ft_bzero(env->user, SH21_MAX_PATH);
}

static void	get_path_env(char *path_env, const char *curr_dir)
{
	char	*path;

	if (!(path = getenv("PATH")))
	{
		if (!(path = getenv("path")))
		{
			ft_strcpy(path_env, "/bin:/sbin:");
			ft_strcat(path_env, curr_dir);
		}
		else
			ft_strcpy(path_env, path);
	}
}

static void	set_shlvl(char *shlvl)
{
	char	*p_shlvl;
	char	*ret_itoa;
	int		num_shlvl;

	p_shlvl = getenv("SHLVL");
	if (p_shlvl)
	{
		num_shlvl = ft_atoi(p_shlvl);
		++num_shlvl;
		ret_itoa = ft_itoa(num_shlvl);
		ft_chk_null_ptr(ret_itoa, E_MALLOC);
		sh21_setenv("SHLVL", ret_itoa, FLAG_ON);
		ft_strcpy(ret_itoa, shlvl);
		ft_strdel(&ret_itoa);
	}
	else
	{
		sh21_setenv("SHLVL", "1", FLAG_ON);
		ft_strcpy(shlvl, "1");
	}
}

void		sh21_init_start_env(struct s_start_env *env,
	const struct s_user_info *user)
{
	char	*buf;

	buf = (char[SH21_MAX_PATH]){0};
	clean_garbage(env);
	sh21_setenv("TERM", "xterm-256color", FLAG_OFF);
	ft_strcpy(env->term, sh21_getenv("TERM"));
	ft_strcpy(env->user, user->user);
	sh21_setenv("USER", user->user, FLAG_ON);
	sh21_setenv("SHELL", P_N, FLAG_ON);
	set_shlvl(env->shlvl);
	ft_strcpy(env->shell, P_N);
	getcwd(buf, SH21_MAX_PATH);
	sh21_setenv("PWD", buf, FLAG_ON);
	ft_strcpy(env->pwd, buf);
	ft_strcpy(env->old_pwd, buf);
	sh21_setenv("OLD_PWD", buf, FLAG_ON);
	get_path_env(env->path, buf);
	sh21_setenv("PATH", env->path, FLAG_OFF);
	ft_strcpy(env->home, user->home_d);
	sh21_setenv("HOME", env->home, FLAG_ON);
}
