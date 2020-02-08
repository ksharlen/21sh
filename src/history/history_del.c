/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 10:11:25 by dsandshr          #+#    #+#             */
/*   Updated: 2020/02/06 10:40:01 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

void		history_del(t_history *hist)
{
	t_history_list *tmp;
	t_history_list *res;

	if (hist)
	{
		if (hist->beg)
		{
			res = hist->beg;
			while (res)
			{
				tmp = res->next;
				ft_strdel(&res->comand);
				free(res);
				res = tmp;
			}
		}
		free(hist);
	}
}