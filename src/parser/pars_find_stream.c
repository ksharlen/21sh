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
		return (NULL); //////////////////// вывод об ошибке когда нет аргументов
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
		return (NULL); //////////////////// вывод об ошибке когда нет аргументов
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
// определяет положение указателя для начала парсинга аргументов после перенаправления
static char	*find_pos_args_next_stream(char *pos_stream, char *splitter)
{
	while (pos_stream != splitter && *pos_stream == '<' && *pos_stream == '>')
		++pos_stream;
	if (ft_isspace(*pos_stream))
	{
		while (pos_stream != splitter && ft_isspace(*pos_stream))
			++pos-check_stream;
		///////////////// функция проверяющая являются ли символы системными - валидность символов
	}
	return (pos_stream);
}
// парсит после перенаправления
static char	*write_next_stream(char *pos_stream, char *splitter, t_red_stream *stream_list)
{
	pos_stream = find_pos_args_next_stream(pos_stream, splitter);
	if (*pos_stream == '&')
		pos_stream = write_amper_args_after_stream(pos_stream, splitter, stream_list);
	else if (pos_stream)
		// функция для записи имени файла
	return (pos_stream);
}
/*
** после перенаправления
*/

/*
**	до перенаправления
*/
/***один лист***/
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
// если старт строки совпадает с перенаправлением
static char	*write_point_one_in_str(char *str, t_red_stream *stream_list)
{
	if (stream_list->flag_file > 0)
		stream_list->stream_a = STDOUT_FILENO;
	else
		stream_list->stream_in = STDIN_FILENO;
	return (str);
}
// парсит для одного листа то, что до перенаправления
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
// парсид для двух листов то, что до перенаправления
static char	*write_two_prev(char *str, char *pos_stream, t_red_stream *stream_list)
{
	if (stream_list->flag_file > 0)
	{
		stream_list->stream_a = STDOUT_FILENO;
		stream_list->next->stream_a = STDERR_FILENO;
	}
	else
	{
		tream_list->stream_in = STDOUT_FILENO;
		stream_list->next->stream_in = STDERR_FILENO;
	}
	while (*pos_stream != '&')
		--pos_stream;
	return (pos_stream);
}
/***два листа***/
// парсит то, что до перенаправления
static char	*write_prev_to_stream(char *str, char *pos_stream, t_red_stream *stream_list)
{
	if (stream_list->next)
		str = write_two_prev(str, pos_stream, stream_list);
	else
		str = write_prev(str, pos_stream, stream_list);
	return (str);
}

/*
**	до перенаправления
*/
// находит первый знак перенаправления
static char	*find_pos_stream(char *str, char *splitter)
{
	while (str != splitter && !ft_isspace(*str))
	{
		if (*str == '<' || *str == '>')
			return (str);
		++str;
	}
}
// основной парсинг перенаправления
static void	pars_stream_in_list(char *str, char *splitter, t_red_stream *stream_list)
{
	char *pos_stream;
	char *start;
	char *end;

	pos_stream = find_pos_stream(str, splitter);
	/// определяет флаги
	statrt = write_prev_to_stream(str, pos_stream, stream_list);
	end = write_next_stream(pos_stream, splitter, stream_list);
}
// проеряет есть ли перенаправления
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
// создаёт новые листы
static void	add_lst_stream(t_red_stream **stream_list, int nbrlst)
{
	while (nbrlst--)
		pars_add_lst_stream(stream_list);
}

char		*pars_find_stream(char *str, char *splitter, t_pars_list *list)
{
	int	nbrlst;

	if ((nbrlst = check_stream(str, splitter)))
	{
		add_lst_stream(&list->stream_list, nbrlst);
		if (nbrlst == 2)
			pars_stream_in_list(str, splitter, list->stream_list->end->prev);
		else
			pars_stream_in_list(str, splitter, list->stream_list->end);
	}
	return (str);
}

// написан парсинг для того, что до перенаправления
// нужно дописать то, что после перенаправления и функция которая ставит флаги, и вывод ошибки если после перенаправления ничего нет
// дописать валидность в find_pos_args_next_stream()
