/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_write_next_stream.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:07:22 by mdelphia          #+#    #+#             */
/*   Updated: 2020/03/11 18:07:24 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void	write_name_in_stream_list(char *buf, t_red_stream *stream_list)
{
	ft_strcpy(stream_list->stream_name, buf);
	if (stream_list->next)
		ft_strcpy(stream_list->next->stream_name, buf);
}

static char	*write_name_file_args(char *pos_stream, char *splitter,
				t_red_stream *stream_list)
{
	char	buf[BUFSIZ];
	size_t	i;

	i = 0;
	while (pos_stream != splitter && !ft_isspace(*pos_stream))
	{
		buf[i] = *pos_stream;
		++i;
		++pos_stream;
	}
	buf[i] = '\0';
	if (!buf[0])
		return (put_error_parse("\\0", 2));
	write_name_in_stream_list(buf, stream_list);
	return (pos_stream);
}

static char	*find_pos_args_next_stream(char *pos_stream, char *splitter)
{
	while (pos_stream != splitter && (*pos_stream == '<' || *pos_stream == '>'))
		++pos_stream;
	if (ft_isspace(*pos_stream))
	{
		while (pos_stream != splitter && ft_isspace(*pos_stream))
			++pos_stream;
		if (check_valid_char_name(*pos_stream))
		{
			*(pos_stream + 1) = '\0';
			return (put_error_parse(pos_stream, 2));
		}
	}
	return (pos_stream);
}

char		*write_next_stream(char *pos_stream, char *splitter,
				t_red_stream *stream_list)
{
	pos_stream = find_pos_args_next_stream(pos_stream, splitter);
	if (*pos_stream == '&')
		pos_stream = write_amper_args_after_stream(
					pos_stream, splitter, stream_list);
	else if (pos_stream)
		pos_stream = write_name_file_args(pos_stream, splitter, stream_list);
	return (pos_stream);
}
