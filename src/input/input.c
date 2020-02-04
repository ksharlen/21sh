/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 22:10:43 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/05 00:12:23 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

static void	input_preparation(struct s_input *inp)
{
	gap_clean_buf(&inp->gap);
	inp->win = get_win_size();
	entry_not_canon(&inp->cfg_cpy);
	input_greeting(&inp->u_info);
	inp->cr = get_pos_cursor();
	--inp->cr.x;
	--inp->cr.y;
	inp->save_refresh_pos = inp->cr;
	inp->key = 0;
}

char	*input_begin(struct s_input *inp)
{
	char	*cmd;

	input_preparation(inp);
	while (!PRESS_CTR_D_AND_EMPTY_STR(inp->key, inp->gap.len_string) &&
			inp->key != KEY_NEW_LINE)
	{
		inp->key = input_getch();
		input_process_key_press(inp);
	}
	write(STDOUT_FILENO, "\n", 1);
	cmd = gap_get_buf(&inp->gap);
	entry_canon(&inp->cfg_cpy);
	return (cmd);
}
