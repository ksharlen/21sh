/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:55:32 by ksharlen          #+#    #+#             */
/*   Updated: 2020/03/20 19:18:40 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_term_var	g_term_lst;

int		main(int argc, char **argv, char **env)
{
	t_init			init;

	(void)(argc);
	(void)(argv);
	(void)(env);
	sh21_init(&init, env);
	while (1)
	{
		input_begin(&init.inp);
		if ((!init.inp.str_for_parse && init.inp.key == ('d' & 0x1f)) ||
				(init.inp.str_for_parse &&
				!ft_strcmp(init.inp.str_for_parse, "exit")))
			break ;
		else if (init.inp.str_for_parse)
			if (!parser(&(init.inp.str_for_parse), &init.prs))
				check_choice(init.execlist, init.prs.beg);
		free_befor_exec(&init.prs);
	}
	input_finish(&init.inp);
	return (0);
}

//* (+) "$> ls 1>&-" - ломается шелл (предположительно, в парсинге)
//* (+) "$> ls & pwd" - падает шелл в функции find_delimiter строка 69

//* (-) "$> ls & && pwd" "$> ls & || pwd" "$> ls &| pwd" -работают
//		если первые варианты ещё допустимы, то третий вариант нет.

// int		main(int argc, char **argv, char **env)
// {
// 	t_init			init;

// 	(void)(argc);
// 	(void)(argv);
// 	(void)(env);
// 	sh21_init(&init, env);
// 	init.inp.str_for_parse = ft_strdup("ls & pwd");
// 	if (!parser(&(init.inp.str_for_parse), &init.prs))
// 		check_choice(init.execlist, init.prs.beg);
// 	free_befor_exec(&init.prs);
// 	input_finish(&init.inp);
// 	return (0);
// }
