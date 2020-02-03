/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_move_cursor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 00:41:07 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/04 01:15:22 by ksharlen         ###   ########.fr       */
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
			--inp->cr.x;
			gap_slide_left(&inp->gap);
		}
	}
	else if (inp->key == KEY_RIGHT_ARROW)
	{
		if (inp->gap.slide < inp->gap.len_string)
		{
			++inp->cr.x;
			gap_slide_right(&inp->gap);
		}
	}
	set_cursor_pos(inp->cr.x, inp->cr.y);
}

void	move_cursor(struct s_input *inp)
{
	if (inp->key == KEY_LEFT_ARROW || inp->key == KEY_RIGHT_ARROW ||
		inp->key == KEY_UP_ARROW || inp->key == KEY_DOWN_ARROW)
		parse_arrow(inp);
	else if (inp->key == KEY_HOME || inp->key == KEY_END)
	{
		
	}
	else if (inp->key == KEY_SHIFT_L_ARROW || inp->key == KEY_SHIFT_R_ARROW)
	{
		
	}
	else if (inp->key == KEY_PAGE_DOWN || inp->key == KEY_PAGE_UP)
	{
		
	}
}
