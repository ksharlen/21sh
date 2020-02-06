/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:11:15 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/06 17:22:55 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

#define IS_QT(sym) ((sym) == '\'' || (sym) == '\"' || (sym) == '`')

static void	put_in_stack_quote_from_str(const char *str, t_queue *qu)
{
	while (*str)
	{
		if (IS_QT(*str))
			ft_qu_push(qu, (void *)str, sizeof(char));
		++str;
	}
}

static char	quote_cmp(char *quote, t_queue *qu)
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

static int	search_double_quotes(t_queue *qu)
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

void	input_quote_mode(struct s_input *inp)
{
	t_queue	qu;
	char	*str;
	int		quote_close;
//!need defense
	ft_qu_init(&qu);
	str = gap_get_buf(&inp->gap);
	put_in_stack_quote_from_str(str, &qu);
	if ((quote_close = search_double_quotes(&qu)) == TRUE)
		ft_printf("TRUE\n");
	else
		ft_printf("quote: %c\n", quote_close);
}
