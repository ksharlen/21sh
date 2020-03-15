/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:56:21 by mdelphia          #+#    #+#             */
/*   Updated: 2020/03/15 20:12:35 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char	**skip_env_argv(char **pars_list, int *argc)
{
	size_t	i;
	char	**cpy_prs;
	char	**new_args;
	size_t	skip_args;

	i = 0;
	skip_args = 0;
	cpy_prs = pars_list;
	++pars_list;
	--(*argc);
	while (i < *argc)
	{
		if (**pars_list == '-')
		{
			++pars_list;
			++skip_args;
		}
		++i;
	}
	new_args = ft_linedup(pars_list);
	ft_strdel_split(cpy_prs);
	*argc -= skip_args;
	return (new_args);
}

static void	exec_env(t_exec_lst execlist, t_pars_list *list)
{
	char	**cpy_environ_src;
	int		argc;

	argc = ft_lineslen(list->pars_args);
	cpy_environ_src = g_sh_environ;
	sh21_env(argc, list->pars_args, NULL);
	list->pars_args = skip_env_argv(list->pars_args, &argc);
	if (argc > 0)
	{
		list->name_func = list->pars_args[0];
		check_run(execlist, &list);
	}
	g_sh_environ = cpy_environ_src;
}

static int	find_and_run_cmd(t_exec_lst execlist, t_pars_list *list)
{
	int		argc;

	argc = ft_lineslen(list->pars_args);
	if (!ft_strcmp("true", list->name_func))
		list->status = cmd_true();
	else if (!ft_strcmp("false", list->name_func))
		list->status = cmd_false();
	else if (!ft_strcmp("cd", list->name_func))
		list->status = sh21_cd(argc, list->pars_args, NULL);
	else if (!ft_strcmp("echo", list->name_func))
		list->status = sh21_echo(argc, list->pars_args, NULL);
	else if (!ft_strcmp("pwd", list->name_func))
		list->status = sh21_pwd(argc, list->pars_args, NULL);
	else if (!ft_strcmp("setenv", list->name_func))
		list->status = sh21_setenv(list->pars_args[1], list->pars_args[2], 0);
	else if (!ft_strcmp("unsetenv", list->name_func))
		list->status = sh21_unsetenv(list->pars_args[1]);
	else if (!ft_strcmp("exit", list->name_func))
		exit_with_code(list);
	else if (!ft_strcmp("env", list->name_func))
		exec_env(execlist, list);
	return (g_term_lst.exec_status = list->status);
}

int			run_cmd(t_exec_lst execlist, t_pars_list *list)
{
	cmd_check_var(list);
	return (find_and_run_cmd(execlist, list));
}
