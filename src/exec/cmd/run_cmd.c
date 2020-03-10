/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:56:21 by mdelphia          #+#    #+#             */
/*   Updated: 2020/03/08 23:29:32 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char **skip_env_argv(char **pars_list, int *argc)
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
	//list->pars_args //подвинуть... поменять namefunc
	//list->name_func = list->pars_args[0];
	char	**cpy_environ_src;
	int		argc;

	argc = ft_lineslen(list->pars_args);
	cpy_environ_src = g_sh_environ;
	sh21_env(argc, list->pars_args, NULL);//
	list->pars_args = skip_env_argv(list->pars_args, &argc);
// printf("argc: %zd\n", argc);
// exit(EXIT_FAILURE);
// printf("argc: %zd\n", argc);
// ft_print_lines(list->pars_args);
// exit(EXIT_FAILURE);
	//
	// check_run(execlist, &list);
	if (argc > 0)
	{
		list->name_func = list->pars_args[0];
		// check_choice(execlist, list);
		check_run(execlist, &list);
	}
	//free(g_sh_environ);
	g_sh_environ = cpy_environ_src;
	//delete env_form_cmd
}

// поиск и запуск необходимой внутренней команды
static int	find_and_run_cmd(t_exec_lst execlist, t_pars_list *list)
{
	int		argc;

	argc = ft_lineslen(list->pars_args);
	if (!ft_strcmp("true", list->name_func))
		list->status = cmd_true();
	else if (!ft_strcmp("false", list->name_func))
		list->status = cmd_false();
	else if (!ft_strcmp("cd", list->name_func))
		list->status = sh21_cd(argc, list->pars_args, NULL);	//////// замена
	else if (!ft_strcmp("echo", list->name_func))
		list->status = sh21_echo(argc, list->pars_args, NULL);	//////// замена
	else if (!ft_strcmp("pwd", list->name_func))
		list->status = sh21_pwd(argc, list->pars_args, NULL);	//////// замена
	else if (!ft_strcmp("setenv", list->name_func))//TODO: need think
		list->status = sh21_setenv(NULL, NULL, 0);	//////// замена
	else if (!ft_strcmp("unsetenv", list->name_func))//TODO: this too
		list->status = sh21_unsetenv(NULL);	//////// замена
	else if (!ft_strcmp("exit", list->name_func))
		exit(EXIT_SUCCESS);
	else if (!ft_strcmp("env", list->name_func))//TODO: need add
		exec_env(execlist, list);
	//else if (sh21_getenv());
		// list->status = minishell_env(0, NULL, NULL);	//////// замена
	return (g_term_lst.exec_status = list->status);
}

int			run_cmd(t_exec_lst execlist, t_pars_list *list)
{
	cmd_check_var(list);
	return (find_and_run_cmd(execlist, list));
}