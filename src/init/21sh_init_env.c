/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh_init_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:28:46 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 16:03:41 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh_init.h"

#define TERM	env->term
#define SHELL	env->shell
#define SHLVL	env->shlvl
#define OLD_PWD	env->old_pwd
#define PWD		env->pwd
#define PATH	env->path
#define HOME	env->home
#define USER	env->user

static void	clean_garbage(struct s_start_env *env)
{
	CLEAN(SHLVL, SH21_MAX_PATH);
	CLEAN(TERM, SH21_MAX_PATH);
	CLEAN(SHELL, SH21_MAX_PATH);
	CLEAN(OLD_PWD, SH21_MAX_PATH);
	CLEAN(PWD, SH21_MAX_PATH);
	CLEAN(PATH, SH21_MAX_PATH);
	CLEAN(HOME, SH21_MAX_PATH);
	CLEAN(USER, SH21_MAX_PATH);
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
		CHK_NULL_PTR(ret_itoa = ft_itoa(num_shlvl), E_MALLOC, P_N);
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

void	sh21_init_start_env(struct s_start_env *env, const struct s_user_info *user)
{
	char	*buf;

	FT_CLEAN_UP(buf, SH21_MAX_PATH);
	clean_garbage(env);
	sh21_setenv("TERM", "xterm-256color", FLAG_OFF);
	ft_strcpy(env->term, sh21_getenv("TERM"));
	ft_strcpy(USER, user->user);
	sh21_setenv("USER", user->user, FLAG_ON);
	sh21_setenv("SHELL", P_N, FLAG_ON);
	set_shlvl(env->shlvl);
	ft_strcpy(SHELL, P_N);
	getcwd(buf, SH21_MAX_PATH);
	sh21_setenv("PWD", buf, FLAG_ON);
	ft_strcpy(PWD, buf);
	ft_strcpy(OLD_PWD, buf);
	sh21_setenv("OLD_PWD", buf, FLAG_ON);
	get_path_env(PATH, buf);
	sh21_setenv("PATH", PATH, FLAG_OFF);
	ft_strcpy(HOME, user->home_d);
	sh21_setenv("HOME", HOME, FLAG_ON);
}
