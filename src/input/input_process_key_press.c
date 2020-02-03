/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process_key_press.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 02:50:45 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/04 01:14:44 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

static int	is_move_key(int key)
{
	if (key == KEY_DOWN_ARROW || key == KEY_UP_ARROW || key == KEY_LEFT_ARROW
		|| key == KEY_RIGHT_ARROW || key == KEY_PAGE_DOWN || key == KEY_PAGE_UP
		|| key == KEY_HOME || key == KEY_END
		|| key == KEY_SHIFT_L_ARROW || key == KEY_SHIFT_R_ARROW)
		return (TRUE);
	else
		return (FALSE);
}

void	input_process_key_press(struct s_input *inp)
{
	if (IS_PRINT_KEY(inp->key) ||
		IS_DEL_KEY(inp->key) ||
		inp->key == CTR_KEY('d'))
	{
		refresh_screen(inp);
	}
	else if (is_move_key(inp->key) == TRUE)
	{
		move_cursor(inp);
	}
}
