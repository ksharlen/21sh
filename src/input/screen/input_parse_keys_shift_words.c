/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse_keys_shift_words.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 21:16:39 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/08 22:54:16 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

#define SKIP_L_WORD 0
#define SKIP_R_WORD 1

static size_t	get_shift_skip_word(const char *str, size_t pos, int where)
{
	size_t		shift;
	const char	*p_str;

	shift = 0;
	if (str)
	{
		p_str = &str[pos];
		while (where == SKIP_L_WORD ? p_str != str : *p_str)
		{
			if (((*p_str) > 32 && (*p_str) < 126) && *(p_str - 1) == ' ')
				break ;
			where == SKIP_L_WORD ? --p_str : ++p_str;
			++shift;
		}
		++shift;
	}
	return (shift);
}

static void		parse_shft_right_arrow(struct s_input *inp)
{
	char			*str;
	ssize_t			shift;
	ssize_t			pos;

	str = gap_get_buf(&inp->gap);
	shift = get_shift_skip_word(str, inp->gap.slide + 1, SKIP_R_WORD);
	pos = inp->gap.slide + shift + inp->greet.len;
	get_coor_word(inp, pos);
	inp->gap.slide += shift;
	ft_strdel(&str);
}

static void		parse_shft_left_arrow(struct s_input *inp)
{
	char	*str;
	ssize_t	pos;
	ssize_t	shift;

	str = gap_get_buf(&inp->gap);
	shift = get_shift_skip_word(str, inp->gap.slide - 1, SKIP_L_WORD) * (-1);
	pos = inp->gap.slide + shift + inp->greet.len;
	get_coor_word(inp, pos);
	inp->gap.slide += shift;
	ft_strdel(&str);
}

void			get_coor_word(struct s_input *inp, ssize_t pos)
{
	struct s_cursor	coord_word;

	coord_word.y = pos / inp->win.cols;
	coord_word.x = pos % inp->win.cols;
	inp->cr.y = inp->save_refresh_pos.y + coord_word.y;
	inp->cr.x = coord_word.x;
}

void			input_parse_keys_shift_words(struct s_input *inp)
{
	if ((inp->key == KEY_SHIFT_L_ARROW || inp->key == KEY_CTR_L_ARROW) &&
			inp->gap.slide)
		parse_shft_left_arrow(inp);
	else if ((inp->key == KEY_SHIFT_R_ARROW || inp->key == KEY_CTR_R_ARROW) &&
				inp->gap.slide != inp->gap.len_string)
		parse_shft_right_arrow(inp);
}
