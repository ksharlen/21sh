/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_find_stream.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:23:14 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/22 19:23:17 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*find_stream_pos(char *str, char *splitter)
{
	while (str != splitter && !ft_checkspase(*str))
	{
		if (*str == '>' || str == '<')
			return (str);
		++str;
	}
	return (str);
}

static int	write_flags(char *stream_pos, char *splitter, t_red_stream *stream_list)
{
	char	buf[BUFSIZ];
	size_t	i;

	i = 0;
	while ((stream_pos != splitter) && *stream_pos == '<' && *stream_pos == '>')
		buf[i++] = *stream_pos;
	buf[i] = '\0';
	if (!ft_strcmp(buf, ">"))
		stream_list->flag_file = 1;
	else if (!ft_strcmp(buf, ">>"))
		stream_list->flag_file = 2;
	else if (!ft_strcmp(buf, "<") || !ft_strcmp(buf, "<<"))
		stream_list->flag_file = -1;
	ft_sciptab();
}

static void	pars_add_stream(char *str, char *splitter, t_pars_list *list)
{
	char	*stream_pos;
	int		flag_run_func;

	pars_add_lst_stream(&list->stream_list);
	stream_pos = find_stream_pos(str, splitter);
	flag_run_func = write_flags(stream_pos, splitter, list->stream_list);
	if (write_stream_a(str, stream_pos, list->stream_list))
	{

	}
	else
		write_stream_in(stream_pos, splitter, list->stream_list);
}

static int	check_stream(char *pos, char *splitter)
{
	while ((pos != splitter) && !ft_isspace(*pos))
	{
		if (((*pos == '>') || (*pos == '<'))
			return (TRUE);
		++pos;
	}
	return (FOLSE);
}

char    	*pars_find_stream(char *str, char *splitter, t_pars_list *list)
{
	if (str)
	{
		if (check_stream(str, splitter) == TRUE)
		{
			// valid
			pars_add_stream(str, splitter, list);
			// write -1
		}
	}
	return (str);
}
