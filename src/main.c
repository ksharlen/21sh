/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:55:32 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/06 22:39:28 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		main(void)
{
	t_init			init;

	sh21_init(&init);
	while (1)
	{
		input_begin(&init.inp);
		if ((!init.inp.str_for_parse && init.inp.key == CTR_KEY('d')) ||
			(init.inp.str_for_parse && !ft_strcmp(init.inp.str_for_parse, "exit")))
			break ;
		// if ((!init.inp.parse_str && init.inp.key == CTR_KEY('d')) || (str && !ft_strcmp(str, "exit")))
			// break ;
		// ft_printf("str: %s\n", str ? str : "empty_str");
	}
	input_finish(&init.inp);
	return (0);
}