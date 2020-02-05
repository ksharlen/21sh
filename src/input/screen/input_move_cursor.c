/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_move_cursor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 00:41:07 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/05 20:35:24 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

/*
**ARROW: L R U D
**PAGE: U D
**HOME: END
**WORDS: R L
*/

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
	// set_cursor_pos(inp->cr.x, inp->cr.y);
}

static void	parse_home_end(struct s_input *inp)
{
	if (inp->gap.len_string)
	{
		if (inp->key == KEY_HOME)
		{
			inp->cr.x = inp->save_refresh_pos.x;
			inp->cr.y = inp->save_refresh_pos.y;
			inp->gap.slide = 0;
		}
		else if (inp->key == KEY_END)
		{
			inp->cr = input_get_end_string(inp);
			inp->gap.slide = inp->gap.len_string;
		}
	}
}

static void	parse_page_keys(struct s_input *inp)
{
	size_t	qt_row_before_cr;
	int		num_sym_in_rows;
	int		reminder_str;

	if (inp->key == KEY_PAGE_DOWN)
	{
		qt_row_before_cr = inp->cr.y - inp->save_refresh_pos.y;
		num_sym_in_rows = qt_row_before_cr * inp->win.cols - (inp->len_greet);
		reminder_str = inp->gap.len_string - num_sym_in_rows;
		if (reminder_str > inp->cr.x)
		{
			if ((qt_row_before_cr + 1) * inp->win.cols >= inp->gap.len_string)
			{
				++inp->cr.y;
			}
		}
	}
}

static void	parse_shift_key(struct s_input *inp)
{
	size_t	qt_row_before_cr;
	size_t	num_sym_in_rows;
	size_t	reminder_str;

	P_UNUSED(reminder_str);
	if (inp->key == KEY_SHIFT_L_ARROW)
	{
		
	}
	else if (inp->key == KEY_SHIFT_R_ARROW)
	{
		
	}
	else if (inp->key == KEY_SHIFT_U_ARROW)
	{
		
	}
	else if (inp->key == KEY_SHIFT_D_ARROW)
	{
		qt_row_before_cr = inp->cr.y - inp->save_refresh_pos.y;
		num_sym_in_rows = qt_row_before_cr * inp->win.cols - inp->len_greet;
		if (inp->gap.len_string > num_sym_in_rows)
			++inp->cr.y;
	}
}

void	move_cursor(struct s_input *inp)
{
	if (inp->key == KEY_LEFT_ARROW || inp->key == KEY_RIGHT_ARROW ||
		inp->key == KEY_UP_ARROW || inp->key == KEY_DOWN_ARROW)
		parse_arrow(inp);
	else if (inp->key == KEY_HOME || inp->key == KEY_END)
	{
		parse_home_end(inp);
	}
	else if (inp->key == KEY_SHIFT_L_ARROW || inp->key == KEY_SHIFT_R_ARROW ||
			inp->key == KEY_SHIFT_U_ARROW || inp->key == KEY_SHIFT_D_ARROW)
	{
		parse_shift_key(inp);
	}
	else if (inp->key == KEY_PAGE_DOWN || inp->key == KEY_PAGE_UP)
	{
		parse_page_keys(inp);
	}
	set_cursor_pos(inp->cr.x, inp->cr.y);
}
