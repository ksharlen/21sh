/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 21:51:34 by dsandshr          #+#    #+#             */
/*   Updated: 2020/02/08 19:51:48 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

char	*history_get_bottom_cmd(t_history *hist)
{
	if (hist->h_list->next)
	{
		hist->h_list = hist->h_list->next;
		return (hist->h_list->comand);
	}
	else if (hist->h_list == hist->end)
		return(NULL);
	return (hist->h_list->comand);
}

char	*history_get_top_cmd(t_history *hist)
{
	if (hist->h_list->prev)
	{
		hist->h_list = hist->h_list->prev;
		return (hist->h_list->comand);
	}
	else if (hist->h_list == hist->beg)
		return (hist->beg->comand);
	return(hist->h_list->comand);
}
