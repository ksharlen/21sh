/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_change_win.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 23:24:34 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/06 23:29:01 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh_bonus.h"

static void	input_update_stat_win(struct s_input *inp, struct s_win *wn)
{
	ssize_t	curr_qt_rows;
	ssize_t	chg_qt_rows;
	ssize_t	reminder;

	curr_qt_rows = ((inp->len_greet + inp->gap.len_string) / inp->win.cols) +
	((inp->len_greet + inp->gap.len_string) % inp->win.cols ? 1 : 0);
	chg_qt_rows = (inp->len_greet + inp->gap.len_string) / wn->cols +
	((inp->len_greet + inp->gap.len_string) % wn->cols ? 1 : 0);
	reminder = curr_qt_rows - chg_qt_rows;
	if (reminder)
	{
		if (reminder > 0)
		{
			inp->save_refresh_pos.y += FT_ABS(reminder);
		}
		else
		{
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
	{
		// inp->win = wn;
		input_update_stat_win(inp, &wn);
	}
		// inp->win = wn;
}

