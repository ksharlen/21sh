/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_refresh_screen.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 23:48:03 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/06 18:08:40 by ksharlen         ###   ########.fr       */
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

//!можно оптимизировать
	qt_col = (inp->gap.len_string + inp->len_greet) / inp->win.cols;
	if ((inp->save_refresh_pos.y + qt_col) == (size_t)(inp->win.rows) &&
		(inp->gap.len_string + inp->len_greet >= (qt_col * inp->win.cols)))
	{
		--inp->save_refresh_pos.y;
		--inp->cr.y;
		write(STDOUT_FILENO, "\n", 1);
	}
}

void	refresh_screen(struct s_input *inp)
{
	char	*out_str;

	if (IS_PRINT_KEY(inp->key))
	{
		gap_putchar_in_buf(&inp->gap, inp->key);
		insert_new_line(inp);
		if (check_line_footnote_down(inp) == FALSE)
			++inp->cr.x;
	}
	else if (inp->key == KEY_DEL || inp->key == CTR_KEY('d'))
	{
		gap_del_sym_on_slide(&inp->gap);
	}
	else if (inp->key == KEY_BCKSPACE)
	{
		if (check_line_footnote_up(inp) == FALSE && inp->gap.slide)
			--inp->cr.x;
		gap_del_sym_before_slide(&inp->gap);
	}
	clear_screen(&inp->save_refresh_pos);
	out_str = gap_get_buf(&inp->gap);
	write(STDOUT_FILENO, out_str, inp->gap.len_string);
	ft_strdel(&out_str);
// //!TMP
	char	buf[200] = {0};

	set_cursor_pos(0, inp->win.rows - 1);
	snprintf(buf, 200, "cols: %d	rows: %d	x: %d	y: %d	size_greet: %zd", inp->win.cols,
		inp->win.rows, inp->cr.x, inp->cr.y, inp->len_greet);
	write(STDOUT_FILENO, buf, 200);
	set_cursor_pos(0, inp->win.rows - 2);
	bzero(buf, 200);
	snprintf(buf, 200, "GAP_LEN: %zd	GAP_SIZE: %zd	GAP_START: %zd	GAP_END: %zd	GAP_SLIDE: %zd",
		inp->gap.len_string, inp->gap.size_gap_buf, inp->gap.gap_start, inp->gap.gap_end, inp->gap.slide);
	write(STDOUT_FILENO, buf, 200);
// //!TMP
	set_cursor_pos(inp->cr.x, inp->cr.y);
	visibility_cursor(VISIBLE_CUR);
}
