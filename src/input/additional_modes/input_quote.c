/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:11:15 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/06 20:35:26 by ksharlen         ###   ########.fr       */
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


static void	quote_init(struct s_input *inp)
{
	gap_clean_buf(&inp->gap);
	inp->save_refresh_pos = get_pos_cursor();
	--inp->save_refresh_pos.y;
	inp->save_refresh_pos.x = inp->len_greet;
	inp->cr = inp->save_refresh_pos;
	inp->key = 0;
}

static void	quote_mode(struct s_input *inp, char search_qt, char *src_str)
{
	t_queue qu;
	char	*str;
	char	close_qt;

	quote_init(inp);
	ft_qu_init(&qu);
	ft_qu_push(&qu, &search_qt, sizeof(char));
	inp->greet(&inp->u_info);
	while (inp->key != KEY_NEW_LINE)
	{
		inp->key = input_getch();
		if (inp->key == CTR_KEY('c'))
		{
			clean_struct_input(inp);
			return ;
		}
		input_process_key_press(inp);
	}
	input_put_new_line(inp);
	str = gap_get_buf(&inp->gap);
	put_in_stack_quote_from_str(str, &qu);
	src_str = ft_strreplace(src_str, str);
	inp->str_for_parse = src_str;
	close_qt = search_double_quotes(&qu);
	if (close_qt != TRUE)
		quote_mode(inp, close_qt, src_str);
}

void	input_quote_mode(struct s_input *inp)
{
	t_queue	qu;
	int		quote_close;
//!need defense
	ft_qu_init(&qu);
	// inp->str_for_parse = gap_get_buf(&inp->gap);
	put_in_stack_quote_from_str(inp->str_for_parse, &qu);
	quote_close = search_double_quotes(&qu);
	if (quote_close != TRUE)
	{
		inp->greet = input_quote_greet;
		inp->len_greet = ft_strlen(QUOTE_GREET_STR);
		quote_mode(inp, quote_close, inp->str_for_parse);
	}
}
