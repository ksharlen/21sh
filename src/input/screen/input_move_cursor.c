/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_move_cursor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 00:41:07 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/08 00:32:43 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

static void	parse_arrow(struct s_input *inp)
{
	if (inp->key == KEY_LEFT_ARROW)
	{
		if (inp->gap.slide)
		{
			if (check_line_footnote_up(inp) == FALSE)
				--inp->cr.x;
			gap_slide_left(&inp->gap);
		}
	}
	else if (inp->key == KEY_RIGHT_ARROW)
	{
		if (inp->gap.slide < inp->gap.len_string)
		{
			if (check_line_footnote_down(inp) == FALSE)
				++inp->cr.x;
			gap_slide_right(&inp->gap);
		}
	}
}

static void	parse_home_end(struct s_input *inp)
{
	if (inp->gap.len_string)
	{
		if (inp->key == KEY_HOME || inp->key == CTR_KEY('a'))
		{
			inp->cr.x = inp->save_refresh_pos.x;
			inp->cr.y = inp->save_refresh_pos.y;
			inp->gap.slide = 0;
		}
		else if (inp->key == KEY_END || inp->key == CTR_KEY('e'))
		{
			inp->cr = input_get_end_string(inp);
			inp->gap.slide = inp->gap.len_string;
		}
	}
}

static void	parse_shift_key(struct s_input *inp)
{
	if (inp->key == KEY_SHIFT_L_ARROW || inp->key == KEY_SHIFT_R_ARROW
		|| inp->key == KEY_CTR_R_ARROW || inp->key == KEY_CTR_L_ARROW)
	{
		input_parse_keys_shift_words(inp);
	}
	else if (inp->key == KEY_SHIFT_U_ARROW || inp->key == KEY_SHIFT_D_ARROW)
	{
		input_parse_page_keys(inp);
	}
}

void	move_cursor(struct s_input *inp)
{
	if (inp->key == KEY_LEFT_ARROW || inp->key == KEY_RIGHT_ARROW ||
		inp->key == KEY_UP_ARROW || inp->key == KEY_DOWN_ARROW)
		parse_arrow(inp);
	else if (inp->key == KEY_HOME || inp->key == KEY_END ||
	inp->key == CTR_KEY('e') || inp->key == CTR_KEY('a'))
		parse_home_end(inp);
	else if (inp->key == KEY_SHIFT_L_ARROW || inp->key == KEY_SHIFT_R_ARROW ||
			inp->key == KEY_SHIFT_U_ARROW || inp->key == KEY_SHIFT_D_ARROW ||
			inp->key == KEY_CTR_L_ARROW || inp->key == KEY_CTR_R_ARROW)
		parse_shift_key(inp);
	else if (inp->key == KEY_PAGE_DOWN || inp->key == KEY_PAGE_UP)
		input_parse_page_keys(inp);
	set_cursor_pos(inp->cr.x, inp->cr.y);
}
