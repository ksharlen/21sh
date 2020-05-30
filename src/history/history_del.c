/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 10:11:25 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 18:15:31 by ksharlen         ###   ########.fr       */
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
