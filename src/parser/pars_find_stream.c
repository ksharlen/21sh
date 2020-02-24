/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_find_stream.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 22:35:05 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/23 22:35:07 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// проверяет на валидность имени файла (должны отсутствовать системные символы) // 4.3
static int	check_valid_char_name(char sym)
{
	if (sym == '&' || sym == '|' || sym == ';')
		return (1);
	return (0);
}
// выводит ошибку символа в перенаправлении
static char	*put_error_parse(char *str, int fd)
{
	ft_putstr_fd("42sh: parse error near \'", fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd("\'\n", fd);
	return (NULL);
}
// записывает '-1' в заданном диапазоне // 2.5


static void	write_minus_sym(char *start, char *end)
{
	while (start <= end)
	{
		if (*start)
			*start = -1;
		++start;
	}
}
/*
** после перенаправления
*/

/*** при парсинге имени файла ***/
// добавляет из буфера имя файла в ёкземпляр листа
static void	write_name_in_stream_list(char *buf, t_red_stream *stream_list)
{
	ft_strcpy(stream_list->stream_name, buf);
	if (stream_list->next)
		ft_strcpy(stream_list->next->stream_name, buf);
}
// записывает в буфер имя файла
static char	*write_name_file_args(char *pos_stream, char *splitter, t_red_stream *stream_list)
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
		return (put_error_parse("\\n", 2));
	write_name_in_stream_list(buf, stream_list);
	return (pos_stream);
}
/*** при парсинге имени файла ***/

/*** если был встречен & ***/
// запись из буфера результата в экземпляр листа
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
// запись значения до пробела или до spletter
static char	*write_nbr_args(char *pos_stream, char *splitter, t_red_stream *stream_list)
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
		return (put_error_parse("\\n", 2));
	write_res_buf_in_stream_list(buf, stream_list);
	return (pos_stream);
}
// если встречается & после перенаправления
static char	*write_amper_args_after_stream(char *pos_stream, char *splitter, t_red_stream *stream_list)
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
/*** если был встречен & ***/

// определяет положение указателя для начала парсинга аргументов после перенаправления // 4.2
static char	*find_pos_args_next_stream(char *pos_stream, char *splitter)
{
	while (pos_stream != splitter && *pos_stream == '<' && *pos_stream == '>')
		++pos_stream;
	if (ft_isspace(*pos_stream))
	{
		while (pos_stream != splitter && ft_isspace(*pos_stream))
			++pos_stream;
		if (check_valid_char_name(*pos_stream))
			return (put_error_parse(pos_stream, 2));
	}
	return (pos_stream);
}
// парсит после перенаправления // 4.1
static char	*write_next_stream(char *pos_stream, char *splitter, t_red_stream *stream_list)
{
	pos_stream = find_pos_args_next_stream(pos_stream, splitter);
	if (*pos_stream == '&')
		pos_stream = write_amper_args_after_stream(pos_stream, splitter, stream_list);
	else if (pos_stream)
		pos_stream = write_name_file_args(pos_stream, splitter, stream_list);
	return (pos_stream);
}
/*
** после перенаправления
*/

/*
**	до перенаправления
*/
/***один лист***/
// 3.3
static void	write_nbr_fd_prev_stream(char *str, char *pos_stream, t_red_stream *stream_list)
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
	if (stream_list->flag_file > 0)
		stream_list->stream_a = ft_atoi(buf);
	else
		stream_list->stream_in = ft_atoi(buf);
}
// если старт строки совпадает с перенаправлением // 3.2
static char	*write_point_one_in_str(char *str, t_red_stream *stream_list)
{
	if (stream_list->flag_file > 0)
		stream_list->stream_a = STDOUT_FILENO;
	else
		stream_list->stream_in = STDIN_FILENO;
	return (str);
}
// парсит для одного листа то, что до перенаправления // 3.1
static char	*write_prev(char *str, char *pos_stream, t_red_stream *stream_list)
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
		save_point = pos_stream;
	return (save_point);
}
/***один лист***/
/***два листа***/
// парсид для двух листов то, что до перенаправления // 2.4
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
/***два листа***/
// парсит то, что до перенаправления // 2.3
static char	*write_prev_to_stream(char *str, char *pos_stream, t_red_stream *stream_list)
{
	if (stream_list->next)
		str = write_two_prev(pos_stream, stream_list);
	else
		str = write_prev(str, pos_stream, stream_list);
	return (str);
}

/*
**	до перенаправления
*/
// находит первый знак перенаправления // 2.2
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
// основной парсинг перенаправления // 2.1
static char *pars_stream_in_list(char *str, char *splitter, t_red_stream *stream_list)
{
	char *pos_stream;
	char *start;
	char *end;

	pos_stream = find_pos_stream(str, splitter);
	/// определяет флаги
	// static void	find_flag_stream(char *pos_stream, char *splitter);
	start = write_prev_to_stream(str, pos_stream, stream_list);
	end = write_next_stream(pos_stream, splitter, stream_list);
	write_minus_sym(start, end);
	return (end);
}
// проеряет есть ли перенаправления // 1.3
static int	check_stream(char *str, char *splitter)
{

	while (str != splitter && !ft_isspace(*str))
	{
		if (*str == '>' || *str == '<')
		{
			if (*(str - 1) == '&')
				return (2);
			else
				return (1);
		}
		str++;
	}
	return (0);
}
// создаёт новые листы // 1.2
static void	add_lst_stream(t_red_stream **stream_list, int nbrlst)
{
	while (nbrlst--)
		pars_add_lst_stream(stream_list);
}
// 1.1
char		*pars_find_stream(char *str, char *splitter, t_pars_list *list)
{
	int	nbrlst;

	if ((nbrlst = check_stream(str, splitter)))
	{
		add_lst_stream(&list->stream_list, nbrlst);
		if (nbrlst == 2)
			str = pars_stream_in_list(str, splitter, list->stream_list->end->prev);
		else
			str = pars_stream_in_list(str, splitter, list->stream_list->end);
	}
	return (str);
}

// нужно дописать функцию которая ставит флаги
