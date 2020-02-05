/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_getch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:39:38 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/05 19:23:23 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

static int		get_key_additional(char key)
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

static int		get_key_arrow(char key)
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

static int		get_key_shift_arrow(void)
{
	char	*sym;
	int		key_shift_arrow;

	sym = (char[3]){0};
	key_shift_arrow = 0;
	CHK_SYS_ERR_EXT(read(STDIN_FILENO, &sym[0], ONE_SYM), E_READ, P_N);
	if (sym[0] == '2')
	{
		CHK_SYS_ERR_EXT(read(STDIN_FILENO, sym + 1, 2), E_READ, P_N);
		if (!sym[2])
		{
			if (sym[1] == 'A')
				key_shift_arrow = KEY_SHIFT_U_ARROW;
			else if (sym[1] == 'B')
				key_shift_arrow = KEY_SHIFT_D_ARROW;
			else if (sym[1] == 'C')
				key_shift_arrow = KEY_SHIFT_R_ARROW;
			else if (sym[1] == 'D')
				key_shift_arrow = KEY_SHIFT_L_ARROW;
		}
	}
	return (key_shift_arrow);
}

static int		get_func_key(struct s_key *key)
{
	CHK_SYS_ERR_EXT(key->nread = read(STDIN_FILENO, &key->read_key[2], ONE_SYM),
		E_READ, "input_getch");
	if (key->read_key[2] >= '0' && key->read_key[2] <= '9')
	{
		CHK_SYS_ERR_EXT(key->nread = read(STDIN_FILENO,
			&key->read_key[3], ONE_SYM), E_READ, "input_getch");
		if (key->read_key[3] == '~')
			key->key = get_key_additional(key->read_key[2]);
		else if (key->read_key[2] == '1' && key->read_key[3] == ';')
			key->key = get_key_shift_arrow();
	}
	else if (KEY_ARROW(key->read_key[2]) || KEY_HOME_END(key->read_key[2]))
		key->key = get_key_arrow(key->read_key[2]);
	else
		key->key = 0;
	return (key->key);
}

int				input_getch(void)
{
	struct s_key	key;

	CHK_SYS_ERR_EXT(key.nread = read(STDIN_FILENO, &key.read_key[0], ONE_SYM),
		E_READ, "input_getch");
	if (key.read_key[0] == ESC)
	{
		CHK_SYS_ERR_EXT(key.nread = read(STDIN_FILENO, &key.read_key[1],
			ONE_SYM), E_READ, "input_getch");
		if (key.read_key[1] == '[')
			key.key = get_func_key(&key);
		else
			key.key = 0;
	}
	else
		key.key = key.read_key[0];
	return (key.key);
}