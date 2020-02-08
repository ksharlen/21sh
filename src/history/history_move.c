/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 21:51:34 by dsandshr          #+#    #+#             */
/*   Updated: 2020/02/02 23:49:33 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

char	*get_bottom_cmd(t_history *hist)
{
	if (hist->h_list->next)
	{
		hist->h_list = hist->h_list->next;
		return (hist->h_list->comand);
	}
	return (NULL);
}

char	*get_top_cmd(t_history *hist)
{
	if (hist->h_list->prev)
	{
		hist->h_list = hist->h_list->prev;
		return (hist->h_list->comand);
	}
	return (NULL);
}
