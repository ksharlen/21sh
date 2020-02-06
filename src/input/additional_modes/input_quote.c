/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:11:15 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/06 16:52:53 by ksharlen         ###   ########.fr       */
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

static int	search_double_quotes(t_queue *qu)
{
	char	*first_pop;
	char	*second_pop;
	int		quote_close;

	quote_close = TRUE;
	if ((ft_qu_is_empty(qu) == FALSE))
	{
		while (1)
		{
			first_pop = ft_qu_pop(qu);
			if (!first_pop)
			{
				quote_close = TRUE;
				break ;
				//!del
			}
			while (1)
			{
				second_pop = ft_qu_pop(qu);
				if (second_pop)
				{
					if (*second_pop == *first_pop)
					{
						quote_close = TRUE;
						//!del
						break ;
					}
				}
				else
				{
					return (FALSE);
				}
			}
		}
	}
	return (quote_close);
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
	else if (quote_close == FALSE)
		ft_printf("FALSE\n");
}
