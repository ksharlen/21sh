/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:08:43 by ksharlen          #+#    #+#             */
/*   Updated: 2020/01/15 15:08:45 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

void	ft_qu_remove(t_queue *qu, void (*del)())
{
	if (qu && qu->beg_dek)
	{
		ft_dlc_del_list(&qu->beg_dek, del);
	}
}

void	ft_qu_init(t_queue *qu)
{
	qu->beg_dek = NULL;
}

void	ft_qu_push(t_queue *qu, void *data, size_t size_data)
{
	if (qu)
	{
		ft_dlc_add_end(&qu->beg_dek, data, size_data);
	}
}

void	*ft_qu_pop(t_queue *qu)
{
	t_dlc	*elem;
	void	*data;

	data = NULL;
	if (qu)
	{
		elem = ft_dlc_get_beg(&qu->beg_dek);
		if (elem)
		{
			data = elem->data;
			ft_dlc_del_struct(&elem);
		}
	}
	return (data);
}

int		ft_qu_is_empty(t_queue *qu)
{
	return (qu->beg_dek == NULL);
}
