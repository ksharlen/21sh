/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_refresh_screen.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 23:48:03 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 18:12:31 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

static void	clear_screen(struct s_cursor *sv_pos)
{
	visibility_cursor(NOT_VISIBLE_CUR);
	set_cursor_pos(sv_pos->x, sv_pos->y);
	clear_pos_cr_to_the_end();
}

static void	insert_new_line(struct s_input *inp)
{
	size_t	qt_col;

	qt_col = (inp->gap.len_string + inp->greet.len) / inp->win.cols;
	if ((inp->save_refresh_pos.y + qt_col) == (size_t)(inp->win.rows) &&
		(inp->gap.len_string + inp->greet.len >= (qt_col * inp->win.cols)))
	{
		--inp->save_refresh_pos.y;
		--inp->cr.y;
		input_write(STDOUT_FILENO, "\n", 1);
	}
}

void		refresh_screen(struct s_input *inp)
{
	if (inp->key >= 32 && inp->key <= 126)
	{
		gap_putchar_in_buf(&inp->gap, inp->key);
		insert_new_line(inp);
		if (check_line_footnote_down(inp) == FALSE)
			++inp->cr.x;
	}
	else if (inp->key == KEY_DEL || inp->key == ('d' & 0x1f))
		gap_del_sym_on_slide(&inp->gap);
	else if (inp->key == KEY_BCKSPACE)
	{
		if (check_line_footnote_up(inp) == FALSE && inp->gap.slide)
			--inp->cr.x;
		gap_del_sym_before_slide(&inp->gap);
	}
	clear_screen(&inp->save_refresh_pos);
	gap_print_buf(&inp->gap);
	set_cursor_pos(inp->cr.x, inp->cr.y);
	visibility_cursor(VISIBLE_CUR);
}
