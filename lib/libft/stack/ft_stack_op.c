/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 17:57:35 by ksharlen          #+#    #+#             */
/*   Updated: 2020/01/25 18:08:20 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stk_init(t_stack *stk)
{
	stk->beg_dek = NULL;
}

void	ft_stk_push(t_stack *stk, void *data, size_t size_data)
{
	if (stk)
		ft_dlc_add_end(&stk->beg_dek, data, size_data);
}

void	*ft_stk_pop(t_stack *stk)
{
	t_dlc	*elem;
	void	*data;

	data = NULL;
	if (stk)
	{
		elem = ft_dlc_get_end(&stk->beg_dek);
		if (elem)
		{
			data = elem->data;
			ft_dlc_del_struct(&elem);
		}
	}
	return (data);
}

int		ft_stk_is_empty(t_stack *stk)
{
	return (stk->beg_dek == NULL);
}
