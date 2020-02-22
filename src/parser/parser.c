/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:55:30 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/22 15:59:15 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// static int 		check_str(const char *str, char *splitter)
// {
// 	size_t 	qty_sym;

// 	P_UNUSED(qty_sym);
// 	P_UNUSED(str);
// 	P_UNUSED(splitter);

// //	qty_sym = 0;
// //	str = ft_skiptabs(str);
// //	while (*str && str != splitter)
// //	{
// //		++qty_sym;
// //		++str;
// //	}
// //	return (qty_sym ? TRUE : FALSE);
// return (0);
// }

// static char	*fill_struct(char *str_start, t_info_parser *prs, char *splitter)
// {
// 	size_t	qty_args;
// 	char 	*str;

// 	P_UNUSED(str_start);
// 	P_UNUSED(prs);
// 	P_UNUSED(splitter);
// 	P_UNUSED(qty_args);
// 	P_UNUSED(str);
// //	str = str_start;
// //	while (*str && *str_start != splitter)
// //	{
// //		str = skip_tabs(str);
// //		str = find_stream(str, splitter, prs->end);			// поиск и заполнение перенаправлений + заполняет всё лишнее '-1'
// //		str = skip_quotes(str, splitter);
// //		str = skip_args(str, splitter);
// //	}
// //	qty_args = count_args(str_start, splitter);
// //	prs->end->pars_args = fill_args(str_start, splitter, qty_args); // qty_args + 1 для NULL
// //	//
// 	return (NULL);
// }

static void		parse_str(char *str_for_parse, t_info_parser *prs)
{
	char		*splitter;
	char 		*str;

	P_UNUSED(splitter);
	P_UNUSED(str);
	P_UNUSED(str_for_parse);
	P_UNUSED(prs);

	str = str_for_parse;
	while (*str)
	{
//!	Посмотреть исключительные случаи разделителя
//		splitter = find_delimiter(str);			// находим разделитель команд или конец строки
//		if ((check_str(str, splitter)) == TRUE)
//			parser_add_list(prs);// создаём новый экземпляр листа и возвращаем на него указатель
//		else {
//			str = (*splitter) ? ++splitter : splitter;
//			continue;
//		}
//		if ((find_set_vars(str, splitter)) == TRUE)
//			;//TODO: парсим переменные
//		else
//		{
//			fill_struct(str, prs, splitter);
//			str = skip_splitter(splitter, &prs->end->f_delimiter);//Тут флаг разделителя и пропуск splitter
//		}
	}
}

void	parser(char *str_for_parse, t_info_parser *prs)
{
	(void)(str_for_parse);
	P_UNUSED(prs);

	parse_str(str_for_parse, prs);
	return ;
}