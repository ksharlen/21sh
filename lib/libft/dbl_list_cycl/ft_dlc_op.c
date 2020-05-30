/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlc_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:06:19 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/08 19:23:17 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dbl_list_cycl.h"

t_dlc	*ft_dlc_new(void *data, size_t size_data)
{
	t_dlc	*new;

	new = NULL;
	if (data && size_data)
	{
		new = ft_memalloc(sizeof(t_dlc));
		if (!new)
			return (NULL);
		new->data = ft_memalloc(sizeof(unsigned char) * size_data);
		ft_memcpy(new->data, data, size_data);
		new->size_data = size_data;
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}

void	ft_dlc_add_beg(t_dlc **beg, void *data, size_t size_data)
{
	t_dlc	*new;

	new = NULL;
	if (beg && data && size_data)
	{
		new = ft_dlc_new(data, size_data);
		if (*beg)
		{
			new->next = (*beg);
			if ((*beg)->next)
			{
				new->prev = (*beg)->prev;
				(*beg)->prev->next = new;
			}
			else
			{
				(*beg)->next = new;
				new->prev = (*beg);
			}
			(*beg)->prev = new;
		}
		(*beg) = new;
	}
}

void	ft_dlc_add_end(t_dlc **beg, void *data, size_t size_data)
{
	t_dlc	*new;

	if (beg && data && size_data)
	{
		new = ft_dlc_new(data, size_data);
		if (*beg)
		{
			new->next = (*beg);
			if ((*beg)->next)
			{
				(*beg)->prev->next = new;
				new->prev = (*beg)->prev;
			}
			else
			{
				(*beg)->next = new;
				new->prev = (*beg);
			}
			(*beg)->prev = new;
		}
		else
			(*beg) = new;
	}
}

t_dlc	*ft_dlc_get_beg(t_dlc **beg)
{
	t_dlc	*taken;

	taken = NULL;
	if (beg && (*beg))
	{
		taken = (*beg);
		(*beg) = (*beg)->next;
		if ((*beg) && (*beg)->next && (*beg)->next->next != (*beg))
		{
			(*beg)->prev = taken->prev;
			taken->prev->next = (*beg);
		}
		else if ((*beg) && (*beg)->next && (*beg)->next->next == (*beg))
		{
			(*beg)->next = NULL;
			(*beg)->prev = NULL;
		}
		else if ((*beg))
			(*beg) = NULL;
		taken->next = NULL;
		taken->prev = NULL;
	}
	return (taken);
}

t_dlc	*ft_dlc_get_end(t_dlc **beg)
{
	t_dlc	*taken;

	taken = NULL;
	if (beg && (*beg))
	{
		taken = (*beg)->prev;
		if ((*beg) && (*beg)->next && (*beg)->next->next != (*beg))
		{
			taken->prev->next = (*beg);
			(*beg)->prev = taken->prev;
		}
		else if ((*beg) && (*beg)->next && (*beg)->next->next == (*beg))
		{
			(*beg)->next = NULL;
			(*beg)->prev = NULL;
		}
		else if (!taken)
		{
			taken = (*beg);
			(*beg) = NULL;
		}
		taken->next = NULL;
		taken->prev = NULL;
	}
	return (taken);
}
