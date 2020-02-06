/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:11:15 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/06 16:27:37 by ksharlen         ###   ########.fr       */
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

void	input_quote_mode(struct s_input *inp)
{
	t_queue	qu;
	char	*str;

	ft_qu_init(&qu);
	str = gap_get_buf(&inp->gap);
	put_in_stack_quote_from_str(str, &qu);
}
