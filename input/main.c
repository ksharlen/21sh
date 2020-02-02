/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:29:18 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/03 00:38:16 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_init.h"
#include "input_parse_key.h"
#include "input_termcap.h"

//#define MAIN_PART

int		main(void)
{
#ifndef MAIN_PART
	struct s_input	inp;
	int				key;

	entry_not_canon(&inp.cfg_cpy);
	input_init(&inp);
	do
	{
		key = input_getch();
		if (key >= 32 && key <= 127)
			write(STDOUT_FILENO, &key, 1);
		else if (key == CTR_KEY('s'))
			write(STDOUT_FILENO, "OK ", 3);
		else if (key == CTR_KEY('r'))
		{
			// set_cursor_pos(0, 0);
			// char	*str = tgetstr("ch", NULL);
			// str = tgoto(str, 0, 0);
			// tputs(str, 0, ft_putchar);
			// write(STDOUT_FILENO, "hello world", 11);
			// char	*str = tgetstr("ch", NULL);
			// str = tgoto(str, 1, 0);
			// tputs(str, 0, ft_putchar);
		}
		else if (key == CTR_KEY('u'))
		{
			// clear_curr_line_to_the_end();
			write(STDOUT_FILENO, "\x1b[J", 3);
		}
	}
	while (key != KEY_NEW_LINE);

	entry_canon(&inp.cfg_cpy);
#else
	struct s_input inp;

	entry_not_canon(&inp.cfg_cpy);
	input_init(&inp);
	set_cursor_pos(15, 15);
	clear_curr_line_to_the_end();
	// inp.cr = get_pos_cursor();
	// printf("x: %d	y: %d\n", inp.cr.x, inp.cr.y);
	// inp.win = get_win_size();
	// printf("col: %d	rows: %d\n", inp.win.cols, inp.win.rows);
	while (1);
	entry_canon(&inp.cfg_cpy);
#endif
	return (0);
}
