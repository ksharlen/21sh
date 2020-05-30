/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_write_prev.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:03:24 by mdelphia          #+#    #+#             */
/*   Updated: 2020/03/11 18:03:29 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void	write_nbr_prev_stream_in_list(t_red_stream *stream_list, int std_fd)
{
	if (stream_list->flag_file > 0)
		stream_list->stream_a = std_fd;
	else
		stream_list->stream_in = std_fd;
}

static void	write_nbr_fd_prev_stream(char *str, char *pos_stream,
				t_red_stream *stream_list)
{
	char	buf[BUFSIZ];
	size_t	i;

	i = 0;
	while (str != pos_stream)
	{
		buf[i] = *str;
		++i;
		++str;
	}
	buf[i] = '\0';
	write_nbr_prev_stream_in_list(stream_list, ft_atoi(buf));
}

static char	*write_point_one_in_str(char *str, t_red_stream *stream_list)
{
	if (stream_list->flag_file > 0)
		stream_list->stream_a = STDOUT_FILENO;
	else
		stream_list->stream_in = STDIN_FILENO;
	return (str);
}

char		*write_prev(char *str, char *pos_stream, t_red_stream *stream_list)
{
	char *save_point;

	save_point = str;
	if ((*str >= '0' && *str <= '9') || str == pos_stream)
	{
		if (str == pos_stream)
			return (write_point_one_in_str(str, stream_list));
		write_nbr_fd_prev_stream(str, pos_stream, stream_list);
	}
	else
	{
		write_nbr_prev_stream_in_list(stream_list, 1);
		save_point = pos_stream;
	}
	return (save_point);
}
