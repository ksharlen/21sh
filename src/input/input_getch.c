/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_getch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:39:38 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/09 18:19:52 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

static int		get_key_combo_arrow(void)
{
	char	sym;
	int		key_shift_arrow;

	sym = 0;
	key_shift_arrow = 0;
	input_read(STDIN_FILENO, &sym, sizeof(t_byte));
	if (sym == '2')
		key_shift_arrow = input_get_key_shift_arrow();
	else if (sym == '5')
		key_shift_arrow = input_get_key_ctr_arrow();
	return (key_shift_arrow);
}

static int		get_func_key(void)
{
	t_byte	sym[2];
	t_key	key;

	key = 0;
	input_read(STDIN_FILENO, &sym[0], sizeof(t_byte));
	if (sym[0] >= '0' && sym[0] <= '9')
	{
		input_read(STDIN_FILENO, &sym[1], sizeof(t_byte));
		if (sym[1] == '~')
			key = input_get_key_additional(sym[0]);
		else if (sym[0] == '1' && sym[1] == ';')
			key = get_key_combo_arrow();
	}
	else if (KEY_ARROW(sym[1]) || KEY_HOME_END(sym[1]))
		key = input_get_key_arrow(sym[1]);
	else
		key = 0;
	return (key);
}

static	t_key	waiting_event(void)
{
	ssize_t	nbyte;
	t_byte	sym;

	nbyte = 0;
	while (!nbyte)
	{
		nbyte = input_read(STDIN_FILENO, &sym, sizeof(t_byte));
		//TODO
	}
	return (sym);
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
	t_byte	sym;
	ssize_t	nread;

	sym = waiting_event();
	if (sym == ESC)
	{
		nread = input_read(STDIN_FILENO, &sym, sizeof(t_byte));
		if (sym == '[')
			sym = get_func_key();
		else
			sym = 0;
	}
	return (sym);
}
