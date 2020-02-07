/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_set_of_instr_for_getch.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 00:00:40 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/08 00:14:46 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

int	input_get_key_shift_arrow(void)
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

int	input_get_key_ctr_arrow(void)
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
