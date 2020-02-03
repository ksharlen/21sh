/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process_key_press.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 02:50:45 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/04 00:11:05 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

void	input_process_key_press(struct s_input *inp)
{
	if (IS_PRINT_KEY(inp->key) || IS_DEL_KEY(inp->key))
	{
		refresh_screen(inp);
	}
	else
	{
		//cursor_move();
	}
}
