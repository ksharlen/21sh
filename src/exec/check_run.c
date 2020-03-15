/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:41:46 by mdelphia          #+#    #+#             */
/*   Updated: 2020/03/15 20:42:05 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void		ignore_signals(int sig)
{
	(void)sig;
}

static void	cod_child(t_exec_lst execlist, t_pars_list **list)
{
	if (!stream_and_file(*list))
		run_exec(execlist, -1, (*list));
	else
		exit(1);
}

static int	run_fork(t_exec_lst execlist, t_pars_list **list)
{
	pid_t	pid;
	int		stat_child;

	sh21_signals(ignore_signals);
	write_name_run(execlist, *list);
	if ((pid = fork()) < 0)
		error_system(EXEC_ERROR_NUM);
	if (!pid)
	{
		sh21_signals(ignore_signals);
		cod_child(execlist, list);
	}
	else if(wait(&stat_child) == EXEC_ERROR_NUM)
		ft_err_exit(E_WAIT, P_N);
	status_child(stat_child, pid, (*list)->name_run_func);
	(*list)->status = stat_child;
	g_term_lst.pid_last = pid;
	error_system((*list)->status);
	g_term_lst.exec_status = (*list)->status;
	return ((*list)->status);
}

static int	code_pipe(t_exec_lst execlist, t_pars_list **list)
{
	t_pipe_list	**pipelist;
	t_pipe_list	*bufpipelist;

	bufpipelist = NULL;
	pipelist = &bufpipelist;
	run_pipe(execlist, pipelist, list);
	error_system((*list)->status);
	g_term_lst.exec_status = (*list)->status;
	g_term_lst.pid_last = (*list)->pid;
	free_pipe_list(*pipelist);
	return (g_term_lst.exec_status);
}

int			check_run(t_exec_lst execlist, t_pars_list **list)
{
	int			status;

	if ((*list)->f_delimiter & F_PIPE)
		status = code_pipe(execlist, list);
	else if (check_cmd((*list)->name_func))
	{
		stream_save_std((*list)->stream_list);
		stream_and_file(*list);
		status = run_cmd(execlist, *list);
		close_and_open_std((*list)->stream_list);
	}
	else
		status = run_fork(execlist, list);
	return (status);
}
