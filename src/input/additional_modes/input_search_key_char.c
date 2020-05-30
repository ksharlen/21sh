/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_search_key_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 20:47:11 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 17:54:08 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

static char		quote_cmp(char *quote, t_queue *qu)
{
	char	*second_pop;
	char	quote_ret;

	while (1)
	{
		second_pop = ft_qu_pop(qu);
		if (second_pop)
		{
			if (*second_pop == *quote)
			{
				quote_ret = TRUE;
				break ;
			}
		}
		else
		{
			quote_ret = *quote;
			break ;
		}
		ft_strdel(&second_pop);
	}
	ft_strdel(&second_pop);
	return (quote_ret);
}

int				search_double_quotes(t_queue *qu)
{
	char	*first_pop;
	char	quote;

	quote = TRUE;
	if ((ft_qu_is_empty(qu) == FALSE))
	{
		while (1)
		{
			first_pop = ft_qu_pop(qu);
			if (!first_pop)
			{
				quote = TRUE;
				break ;
			}
			if ((quote = quote_cmp(first_pop, qu)) != TRUE)
			{
				ft_strdel(&first_pop);
				return (quote);
			}
			ft_strdel(&first_pop);
		}
	}
	return (quote);
}
