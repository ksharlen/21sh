/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_find_delimiter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:49:58 by ksharlen          #+#    #+#             */
/*   Updated: 2020/03/17 12:54:51 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			parse_not_srvc_symb(char *c)
{
	if (*c == '&' && *(c + 1) == '&')
		return (0);
	else if (*c == '&' && (*(c + 1) > '9' || *(c + 1) < '0') && *(c + 1) != '-')
		return (0);
	else if (*c == '|')
		return (0);
	else if (*c == '\0' || *c == ';')
		return (0);
	else
		return (1);
}

static void	parse_skip_spaces(char *ptr)
{
	while ((ft_isspace(*ptr)))
		ptr++;
}

int			parse_is_quote(char c)
{
	if (c == '\'' || c == '"' || c == '`')
		return (1);
	return (0);
}

char		*parse_next_quote(char *str)
{
	char	*ptr;

	ptr = str + 1;
	while (*ptr != *str)
		ptr++;
	return (ptr);
}

char		*find_delimiter(char *str)
{
	char	*ptr;
	char	*ptr_2;

	ptr = str;
	while (parse_not_srvc_symb(ptr))
	{
		if (parse_is_quote(*ptr))
			ptr = parse_next_quote(ptr);
		ptr++;
	}
	if ((ptr != str && (*(ptr - 1) == '>' || *(ptr - 1) == '<')))
	{
		ptr_2 = ptr;
		parse_skip_spaces(ptr_2);
		if (!parse_not_srvc_symb(ptr_2) && *ptr_2 != ';')
		{
			put_error_flags(ptr_2, 1);
			return (NULL);
		}
		else if (*ptr_2 == ';')
			return (ptr_2);
	}
	return (ptr);
}
