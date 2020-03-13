/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <tjonella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 21:00:26 by tjonella          #+#    #+#             */
/*   Updated: 2020/03/13 19:03:37 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_utilities.h"

static	int	found_count_args(t_pars_list *list)
{
	int		count_args;
	char	**ptr;

	ptr = list->pars_args + 1;
	count_args = 1;
	while (*ptr && ++ptr)
		count_args++;
	return (count_args);
}

static void	exit_put_args(t_pars_list *list, char **tmp_str)
{
	free(*tmp_str);
	exit((unsigned char)ft_atoi(*(list->pars_args + 1)));
}

static void	exit_put_error(t_pars_list *list, char **tmp_str)
{
	free(*tmp_str);
	ft_putstr_fd("exit: ", 2);
	ft_putstr_fd(*(list->pars_args + 1), 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	exit(255);
}

int			exit_with_code(t_pars_list *list)
{
	char	*tmp_str;

	if (list->pars_args && list->pars_args + 1 && *(list->pars_args + 1))
	{
		if (found_count_args(list) > 2)
		{
			ft_putstr_fd("exit: too many arguments\n", 2);
			return (1);
		}
		tmp_str = ft_itoa(ft_atoi(*(list->pars_args + 1)));
		if (ft_strcmp(*(list->pars_args + 1), tmp_str))
			exit_put_error(list, &tmp_str);
		else
			exit_put_args(list, &tmp_str);
	}
	exit(0);
}
