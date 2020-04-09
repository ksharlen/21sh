/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_stream_in_lis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:01:14 by mdelphia          #+#    #+#             */
/*   Updated: 2020/03/11 18:01:16 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void	write_minus_sym(char *start, char *end)
{
	while (start < end)
	{
		if (*start)
			*start = -1;
		++start;
	}
}

static char	*write_two_prev(char *pos_stream, t_red_stream *stream_list)
{
	if (stream_list->flag_file > 0)
	{
		stream_list->stream_a = STDOUT_FILENO;
		stream_list->next->stream_a = STDERR_FILENO;
	}
	else
	{
		stream_list->stream_in = STDOUT_FILENO;
		stream_list->next->stream_in = STDERR_FILENO;
	}
	while (*pos_stream != '&')
		--pos_stream;
	return (pos_stream);
}

static char	*write_prev_to_stream(char *str, char *pos_stream,
				t_red_stream *stream_list)
{
	if (stream_list->next)
		str = write_two_prev(pos_stream, stream_list);
	else
		str = write_prev(str, pos_stream, stream_list);
	return (str);
}

static char	*find_pos_stream(char *str, char *splitter)
{
	while (str != splitter && !ft_isspace(*str))
	{
		if (*str == '<' || *str == '>')
			return (str);
		++str;
	}
	return (str);
}

char		*pars_stream_in_list(char *str, char *splitter,
				t_red_stream *stream_list)
{
	char	*pos_stream;
	char	*start;
	char	*end;

	pos_stream = find_pos_stream(str, splitter);
	if (find_flag_stream(pos_stream, stream_list))
		return (NULL);
	start = write_prev_to_stream(str, pos_stream, stream_list);
	end = write_next_stream(pos_stream, splitter, stream_list);
	write_minus_sym(start, end);
	return (end);
}
