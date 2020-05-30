/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:24:32 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/23 17:51:20 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*get_dquote_arg(char **str)
{
	size_t	len_str;
	char	*arg;

	++(*str);
	arg = NULL;
	len_str = ft_strnlen(*str, '\"');
	arg = ft_strnew(sizeof(char) * len_str);
	ft_memcpy(arg, *str, len_str);
	(*str) += (len_str + 1);
	return (arg);
}

static char	*get_quote_arg(char **str)
{
	size_t	len_str;
	char	*arg;

	++(*str);
	arg = NULL;
	len_str = ft_strnlen(*str, '\'');
	arg = ft_strnew(sizeof(char) * len_str);
	ft_memcpy(arg, *str, len_str);
	(*str) += (len_str + 1);
	return (arg);
}

char		*parser_quote_arg(char **str, char *splitter)
{
	char	*arg;

	arg = NULL;
	(void)(splitter);
	if (**str == '\'')
		arg = get_quote_arg(str);
	else if (**str == '\"')
		arg = get_dquote_arg(str);
	return (arg);
}
