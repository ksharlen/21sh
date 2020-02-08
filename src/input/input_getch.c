/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_getch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:39:38 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/09 00:10:30 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

static int		get_key_combo_arrow(void)
{
	char	sym;
	int		key_shift_arrow;

	sym = 0;
	key_shift_arrow = 0;
	CHK_SYS_ERR_EXT(read(STDIN_FILENO, &sym, ONE_SYM), E_READ, P_N);
	if (sym == '2')
		key_shift_arrow = input_get_key_shift_arrow();
	else if (sym == '5')
		key_shift_arrow = input_get_key_ctr_arrow();
	return (key_shift_arrow);
}

static int		get_func_key(void)
{
	ssize_t	nread;
	t_key	key[2];

	nread = input_read(STDIN_FILENO, &key[0], ONE_SYM);
	if (key[0] >= '0' && key[0] <= '9')
	{
		input_read(STDIN_FILENO, &key[1], ONE_SYM);
		if (key[1] == '~')
			key[0] = input_get_key_additional(key->read_key[0]);
		else if (key[0] == '1' && key[1] == ';')
			key[0] = get_key_combo_arrow();
	}
	else if (KEY_ARROW(key->read_key[2]) || KEY_HOME_END(key->read_key[2]))
		key->key = input_get_key_arrow(key->read_key[2]);
	else
		key->key = 0;
	return (key->key);
}

static	t_key	get_key_hooK(void)
{
	ssize_t	nbyte;
	t_key	key;

	nbyte = 0;
	while (!nbyte)
	{
		nbyte = input_read(STDIN_FILENO, key, ONE_SYM);
		//TODO
	}
}

ssize_t		input_read(const int fd, void *buf, const size_t nbyte)
{
	ssize_t	ret_read;

	ret_read = read(fd, buf, nbyte);
	ft_chk_sys_error(ret_read, E_READ);
	return (ret_read);
}

int				input_getch(void)
{
	t_key	key;
	ssize_t	nread;

	key = get_key_hook();
	if (key == ESC)
	{
		nread = input_read(STDIN_FILENO, &key, ONE_SYM);
		if (key == '[')
			key = get_func_key();
		else
			key = 0;
	}
	return (key);
}
