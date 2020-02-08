/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mode_term.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 19:33:14 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/08 23:40:12 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_init.h"

void	entry_not_canon(struct termios *st_copy)
{
	struct termios	chg_mode;

	if (st_copy)
	{
		CHK_SYS_ERR_EXT(tcgetattr(STDIN_FILENO, &chg_mode),
			E_TCGETATTR, "entry_canon");
		*st_copy = chg_mode;
		chg_mode.c_lflag &= ~(ICANON | ECHO | ISIG | IEXTEN);
		chg_mode.c_iflag &= ~(IXON | ICRNL);
		chg_mode.c_cc[VMIN] = 0;
		chg_mode.c_cc[VTIME] = 1;
		CHK_SYS_ERR_EXT(tcsetattr(STDIN_FILENO, TCSANOW, &chg_mode),
						E_TCSETATTR, "entry_canon");
	}
}

void	entry_canon(struct termios *st_term)
{
	CHK_SYS_ERR_EXT(tcsetattr(STDIN_FILENO, TCSANOW, st_term),
						E_TCSETATTR, "entry_canon");
}
