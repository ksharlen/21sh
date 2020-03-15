/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_write_amper_args_after_stream.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:20:12 by mdelphia          #+#    #+#             */
/*   Updated: 2020/03/11 18:20:15 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void	write_res_buf_in_stream_list(char *buf, t_red_stream *stream_list)
{
	if (stream_list->flag_file > 0)
	{
		stream_list->stream_in = ft_atoi(buf);
		if (stream_list->next)
			stream_list->next->stream_in = stream_list->stream_in;
	}
	else
	{
		stream_list->stream_a = ft_atoi(buf);
		if (stream_list->next)
			stream_list->next->stream_a = stream_list->stream_a;
	}
}

static char	*write_nbr_args(char *pos_stream, char *splitter,
				t_red_stream *stream_list)
{
	char	buf[BUFSIZ];
	size_t	i;

	i = 0;
	while ((pos_stream != splitter) && (!ft_isspace(*pos_stream)))
	{
		buf[i] = *pos_stream;
		++i;
		++pos_stream;
	}
	buf[i] = '\0';
	if (!buf[0])
		return (put_error_parse("\\0", 2));
	write_res_buf_in_stream_list(buf, stream_list);
	return (pos_stream);
}

char		*write_amper_args_after_stream(char *pos_stream, char *splitter,
				t_red_stream *stream_list)
{
	++pos_stream;
	if (*pos_stream == '-')
	{
		stream_list->flag_close = 1;
		if (stream_list->next)
			stream_list->next->flag_close = 1;
		++pos_stream;
	}
	else
		pos_stream = write_nbr_args(pos_stream, splitter, stream_list);
	return (pos_stream);
}
