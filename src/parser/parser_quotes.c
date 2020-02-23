/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:24:32 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/23 16:00:05 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
**TODO: 21sh does not support two different quotation modes
*/
static char	*get_dquote_arg(char **str, char *splitter)
{
	size_t	len_str;
	char	*arg;

	P_UNUSED(splitter);
	++(*str);
	arg = NULL;
	len_str = ft_strnlen(*str, '\"');
	arg = ft_strnew(sizeof(char) * len_str);
	ft_memcpy(arg, *str, len_str);

	(*str) += (len_str + 1);
// ft_printf("str:%s\n", (*str));
// exit(EXIT_FAILURE);
	return (arg);
}

char		*parser_quote_arg(char **str, char *splitter)
{
	char	*arg;

	arg = NULL;
	P_UNUSED(splitter);
	if (**str == '\'')
	{
		
	}
	else if (**str == '\"')
	{
		arg = get_dquote_arg(str, splitter);
		
	}
	else if (**str == '`')
	{
		
	}
	return (arg);
}
