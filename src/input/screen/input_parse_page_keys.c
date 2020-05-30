/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse_page_keys.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 20:49:41 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 18:11:42 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

static void	parse_page_up(struct s_input *inp)
{
	struct s_cursor	beg;

	beg = inp->save_refresh_pos;
	if (inp->cr.y >= beg.y)
	{
		if (inp->cr.y == beg.y ||
			((inp->cr.y - beg.y) == 1 && inp->cr.x <= beg.x))
		{
			inp->cr = beg;
			inp->gap.slide = 0;
		}
		else
		{
			--inp->cr.y;
			inp->gap.slide -= inp->win.cols;
		}
	}
}

static void	parse_page_down(struct s_input *inp)
{
	struct s_cursor	end;

	end = input_get_end_string(inp);
	if (inp->cr.y <= end.y)
	{
		if (inp->cr.y == end.y ||
			(inp->cr.x > end.x && (end.y - inp->cr.y) == 1))
		{
			inp->cr = end;
			inp->gap.slide = inp->gap.len_string;
		}
		else if (inp->cr.x <= end.x || ((end.y - 1) - inp->cr.y))
		{
			++inp->cr.y;
			inp->gap.slide += inp->win.cols;
		}
	}
}

void		input_parse_page_keys(struct s_input *inp)
{
	if (inp->key == KEY_SHIFT_D_ARROW || inp->key == KEY_PAGE_DOWN)
		parse_page_down(inp);
	else if (inp->key == KEY_SHIFT_U_ARROW || inp->key == KEY_PAGE_UP)
		parse_page_up(inp);
}
