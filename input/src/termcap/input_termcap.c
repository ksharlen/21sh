/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_termcap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 22:35:41 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/02 22:55:52 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_termcap.h"

void	input_tgetent(void)
{
	int	ok;

	ok = tgetent(T_BUFFER, getenv("TERM"));
	if (ok != 1)
	{
		ft_printf("termcap for current terminal not found\n");
		exit(EXIT_FAILURE);
	}
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
	{
		ft_printf("ftsh_tgetstr: empty cb\n");
		exit(EXIT_FAILURE);
	}
	return (str);
}

char	*input_tgoto(char *cb, int one, int two)
{
	char	*str;

	if (cb)
	{
		CHK_NULL_PTR(str = tgoto(cb, one, two), E_TGOTO, "input_tgoto");
	}
	else
	{
		ft_printf("ftsh_tgoto: empty cb\n");
		exit(EXIT_FAILURE);
	}
	return (str);
}

void	input_tputs(const char *str, int affcnt, int (*putc)(int))
{
	if (str)
	{
		CHK_SYS_ERR_EXT(tputs(str, affcnt, putc), E_TPUTS, "input_tputs");
	}
	else
	{
		ft_printf("ftsh_tputs: empty str\n");
		exit(EXIT_FAILURE);
	}
}
