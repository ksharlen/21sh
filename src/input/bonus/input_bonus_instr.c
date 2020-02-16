/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus_instr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:52:56 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 19:57:06 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_bonus.h"

void	input_update_rows(struct s_input *inp, struct s_win *wn)
{
	ssize_t	reminder;

	reminder = 0;
	if (inp->win.rows != wn->rows)
	{
		if (inp->win.rows > wn->rows)
			;
		else if (inp->win.rows < wn->rows)
		{
			reminder = wn->rows - inp->win.rows;
			inp->save_refresh_pos.y += reminder;
		}
	}
}
