/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_common.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 20:15:29 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/22 22:30:21 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static const char	*skip_word(const char *str, char *splitter)
{
	if (str)
	{
		while (str != splitter && !ft_isspace(*str))
			++str;
	}
	return (str);
}

size_t	parse_count_args(const char *str, char *splitter)
{
	size_t	qty_args;

	qty_args = 0;
	if (str)
	{
		while (str != splitter)
		{
			str = ft_skiptabs(str);
			if (*str && *str == -1)
				str = ft_skipfirst(str, -1);
			else
			{
				++qty_args;
				str = skip_word(str, splitter);
			}
		}
	}
	return (qty_args);
}

char	*parse_skip_quotes(char *str, char *splitter)
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
