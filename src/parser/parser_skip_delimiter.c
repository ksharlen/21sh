/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_skip_delimiter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:36:01 by tjonella          #+#    #+#             */
/*   Updated: 2020/02/23 17:44:45 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*fill_split_flag(char *splitter, int size, unsigned int *flags_splt)
{
	if (size == 1)
	{
		if (*splitter == '&')
			*flags_splt |= F_AMPERSANT;
		else if (*splitter == '|')
			*flags_splt |= F_PIPE;
		else if (*splitter == ';')
			*flags_splt |= F_SEMICOLON;
	}
	else if (size == 2)
	{
		if (*splitter == '&')
			*flags_splt |= F_AND;
		else if (*splitter == '|')
			*flags_splt |= F_OR;
	}
	return (splitter + size);
}

char	*skip_splitter(char *splitter, unsigned int *flags_splt)
{
	char	*check_err;

	check_err = NULL;
	if (splitter)
	{
		if (!*splitter)
			return (splitter);
		else if (*(splitter + 1) == *splitter)
		{
			if (!parse_not_srvc_symb(splitter + 2))
				return (put_error_parse(splitter, 2));
			else if (ft_isspace(*(splitter + 2)))
			{
				check_err = ft_skiptabs(splitter + 2);
				if (!parse_not_srvc_symb(check_err))
					return (put_error_parse(check_err, 2));
			}
			splitter = fill_split_flag(splitter, 2, flags_splt);
		}
		else
			fill_split_flag(splitter, 1, flags_splt);
		return (splitter);
	}
	return (NULL);
}
