/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 22:10:43 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/03 23:04:19 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

static void	input_preparation(struct s_input *inp)
{
	entry_not_canon(&inp->cfg_cpy);
	// input_greeting(inp->)
	inp->cr = get_pos_cursor();
	--inp->cr.x;
	--inp->cr.y;
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
	entry_canon(&inp->cfg_cpy);
}
