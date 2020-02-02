/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_cursor_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 22:03:30 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/03 00:45:19 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_termcap.h"

static void					parse_str_cursor(char *buf)
{
	size_t	i;

	i = 0;
	CHK_SYS_ERR_EXT(read(STDIN_FILENO, buf, 32), E_READ, "get_pos_cursor");
	while (i < 32)
	{
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

	CHK_SYS_ERR_EXT(write(STDOUT_FILENO, GET_POS_CURSOR),
		E_WRITE, "get_pos_cursor");
	parse_str_cursor(buf);
	p_buf = buf;
	cr.y = ft_atoi(buf + 2);
	p_buf = ft_skip_before(buf, ';');
	cr.x = ft_atoi(p_buf);
	return (cr);
}

void	set_cursor_pos(int col, int row)
{
	char	*str;

	str = input_tgetstr(CM);
	str = input_tgoto(str, col, row);
	input_tputs(str, 0, ft_putchar);
}

void	set_cursor_col(int col)
{
	char	*str;

	str = input_tgetstr(CH);
	str = input_tgoto(str, 0, col);
	input_tputs(str, 0, ft_putchar);
}

void	set_cursor_row(int row)
{
	char	*str;

	str = input_tgetstr(CV);
	str = input_tgoto(str, 0, row);
	input_tputs(str, 0, ft_putchar);
}
