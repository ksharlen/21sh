/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 22:10:43 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/04 01:50:19 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

static void	input_preparation(struct s_input *inp)
{
	inp->win = get_win_size();
	entry_not_canon(&inp->cfg_cpy);
	// input_greeting(&inp->u_info);
	inp->cr = get_pos_cursor();
	--inp->cr.x;
	--inp->cr.y;
	inp->save_refresh_pos = inp->cr;
	inp->key = 0;
}

void	input_begin(struct s_input *inp)
{
	input_preparation(inp);
	while (!PRESS_CTR_D_AND_EMPTY_STR(inp->key, inp->gap.len_string) &&
			inp->key != KEY_NEW_LINE)
	{
		inp->key = input_getch();
		input_process_key_press(inp);
	}
	write(STDOUT_FILENO, "\n", 1);
	entry_canon(&inp->cfg_cpy);
}
