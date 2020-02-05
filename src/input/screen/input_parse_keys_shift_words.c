/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse_keys_shift_words.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 21:16:39 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/05 23:50:31 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

#define SKIP_L_WORD 0
#define SKIP_R_WORD 1

static size_t	get_shift_skip_word(const char *str, size_t pos, int whome)
{
	size_t		shift;
	const char	*p_str;

	shift = 0;
	if (str)
	{
		p_str = &str[pos];
		while (whome == SKIP_L_WORD ? p_str != str : *p_str)
		{
			if (((*p_str) > 32 && (*p_str) < 126) && *(p_str - 1) == ' ')
				break ;
			whome == SKIP_L_WORD ? --p_str : ++p_str;
			++shift;
		}
		++shift;
	}
	return (shift);
}

static void parse_shft_right_arrow(struct s_input *inp)
{
	struct s_cursor	next_word;
	size_t			shift;
	size_t			pos;
	char			*str;

	if (inp->gap.slide != inp->gap.len_string)
	{
		str = gap_get_buf(&inp->gap);
		shift = get_shift_skip_word(str, inp->gap.slide + 1, SKIP_R_WORD);
		pos = inp->gap.slide + shift + inp->len_greet;
		next_word.y = pos / inp->win.cols;
		next_word.x = pos % inp->win.cols;
		inp->cr.y = inp->save_refresh_pos.y + next_word.y;
		inp->cr.x = next_word.x;
		inp->gap.slide += shift;
		ft_strdel(&str);
	}
}

static void	parse_shft_left_arrow(struct s_input *inp)
{
	struct s_cursor	prev_word;
	char	*str;
	size_t	shift;
	size_t	pos;

	shift = 0;
	if (inp->gap.slide)
	{
		str = gap_get_buf(&inp->gap);
		shift = get_shift_skip_word(str, inp->gap.slide - 1, SKIP_L_WORD);
		pos = inp->gap.slide - shift + inp->len_greet;
		prev_word.y = pos / (inp->win.cols);
		prev_word.x = pos % (inp->win.cols);
		inp->cr.y = inp->save_refresh_pos.y + prev_word.y;
		inp->cr.x = prev_word.x;
		inp->gap.slide -= shift;
		ft_strdel(&str);
	}
}

void	input_parse_keys_shift_words(struct s_input *inp)
{
	if (inp->key == KEY_SHIFT_L_ARROW)
	{
		parse_shft_left_arrow(inp);
	}
	else if (inp->key == KEY_SHIFT_R_ARROW)
	{
		parse_shft_right_arrow(inp);
	}
}