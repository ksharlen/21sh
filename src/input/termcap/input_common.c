/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_common.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 21:06:48 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/04 01:27:18 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_termcap.h"

struct s_win	get_win_size(void)
{
	struct s_win	wn;

	wn.cols = input_tgetnum(CO);
	wn.rows = input_tgetnum(LI);
	return (wn);
}

// void	clear_curr_line_to_the_end(void)
// {
// 	char	*str;

// 	set_cursor_col(0);
// 	str = input_tgetstr(CD);
// 	input_tputs(str, 0, ft_putchar);
// }

void	clear_window(void)
{
	char	*str;

	str = input_tgetstr(CL);
	input_tputs(str, 0, ft_putchar);
}

void	clear_pos_cr_to_the_end(void)
{
	char	*str;

	str = input_tgetstr(CD);
	input_tputs(str, 0, ft_putchar);
}

void	visibility_cursor(int visible)
{
	char	*str;

	str = input_tgetstr(visible == VISIBLE_CUR ? VE : VI);
	input_tputs(str, 0, ft_putchar);
}
