/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <tjonella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:55:30 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/29 16:01:56 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char		*skip_args(char *str, char *splitter)
{
	while (str != splitter && !ft_isspace(*str))
		++str;
	return (str);
}

static int 		check_str(const char *str, char *splitter)
{
	size_t 	qty_sym;

	qty_sym = 0;
	str = ft_skiptabs(str);
	while (*str && str != splitter)
	{
		++qty_sym;
		++str;
	}
	return (qty_sym ? TRUE : FALSE);
}

static int	fill_struct(char *str_start, t_info_parser *prs, char *splitter)
{
	size_t	qty_args;
	char 	*str;
	char	*check_pos;

	str = str_start;
	while (*str && str != splitter)
	{
		str = ft_skiptabs(str);
		str = parser_skipminus(str);
		check_pos = str;
		if (!(str = pars_find_stream(str, splitter, prs->end)))	// поиск и заполнение перенаправлений + заполняет всё лишнее '-1'
			return (1);
		str = parser_skip_quotes(str, splitter);
		if (check_pos == str)
			str = skip_args(str, splitter);
	}
	qty_args = parser_count_args(str_start, splitter); //!счетчик работает для пустой строки, он считает разделитель
	prs->end->pars_args = parser_fill_args(str_start, splitter, qty_args); // qty_args + 1 для NULL
	return (0);
}

static int		parse_str(char *str_for_parse, t_info_parser *prs)
{
	char		*splitter;
	char 		*str;

	str = str_for_parse;
	while (str && *str)
	{
//!	Посмотреть исключительные случаи разделителя
		splitter = find_delimiter(str);			// находим разделитель команд или конец строки
		// parser_add_list(prs);
		str = parser_skip_quotes(str, splitter);
		if ((check_str(str, splitter)) == TRUE)
			parser_add_list(prs);// создаём новый экземпляр листа и возвращаем на него указатель
		else
		{
			str = (*splitter) ? ++splitter : splitter;
			continue;
		}
	if (fill_struct(str, prs, splitter))
		return (1);
	str = skip_splitter(splitter, &prs->end->f_delimiter);//Тут флаг разделителя и пропуск splitter
//!			need validation
	}
	return ((str) ? 0 : 1);
}


int		parser(char *str_for_parse, t_info_parser *prs)
{
	if (parse_str(str_for_parse, prs))
		return (1);
	parser_fill_point_args(prs->beg);
	return (0);
}
