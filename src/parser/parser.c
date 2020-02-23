/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:55:30 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/23 15:48:56 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// static int 		check_str(const char *str, char *splitter)
// {
// 	size_t 	qty_sym;

// 	P_UNUSED(qty_sym);
// 	P_UNUSED(str);
// 	P_UNUSED(splitter);

// 	qty_sym = 0;
// 	str = ft_skiptabs(str);
// 	while (*str && str != splitter)
// 	{
// 		++qty_sym;
// 		++str;
// 	}
// 	return (qty_sym ? TRUE : FALSE);
// }

static char	*fill_struct(char *str_start, t_info_parser *prs, char *splitter)
{
	size_t	qty_args;
	char 	*str;

	P_UNUSED(str_start);
	P_UNUSED(prs);
	P_UNUSED(splitter);
	P_UNUSED(qty_args);
	P_UNUSED(str);
	str = str_start;
// //*	while (*str && *str_start != splitter)
// //	{
		str = ft_skiptabs(str);
//		str = find_stream(str, splitter, prs->end);			// поиск и заполнение перенаправлений + заполняет всё лишнее '-1'
//* 	str = skip_quotes(str, splitter);
// // printf("str: %s\n", str);
// // EXIT();
// //		str = skip_args(str, splitter);
// //	}
	qty_args = parser_count_args(str_start, splitter); //!счетчик работает для пустой строки, он считает разделитель
	prs->end->pars_args = parser_fill_args(str_start, splitter, qty_args); // qty_args + 1 для NULL
//	//
	return (NULL);
}

static void		print_args(t_pars_list *elem)
{
	char	**current = elem->pars_args;
	size_t	size = 0;

	while (*current)
	{
		ft_printf("%s	size: %zd\n", *current, ft_strlen(*current));
		++current;
		++size;
	}
ft_printf("size: %zd\n", size);
exit(EXIT_FAILURE);
}

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
		splitter = find_delimiter(str);			// находим разделитель команд или конец строки
		parser_add_list(prs);
		// str = parse_skip_quotes(str, splitter);
//*		if ((check_str(str, splitter)) == TRUE)
//*			parser_add_list(prs);// создаём новый экземпляр листа и возвращаем на него указатель
//*		else
//		{
//*			str = (*splitter) ? ++splitter : splitter;
//*			continue;
//		}
//		if ((find_set_vars(str, splitter)) == TRUE)
//			;//TODO: парсим переменные
//*		else
//*		{
			fill_struct(str, prs, splitter);
print_args(prs->end);
//			str = skip_splitter(splitter, &prs->end->f_delimiter);//Тут флаг разделителя и пропуск splitter
//!			need validation
//		}
	}
}
//ft_printf("%v%s: %s%s\n", STDERR_FILENO, P_N, DELIM_ERR, ...);

void	parser(char *str_for_parse, t_info_parser *prs)
{
	(void)(str_for_parse);
	P_UNUSED(prs);

	parse_str(str_for_parse, prs);
	return ;
}