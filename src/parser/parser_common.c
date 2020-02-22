/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_common.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 20:15:29 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/22 21:56:06 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
