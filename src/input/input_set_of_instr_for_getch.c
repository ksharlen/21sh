/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_set_of_instr_for_getch.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 00:00:40 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/09 00:08:08 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

int		input_get_key_additional(char key)
{
	int	add_key;

	add_key = 0;
	if (key == '1' || key == '7')
		add_key = KEY_HOME;
	else if (key == '3')
		add_key = KEY_DEL;
	else if (key == '4' || key == '8')
		add_key = KEY_END;
	else if (key == '5')
		add_key = KEY_PAGE_UP;
	else if (key == '6')
		add_key = KEY_PAGE_DOWN;
	return (add_key);
}

int		input_get_key_arrow(char key)
{
	int	key_arrow;

	key_arrow = 0;
	if (key == 'A')
		key_arrow = KEY_UP_ARROW;
	else if (key == 'B')
		key_arrow = KEY_DOWN_ARROW;
	else if (key == 'C')
		key_arrow = KEY_RIGHT_ARROW;
	else if (key == 'D')
		key_arrow = KEY_LEFT_ARROW;
	else if (key == 'H')
		key_arrow = KEY_HOME;
	else if (key == 'F')
		key_arrow = KEY_END;
	return (key_arrow);
}

int		input_get_key_shift_arrow(void)
{
	unsigned char	*sym;
	int				key_shift_arrow;

	key_shift_arrow = 0;
	sym = (unsigned char[2]){0};
	CHK_SYS_ERR_EXT(read(STDIN_FILENO, sym, 2), E_READ, P_N);
	if (!sym[1])
	{
		if (sym[0] == 'A')
			key_shift_arrow = KEY_SHIFT_U_ARROW;
		else if (sym[0] == 'B')
			key_shift_arrow = KEY_SHIFT_D_ARROW;
		else if (sym[0] == 'C')
			key_shift_arrow = KEY_SHIFT_R_ARROW;
		else if (sym[0] == 'D')
			key_shift_arrow = KEY_SHIFT_L_ARROW;
	}
	return (key_shift_arrow);
}

int		input_get_key_ctr_arrow(void)
{
	unsigned char	*sym;
	int				key;

	key = 0;
	sym = (unsigned char[2]){0};
	CHK_SYS_ERR_EXT(read(STDIN_FILENO, sym, 2), E_READ, P_N);
	if (!sym[1])
	{
		if (sym[0] == 'A')
			key = KEY_CTR_U_ARROW;
		else if (sym[0] == 'B')
			key = KEY_CTR_D_ARROW;
		else if (sym[0] == 'C')
			key = KEY_CTR_R_ARROW;
		else if (sym[0] == 'D')
			key = KEY_CTR_L_ARROW;
	}
	return (key);
}
