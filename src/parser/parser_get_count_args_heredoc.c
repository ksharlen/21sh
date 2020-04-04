/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_count_args_heredoc.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 17:19:10 by mdelphia          #+#    #+#             */
/*   Updated: 2020/04/24 17:19:10 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static size_t	get_count_heredoc(t_red_stream *stream_list)
{
	size_t count_args;

	count_args = 0;
	while (stream_list)
	{
		if (stream_list->flag_file == -2)
			++count_args;
		stream_list = stream_list->next;
	}
	return (count_args);
}

size_t			parser_get_count_args_heredoc(t_pars_list *list,
					size_t count_args)
{
	if (list->stream_list)
		count_args += get_count_heredoc(list->stream_list);
	return (count_args);
}
