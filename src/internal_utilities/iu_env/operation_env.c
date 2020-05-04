/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 00:27:17 by ksharlen          #+#    #+#             */
/*   Updated: 2019/11/10 21:21:47 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_utilities.h"

static void		delete_name(t_exec_lst *execlist, char *const *need_delete)
{
	if (need_delete)
		while (*need_delete)
			sh21_unsetenv(execlist, *need_delete++);
}

char *const		*u_flag(t_exec_lst *execlist, char *const argv[])
{
	char	**split;

	if (argv && *argv)
	{
		if (!ft_strcmp(*argv, "-S"))
		{
			++argv;
			split = s_flag((char *)*argv);
			delete_name(execlist, split);
			ft_strdel_split(split);
			free(split);
			split = NULL;
		}
		else
			sh21_unsetenv(execlist, *argv);
		++argv;
	}
	return (argv);
}

static void		change_value(t_exec_lst *execlist, char *const *need_add)
{
	struct s_nameval nval;

	if (need_add && *need_add)
	{
		while (*need_add)
		{
			nval = split_name_val(*need_add);
			sh21_setenv(execlist, nval.name, nval.value, FLAG_ON);
			ft_strdel(&nval.name);
			ft_strdel(&nval.value);
			++need_add;
		}
	}
}

char	*const	*change_value_name(t_exec_lst *execlist, char *const argv[])
{
	char	**split;

	split = NULL;
	if (*argv && !ft_strcmp(*argv, "-S"))
	{
		++argv;
		if (*argv && ft_strtabchr((char *)*argv, '='))
		{
			split = s_flag(*argv);
			change_value(execlist, split);
			ft_strdel_split(split);
			free(split);
			split = NULL;
		}
	}
	else
	{
		if (*argv && ft_strtabchr(*argv, '='))
		{
			change_value(execlist, (char *const *)*&argv);
			++argv;
		}
	}
	return (argv);
}

char			**s_flag(const char *str)
{
	char	**split;

	split = NULL;
	if (str)
		split = ft_strsplit_skip_space((char *)str, ' ');
	return (split);
}
