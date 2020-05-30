/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_change_win.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 23:24:34 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 19:56:19 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_bonus.h"

static ssize_t	get_reminder_row(struct s_input *inp, struct s_win *wn)
{
	ssize_t	curr_qt_rows;
	ssize_t	chg_qt_rows;

	curr_qt_rows = ((inp->greet.len + inp->gap.len_string) / inp->win.cols) +
		((inp->greet.len + inp->gap.len_string) % inp->win.cols ? 1 : 0);
	chg_qt_rows = (inp->greet.len + inp->gap.len_string) / wn->cols +
		((inp->greet.len + inp->gap.len_string) % wn->cols ? 1 : 0);
	return (curr_qt_rows - chg_qt_rows);
}

static void		first_row_set_coor(struct s_input *inp, struct s_win *wn)
{
	struct s_cursor	crr;
	ssize_t			reminder;

	reminder = get_reminder_row(inp, wn);
	if (reminder > 0)
		inp->save_refresh_pos.y += (reminder > 0 ? reminder : -reminder);
	else
	{
		input_tputs(input_tgetstr(CL), 0, ft_putchar);
		set_cursor_pos(0, 0);
		input_greeting(&inp->greet);
		crr.y = (inp->gap.slide + inp->greet.len) / wn->cols;
		crr.x = (inp->gap.slide + inp->greet.len) % wn->cols;
		inp->cr = crr;
	}
}

static void		set_cursor_inside_new_win(struct s_input *inp)
{
	get_coor_word(inp, inp->greet.len + inp->gap.slide);
	set_cursor_pos(inp->cr.x, inp->cr.y);
}

static void		input_update_stat_win(struct s_input *inp, struct s_win *wn)
{
	ssize_t	reminder;

	if (inp->save_refresh_pos.y)
	{
		reminder = get_reminder_row(inp, wn);
		if (reminder)
		{
			if (reminder > 0)
				inp->save_refresh_pos.y +=
					(reminder > 0 ? reminder : -reminder);
			else
				inp->save_refresh_pos.y -=
					(reminder > 0 ? reminder : -reminder);
		}
	}
	else
		first_row_set_coor(inp, wn);
	input_update_rows(inp, wn);
	inp->win = *wn;
	set_cursor_inside_new_win(inp);
}

void			check_change_winsize(t_exec_lst *execlist, struct s_input *inp)
{
	struct s_win	wn;

	input_tgetent(execlist);
	wn = get_win_size();
	if (ft_memcmp(&wn, &inp->win, sizeof(struct s_win)))
		input_update_stat_win(inp, &wn);
}
