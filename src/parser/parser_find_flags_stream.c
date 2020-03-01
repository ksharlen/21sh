/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_find_flags_stream.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <tjonella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:00:42 by tjonella          #+#    #+#             */
/*   Updated: 2020/02/25 00:34:57 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int		flag_stream_valid_check(char *pos_stream, int size)
{
	char	*ptr;

	ptr = pos_stream;
	ptr = ft_skiptabs(ptr + size);
	if (!(check_valid_char_name(*pos_stream)))
	{
		if (*pos_stream && *(pos_stream + 1))
		{
			if (check_valid_char_name(*(pos_stream + 1)))
			{
				*(pos_stream + 2) = '\0';
				put_error_parse(pos_stream, 2);
			}
			else
			{
				*(pos_stream + 1) = '\0';
				put_error_parse(pos_stream, 2);
			}
		}
		else
			put_error_parse(pos_stream, 2);
		return (0);
	}
	return (1);
}

int				find_flag_stream(char *pos_stream, t_red_stream *stream_list)
{
	if (*pos_stream == *(pos_stream + 1))
	{
		if (!flag_stream_valid_check(pos_stream, 2))
			return (1);
		if (*pos_stream == '>')
			stream_list->flag_file = 2;
		else if (*pos_stream == '<')
			stream_list->flag_file = -2;
		else
			return (1);
	}
	else if (*pos_stream != *(pos_stream + 1) && !check_valid_char_name(*(pos_stream + 1)))
	{
		if (!flag_stream_valid_check(pos_stream, 1))
			return (1);
		if (*pos_stream == '>')
			stream_list->flag_file = 1;
		else if (*pos_stream == '<')
			stream_list->flag_file = -1;
		else
			return (1);
	}
	else
		return (1);
	if (stream_list->next)
		stream_list->next->flag_file = stream_list->flag_file;
	return (0);
}