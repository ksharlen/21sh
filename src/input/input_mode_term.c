/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mode_term.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 19:33:14 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 18:08:43 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_init.h"

void	entry_not_canon(struct termios *st_copy)
{
	struct termios	chg_mode;
	int				ret_tcgetattr;
	int				ret_tcsetattr;

	if (st_copy)
	{
		ret_tcgetattr = tcgetattr(STDIN_FILENO, &chg_mode);
		ft_chk_sys_error(ret_tcgetattr, E_TCGETATTR);
		*st_copy = chg_mode;
		chg_mode.c_lflag &= ~(ICANON | ECHO | ISIG | IEXTEN);
		chg_mode.c_iflag &= ~(IXON | ICRNL);
		chg_mode.c_cc[VMIN] = 0;
		chg_mode.c_cc[VTIME] = 1;
		ret_tcsetattr = tcsetattr(STDIN_FILENO, TCSANOW, &chg_mode);
		ft_chk_sys_error(ret_tcsetattr, E_TCSETATTR);
	}
}

void	entry_canon(struct termios *st_term)
{
	int		ret_tcsetattr;

	if (st_term)
	{
		ret_tcsetattr = tcsetattr(STDIN_FILENO, TCSANOW, st_term);
		ft_chk_sys_error(ret_tcsetattr, E_TCSETATTR);
	}
}
