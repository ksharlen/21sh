/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 19:42:09 by ksharlen          #+#    #+#             */
/*   Updated: 2020/03/15 19:57:20 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void		get_ret_child(const int stat_child)
{
	if (WIFEXITED(stat_child))
		g_path.ret_child = WEXITSTATUS(stat_child);
	else
		g_path.ret_child = WIFSIGNALED(stat_child);
}

void			status_child(int stat_child,
	pid_t pid_child, const char *path_cmd)
{
	char	*lvl_proccess;

	lvl_proccess = sh21_getenv(SHLVL);
	if (!lvl_proccess)
		lvl_proccess = "1";
	if (stat_child == SIGINT)
		ft_printf("\n");
	else if (stat_child == SIGSEGV)
		print_sig_error(lvl_proccess, pid_child, ESIG, path_cmd);
	else if (stat_child == SIGABRT)
		print_sig_error(lvl_proccess, pid_child, EABR, path_cmd);
	else if (stat_child == SIGBUS)
		print_sig_error(lvl_proccess, pid_child, EBUS, path_cmd);
	else if (stat_child == SIGFPE)
		print_sig_error(lvl_proccess, pid_child, FPOT, path_cmd);
	else if (stat_child == SIGQUIT)
	{
		ft_printf("\n");
		print_sig_error(lvl_proccess, pid_child, QUIT, path_cmd);
	}
	get_ret_child(stat_child);
}

void			handler_parrent(int sig)
{
	if (sig == SIGINT || sig == SIGQUIT)
	{
		ft_printf("\n");
		minishell_greeting();
	}
}

void			handler_child(int sig)
{
	if (sig == SIGINT)
		exit(EXIT_FAILURE);
	else if (sig == SIGQUIT)
		;
}

void			minishell_signals(void (*handler)(int))
{
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
}
