/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_common.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 20:15:29 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/23 16:02:20 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t				parser_get_len_arg(char *str, char *splitter)
{
	size_t	len_arg;

	len_arg = 0;
	while (str != splitter && !ft_isspace(*str) &&
		*str != '\'' && *str != '\"' && *str != '`' && *str != -1)
	{
		++len_arg;
		++str;
	}
	return (len_arg);
}

const char			*parser_skip_word(const char *str, char *splitter)
{
	if (str)
	{
		while (str != splitter && !ft_isspace(*str))
			++str;
	}
	return (str);
}

size_t				parser_count_args(const char *str, char *splitter)
{
	size_t	qty_args;

	qty_args = 0;
	if (str)
	{
		str = ft_skiptabs(str);
		while (str != splitter)
		{
			if (*str && *str == -1)
				str = ft_skipfirst(str, -1);
			else if (*str == '\'' || *str == '\"' || *str == '`')
			{
				++qty_args;
				str = parser_skip_quotes((char *)str, splitter);
			}
			else
			{
				++qty_args;
				str = parser_skip_word(str, splitter);
			}
			str = ft_skiptabs(str);
		}
	}
	return (qty_args);
}

char				*parser_skip_quotes(char *str, char *splitter)
{
	char	quote;

	if (str && str != splitter)
	{
		quote = *str;
		if (quote == '\'' || quote == '\"' || quote == '`')
		{
			++str;
			while (str && *str != quote)
				++str;
			++str;
		}
	}
	return (str);
}
