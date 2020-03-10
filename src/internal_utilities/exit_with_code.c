/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <tjonella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 21:00:26 by tjonella          #+#    #+#             */
/*   Updated: 2020/03/10 20:04:33 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_utilities.h"

void	exit_with_code(t_pars_list *list)
{
	int		count_args;
	char	**ptr;

	if (list->pars_args && list->pars_args + 1)
	{
		ptr = list->pars_args + 1;
		count_args = 1;
		while (*ptr && ++ptr)
			count_args++;
		if (count_args > 2)
		{
			ft_putstr_fd("exit: too many arguments\n", 2);
			return ;
		}
		if (ft_strcmp(*(list->pars_args + 1), ft_itoa(ft_atoi(*(list->pars_args + 1)))))
		{
			ft_putstr_fd("exit: ", 2);
			ft_putstr_fd(*(list->pars_args + 1), 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit(255);
		}
		else
			exit((unsigned char)ft_atoi(*(list->pars_args + 1)));
	}
	exit(0);
}