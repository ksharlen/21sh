/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_find_flags_stream.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <tjonella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:00:42 by tjonella          #+#    #+#             */
/*   Updated: 2020/03/17 13:20:39 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int				put_error_flags(char *pos_stream, int sz)
{
	*(pos_stream + sz) = '\0';
	put_error_parse(pos_stream, sz);
	return (1);
}

static int		fill_flags_stream(char pos_stream, int size,
					t_red_stream *stream_list)
{
	if (pos_stream == '>')
		stream_list->flag_file = size;
	else if (pos_stream == '<')
		stream_list->flag_file = -size;
	else
		return (1);
	return (0);
}

static int		flag_stream_valid_check(char *pos_stream, int size)
{
	char	*ptr;

	ptr = pos_stream;
	ptr = ft_skiptabs(ptr + size);
	if (!(check_valid_char_name(*ptr)) || *ptr == '&')
	{
		if (*pos_stream && *(pos_stream + 1))
		{
			if (check_valid_char_name(*(ptr)) && *ptr != '&')
				put_error_flags(pos_stream, 2);
			else
				return (0);
		}
		else
			put_error_parse(ptr, 1);
		return (0);
	}
	return (1);
}

int				find_flag_stream(char *pos_stream, t_red_stream *stream_list)
{
	if (*pos_stream == *(pos_stream + 1))
	{
		if (flag_stream_valid_check(pos_stream, 2))
			return (put_error_flags(pos_stream, 2));
		if (fill_flags_stream(*pos_stream, 2, stream_list))
			return (put_error_flags(pos_stream, 2));
	}
	else if (*pos_stream != *(pos_stream + 1) &&
		(!check_valid_char_name(*(pos_stream + 1)) || *(pos_stream + 1) == '&'))
	{
		if (flag_stream_valid_check(pos_stream, 1))
			return (put_error_flags(pos_stream, 1));
		if (fill_flags_stream(*pos_stream, 1, stream_list))
			return (put_error_flags(pos_stream, 1));
	}
	else
		return (put_error_flags(pos_stream, 1));
	if (stream_list->next)
		stream_list->next->flag_file = stream_list->flag_file;
	return (0);
}
