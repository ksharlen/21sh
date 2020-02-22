/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <tjonella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:55:30 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/22 20:33:09 by tjonella         ###   ########.fr       */
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

int		parse_not_srvc_symb(char *c)
{
	if (*c == '&' && *(c + 1) == '&') // logical AND
		return (0);
	else if (*c == '|') // logical OR или PIPE
		return (0);
	else if (*c == '\0') // Конец строки
		return (0);
	else
		return (1);	
}

int		parse_is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	parse_skip_spaces(char *ptr)
{
	while ((parse_is_space(*ptr)))
		ptr++;
}

int		parse_is_quote(char c)
{
	if (c == '\'' || c == '"' || c == '`')
		return (1);
	return (0);
}

char	*parse_next_quote(char *str)
{
	char	*ptr;

	ptr = str + 1;
	while (*ptr != *str)
		ptr++;
	return (ptr);
}

char	*find_delimiter(char *str)
{
	char	*ptr;
	char	*ptr_2;

	ptr = str;
	// Мотаем до первого разделителя
	while (parse_not_srvc_symb(ptr))
	{
		// Если кавычки, то мотаем, т.к в кавычках в любом случае аргумент
		if (parse_is_quote(*ptr))
			ptr = parse_next_quote(ptr);
		ptr++;
	}
	// Особое условие для фонового режима
	if (*ptr == '&' && (parse_is_space(*(ptr + 1)) || (ptr != str && *(ptr - 1) == '>')))
	{
		ptr_2 = ptr;
		parse_skip_spaces(ptr_2);
		// Если после & следует 1) оператор - ошибка; 2) ';' - возвращаем его; 3) что угодно еще - '&'
		if (!parse_not_srvc_symb(ptr_2) && *ptr_2 != ';')
			exit(0);
			//error(); // Придумать ошибку
		else if (*ptr_2 == ';')
			return (ptr_2);
	}
	return (ptr);
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
//	while (*str)
//	{
//!	Посмотреть исключительные случаи разделителя
		splitter = find_delimiter(str);			// находим разделитель команд или конец строки
		printf("%c", *splitter);
		exit(0);
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
//	}
}

void	parser(char *str_for_parse, t_info_parser *prs)
{
	(void)(str_for_parse);
	P_UNUSED(prs);

	parse_str(str_for_parse, prs);
	return ;
}