/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:42:49 by mdelphia          #+#    #+#             */
/*   Updated: 2020/03/15 20:27:25 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	error_run_exec(t_pars_list *list)
{
	ft_putstr_fd("42sh: command not found: ", 2);
	ft_putstr_fd(list->name_func, 2);
	ft_putchar_fd('\n', 2);
	g_term_lst.exec_status = 127;
	exit(127);
}

static int	write_name_environ(char *str, char *buf)
{
	size_t i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		buf[i] = str[i];
		++i;
	}
	buf[i] = '\0';
	return (1);
}

static char	*find_path_param(void)
{
	size_t	i;
	char	buf[BUFSIZ];
	
	i = 0;
	while (g_sh_environ && g_sh_environ[i])
	{
		if (g_sh_environ[i][0] == 'P' &&
			write_name_environ(g_sh_environ[i], buf) &&
			!ft_strcmp(buf, "PATH"))
			return (g_sh_environ[i] + 5);
		++i;
	}
	return (NULL);
}

void		write_name_run(t_exec_lst execlist, t_pars_list *list)
{
	if (write_this_dir(list))
		return ;
	if (exec_fill_way_for_path(find_path_param(), list))
		return ;
	if (exec_fill_way_for_path(execlist.exec_envlist.path, list))
		return ;
	error_run_exec(list);
}

void		run_exec(int fd, t_pars_list *list)
{
	if (fd > -1)
		dup_fd_and_close(fd, STDIN_FILENO);
	if (execve(list->name_run_func, list->pars_args, g_sh_environ))
		error_run_exec(list);
}
