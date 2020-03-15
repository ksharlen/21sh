/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:48:49 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/23 15:25:13 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*push_args(char **str, char *splitter)
{
	char	*arg;
	size_t	len_arg;

	arg = NULL;
	if (**str == '\'' || **str == '\"' || **str == '`')
		arg = parser_quote_arg(str, splitter);
	else
	{
		len_arg = parser_get_len_arg(*str, splitter);
		arg = ft_strnew(len_arg);
		ft_chk_null_ptr(arg, E_MALLOC);
		ft_memcpy(arg, *str, sizeof(char) * len_arg);
		*str = (char *)parser_skip_word(*str, splitter);
	}
	return (arg);
}

char		**parser_fill_args(char *start_str, char *splitter, size_t qty_args)
{
	char	*str;
	char	**args;
	size_t	i;

	str = start_str;
	i = 0;
	str = ft_skiptabs(str);
	args = (char **)ft_memalloc(sizeof(char *) * (qty_args + 1));
	ft_chk_null_ptr(args, E_MALLOC);
	while (str && str != splitter && i < qty_args)
	{
		if (*str == -1)
			str = (char *)ft_skipfirst(str, -1);
		else
			args[i++] = push_args(&str, splitter);
		str = ft_skiptabs(str);
	}
	args[qty_args] = NULL;
	return (args);
}
