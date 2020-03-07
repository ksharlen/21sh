/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:56:21 by mdelphia          #+#    #+#             */
/*   Updated: 2020/03/05 15:56:23 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
// поиск и запуск необходимой внутренней команды
static int	find_and_run_cmd(t_pars_list *list)
{
	if (!ft_strcmp("true", list->name_func))
		list->status = cmd_true();
	else if (!ft_strcmp("false", list->name_func))
		list->status = cmd_false();
	else if (!ft_strcmp("cd", list->name_func))
		list->status = sh21_cd(0, list->pars_args, NULL);	//////// замена
	else if (!ft_strcmp("echo", list->name_func))
		list->status = sh21_echo(0, list->pars_args, NULL);	//////// замена
	else if (!ft_strcmp("pwd", list->name_func))
		list->status = sh21_pwd(0, list->pars_args, NULL);	//////// замена
	else if (!ft_strcmp("setenv", list->name_func))//TODO: need think
		list->status = sh21_setenv(NULL, NULL, 0);	//////// замена
	else if (!ft_strcmp("unsetenv", list->name_func))//TODO: this too
		list->status = sh21_unsetenv(NULL);	//////// замена
	else if (!ft_strcmp("exit", list->name_func))
		exit(EXIT_SUCCESS);
	// else if (!ft_strcmp("env", list->name_func))//TODO: need add
		// list->status = minishell_env(0, NULL, NULL);	//////// замена
	return (g_term_lst.exec_status = list->status);
}

int			run_cmd(t_pars_list *list)
{
	cmd_check_var(list);
	return (find_and_run_cmd(list));
}
