/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_common_screen.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 01:28:50 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/08 01:19:41 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

int		check_line_footnote_down(struct s_input *inp)
{
	int	is_footnote;

	is_footnote = FALSE;
	if (inp->cr.x == inp->win.cols - 1)
	{
		++inp->cr.y;
		inp->cr.x = 0;
		is_footnote = TRUE;
	}
	return (is_footnote);
}

int		check_line_footnote_up(struct s_input *inp)
{
	int is_footnote;

	is_footnote = FALSE;
	if (!inp->cr.x)
	{
		--inp->cr.y;
		inp->cr.x = inp->win.cols - 1;
		is_footnote = TRUE;
	}
	return (is_footnote);
}

void	clear_full_screen(struct s_input *inp)
{
	char				*str;
	struct s_cursor		cursor_after_clear;

	if (inp->save_refresh_pos.y)
	{
		cursor_after_clear.y = inp->cr.y - inp->save_refresh_pos.y;
		cursor_after_clear.x = inp->cr.x;
		visibility_cursor(NOT_VISIBLE_CUR);
		str = input_tgetstr(CL);
		tputs(str, 0, ft_putchar);
		inp->len_greet = inp->greet(&inp->u_info);
		inp->save_refresh_pos = get_pos_cursor();
		--inp->save_refresh_pos.x;
		--inp->save_refresh_pos.y;
		gap_print_buf(&inp->gap);
		inp->cr = cursor_after_clear;
		set_cursor_pos(inp->cr.x, inp->cr.y);
		visibility_cursor(VISIBLE_CUR);
	}
}
