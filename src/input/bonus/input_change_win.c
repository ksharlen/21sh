/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_change_win.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 23:24:34 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/06 23:36:07 by ksharlen         ###   ########.fr       */
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
	inp->win = *wn;
	inp->cr = get_pos_cursor();
	--inp->cr.x;
	--inp->cr.y;
}

void	check_change_winsize(struct s_input *inp)
{
	struct s_win	wn;

	input_tgetent();
	wn = get_win_size();
	if (ft_memcmp(&wn, &inp->win, sizeof(struct s_win)))
		input_update_stat_win(inp, &wn);
}
