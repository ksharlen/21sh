/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:55:32 by ksharlen          #+#    #+#             */
/*   Updated: 2020/04/07 10:50:43 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_term_var	g_term_lst;

static void sh21_finish()
{
	ft_strdel_split(g_sh_environ);
}

int			main(int argc, char **argv, char **env)
{
	t_init			init;

	(void)(argc);
	(void)(argv);
	(void)(env);
	sh21_init(&init, env);
	while (1)
	{
		input_begin(&init.inp);
		if ((!init.inp.str_for_parse && init.inp.key == ('d' & 0x1f)))
			break ;
		else if (init.inp.str_for_parse &&
			!parser(&(init.inp.str_for_parse), &init.prs))
				check_choice(init.execlist, init.prs.beg);
		free_befor_exec(&init.prs);
	}
	input_finish(&init.inp);
	sh21_finish();
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
// 	init.inp.str_for_parse = ft_strdup("ls");
// 	if (!parser(&(init.inp.str_for_parse), &init.prs))
// 		check_choice(init.execlist, init.prs.beg);
// 	free_befor_exec(&init.prs);
// 	input_finish(&init.inp);
// 	sh21_finish();
// 	return (0);
// }
