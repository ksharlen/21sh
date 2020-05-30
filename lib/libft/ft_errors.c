/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:46:28 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/08 23:56:06 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char *const g_sys_errors[] = {
	"open_error",
	"close_error",
	"read_error",
	"opendir_error",
	"closedir_error",
	"readdir_error",
	"fork_error",
	"wait_error",
	"signal_error",
	"time_error",
	"ctime_error",
	"waitpid_error",
	"kill_error",
	"getcwd_error",
	"malloc_error",
	"chdir_error",
	"stat_error",
	"fstat_error",
	"lstat_error",
	"getpwduid_error",
	"tcgetattr_error",
	"tcsetattr_error",
	"tgetent_error",
	"tgetstr_error",
	"tgoto_error",
	"tputs_error",
	"write_error"
};

void	ft_err_str(t_error nerror, const char *add_text)
{
	if (add_text && *add_text)
		ft_printf("%v%s: %s\n", STDERR_FILENO, add_text, g_sys_errors[nerror]);
	else
		ft_printf("%v%s\n", STDERR_FILENO, g_sys_errors[nerror]);
}

void	ft_err_exit(t_error nerror, const char *add_text)
{
	ft_err_str(nerror, add_text);
	exit(EXIT_FAILURE);
}

void	ft_chk_null_ptr(void *ptr, t_error nerror)
{
	if (!ptr)
		ft_err_exit(nerror, NULL);
}

void	ft_chk_sys_error(ssize_t val, t_error nerror)
{
	if (val == -1)
		ft_err_exit(nerror, NULL);
}
