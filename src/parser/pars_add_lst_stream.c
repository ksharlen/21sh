/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_add_lst_stream.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:50:26 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/29 19:08:18 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_red_stream	*create_newlist(void)
{
	t_red_stream	*newlist;

	if (!(newlist = (t_red_stream *)malloc(sizeof(t_red_stream))))
		exit(222);
	newlist->stream_a = -1;
	newlist->stream_in = -1;
	newlist->stream_name[0] = '\0';
	newlist->fd_file = -1;
	newlist->flag_file = 0;
	newlist->flag_close = 0;
	newlist->save_std = -1;
	newlist->next = NULL;
	newlist->prev = NULL;
	newlist->end = NULL;
	return (newlist);
}

static void			add_newlist(t_red_stream **stream_list,
						t_red_stream **newlist)
{
	t_red_stream	*buflist;

	buflist = (*stream_list);
	while (buflist->next)
		buflist = buflist->next;
	buflist->next = (*newlist);
	(*stream_list)->end = (*newlist);
	(*newlist)->prev = buflist;
}

t_red_stream		*pars_add_lst_stream(t_red_stream **stream_list)
{
	t_red_stream	*newlist;

	newlist = create_newlist();
	if (!(*stream_list))
	{
		(*stream_list) = newlist;
		(*stream_list)->end = newlist;
		return (*stream_list);
	}
	add_newlist(stream_list, &newlist);
	return (*stream_list);
}
