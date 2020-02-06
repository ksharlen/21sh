/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:55:32 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/06 21:31:49 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		main(void)
{
	t_init			init;
	char			*str;

	sh21_init(&init);
	while (1)
	{
		str = input_begin(&init.inp);
		if ((!str && init.inp.key == CTR_KEY('d')) || (str && !ft_strcmp(str, "exit")))
			break ;
		// ft_printf("str: %s\n", str ? str : "empty_str");
		ft_strdel(&str);
	}
	input_finish(&init.inp);
	return (0);
}