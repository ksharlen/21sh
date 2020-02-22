/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:55:32 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/19 18:23:31 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_term_var	g_term_lst;

int		main(int argc, char **argv, char **env)
{
	t_init			init;

	(void)(argc);
	(void)(argv);
	sh21_init(&init, env);
	while (1)
	{
		input_begin(&init.inp);
		if ((!init.inp.str_for_parse && init.inp.key == ('d' & 0x1f)) ||
			(init.inp.str_for_parse &&
				!ft_strcmp(init.inp.str_for_parse, "exit")))
			break ;
		else if (!init.inp.str_for_parse)
		{
			//parser(init.inp.str_for_parse, ...);
			//exec(...);
		}
	}
	input_finish(&init.inp);
	return (0);
}
