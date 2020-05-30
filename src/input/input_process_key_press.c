/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process_key_press.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 02:50:45 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 18:08:56 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

static int	is_move_key(int key)
{
	if (key == KEY_DOWN_ARROW || key == KEY_UP_ARROW || key == KEY_LEFT_ARROW
		|| key == KEY_RIGHT_ARROW || key == KEY_PAGE_DOWN || key == KEY_PAGE_UP
		|| key == KEY_HOME || key == KEY_END
		|| key == KEY_SHIFT_L_ARROW || key == KEY_SHIFT_R_ARROW
		|| key == KEY_CTR_L_ARROW || key == KEY_CTR_R_ARROW
		|| key == KEY_SHIFT_U_ARROW || key == KEY_SHIFT_D_ARROW
		|| key == ('e' & 0x1f) || key == ('a' & 0x1f))
		return (TRUE);
	else
		return (FALSE);
}

void		input_process_key_press(struct s_input *inp)
{
	if ((inp->key >= 32 && inp->key <= 126) ||
		(inp->key == KEY_DEL || inp->key == KEY_BCKSPACE) ||
		inp->key == ('d' & 0x1f))
		refresh_screen(inp);
	else if (is_move_key(inp->key) == TRUE)
		input_move_cursor(inp);
	else if (inp->key == ('l' & 0x1f))
		clear_full_screen(inp);
	else if (inp->key < 32)
		input_ctr_keys(inp);
}
