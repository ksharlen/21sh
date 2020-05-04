/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_choice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:41:27 by mdelphia          #+#    #+#             */
/*   Updated: 2020/04/09 16:13:09 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void		check_choice(t_exec_lst *execlist, t_pars_list *list)
{
	int status;

	while (list)
	{
		if (list->f_delimiter & F_AMPERSANT)
			status = run_ampersant(execlist, &list);
		else
			status = check_run(execlist, &list);
		exec_next_list(status, &list);
	}
}
