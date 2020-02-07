/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_change_win.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 23:24:34 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/07 23:48:09 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh_bonus.h"

static ssize_t	get_reminder_row(struct s_input *inp, struct s_win *wn)
{
	ssize_t	curr_qt_rows;
	ssize_t	chg_qt_rows;

	curr_qt_rows = ((inp->len_greet + inp->gap.len_string) / inp->win.cols) +
		((inp->len_greet + inp->gap.len_string) % inp->win.cols ? 1 : 0);
	chg_qt_rows = (inp->len_greet + inp->gap.len_string) / wn->cols +
		((inp->len_greet + inp->gap.len_string) % wn->cols ? 1 : 0);
	return (curr_qt_rows - chg_qt_rows);
}

static void	first_row_set_coor(struct s_input *inp, struct s_win *wn)
{
	struct s_cursor	crr;
	ssize_t	reminder;

	reminder = get_reminder_row(inp, wn);
	if (reminder > 0)
		inp->save_refresh_pos.y += FT_ABS(reminder);
	else
	{
		input_tputs(input_tgetstr(CL), 0, ft_putchar);
		set_cursor_pos(0, 0);
		inp->greet(&inp->u_info);
		crr.y = (inp->gap.slide + inp->len_greet) / wn->cols;
		crr.x = (inp->gap.slide + inp->len_greet) % wn->cols;
		inp->cr = crr;
	}
}

static void	set_cursor_inside_new_win(struct s_input *inp)
{
	get_coor_word(inp, inp->len_greet + inp->gap.slide);
	set_cursor_pos(inp->cr.x, inp->cr.y);
}

static void	input_update_stat_win(struct s_input *inp, struct s_win *wn)
{
	ssize_t	reminder;

	if (inp->save_refresh_pos.y)
	{
		reminder = get_reminder_row(inp, wn);
		if (reminder)
		{
			if (reminder > 0)
				inp->save_refresh_pos.y += FT_ABS(reminder);
			else
				inp->save_refresh_pos.y -= FT_ABS(reminder);
		}
	}
	else
		first_row_set_coor(inp, wn);
	inp->win = *wn;
	set_cursor_inside_new_win(inp);
}

void	check_change_winsize(struct s_input *inp)
{
	struct s_win	wn;

	input_tgetent();
	wn = get_win_size();
	if (ft_memcmp(&wn, &inp->win, sizeof(struct s_win)))
		input_update_stat_win(inp, &wn);
}
