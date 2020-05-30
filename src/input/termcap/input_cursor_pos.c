/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_cursor_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 22:03:30 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 20:09:54 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_termcap.h"

static void					parse_str_cursor(char *buf)
{
	size_t	i;

	i = 0;
	while (i < 32)
	{
		input_read(STDIN_FILENO, &buf[i], 1);
		if (buf[i] == 'R')
		{
			buf[i] = 0;
			break ;
		}
		++i;
	}
}

struct s_cursor				get_pos_cursor(void)
{
	struct s_cursor	cr;
	char			buf[32];
	char			*p_buf;

	input_write(STDOUT_FILENO, GET_POS_CURSOR, 4);
	parse_str_cursor(buf);
	p_buf = buf;
	cr.y = ft_atoi(buf + 2);
	p_buf = ft_skip_before(buf, ';');
	cr.x = ft_atoi(p_buf);
	return (cr);
}

void						set_cursor_pos(int col, int row)
{
	char	*str;

	str = input_tgetstr(CM);
	str = input_tgoto(str, col, row);
	input_tputs(str, 0, ft_putchar);
}
