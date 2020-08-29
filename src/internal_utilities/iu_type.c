/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iu_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:41:27 by mdelphia          #+#    #+#             */
/*   Updated: 2020/04/09 16:13:09 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_utilities.h"

static int	valid_cmd(t_pars_list *list, char *args)
{
	if (write_this_dir(list, args))
		return (1);
	return (0);
}

int			iu_type(t_exec_lst *execlist, t_pars_list *list)
{
	int status;
	char **args;

	status = GOOD_RUN_CMD;
	args = list->pars_args;
	while (*(++args))
	{
		if (check_cmd(*args))
		{
			ft_putstr(*args);
			ft_putstr(" is a shell builtin\n");
		}
		else if (valid_cmd(list, *args))
		{
			ft_putstr(*args);
			ft_putstr(" is ");
			ft_putstr(list->name_run_func);
			ft_putchar('\n');
		}
		else
		{
			ft_putstr(*args);
			ft_putstr(" not found\n");
			status = ERROR_RUN_CMD;
		}
	}
	return (status);
}
