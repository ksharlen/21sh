/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_termcap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 22:35:41 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/02 23:37:47 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_termcap.h"

void	input_tgetent(void)
{
	int	ok;

	ok = tgetent(T_BUFFER, getenv("TERM"));
	if (ok != 1)
		input_error_ext("termcap for current terminal not found");
}

char	*input_tgetstr(char *cb)
{
	char	*str;

	str = NULL;
	if (cb)
	{
		CHK_NULL_PTR(str = tgetstr(cb, T_BUFFER), E_TGETENT, "input_tgetstr");
	}
	else
		input_error_ext("input_tgetstr: empty cb");
	return (str);
}

char	*input_tgoto(char *cb, int one, int two)
{
	char	*str;

	str = NULL;
	if (cb)
	{
		CHK_NULL_PTR(str = tgoto(cb, one, two), E_TGOTO, "input_tgoto");
	}
	else
		input_error_ext("input_tgoto: empty cb");
	return (str);
}

void	input_tputs(const char *str, int affcnt, int (*putc)(int))
{
	if (str)
	{
		CHK_SYS_ERR_EXT(tputs(str, affcnt, putc), E_TPUTS, "input_tputs");
	}
	else
		input_error_ext("input_tputs: empty str");
}

int		input_tgetnum(char *str)
{
	int		val;

	val = -1;
	if (str)
	{
		val = tgetnum(str);
		if (val == -1)
			input_error_ext("input_tgetnum: val = -1");
	}
	else
		input_error_ext("input_tgetnum: empty str");
	return (val);
}
