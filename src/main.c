/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:55:32 by ksharlen          #+#    #+#             */
/*   Updated: 2020/03/08 23:23:06 by ksharlen         ###   ########.fr       */
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
									/*** test ***/	// необходимо реализовать заполнение интерфейса для exec
									// init.inp.str_for_parse = ft_strdup("ls > newfile");
									// ft_strcpy(execlist.exec_envlist.path, "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Frameworks/Mono.framework/Versions/Current/Commands:/usr/local/munki:/Library/TeX/texbin");
									/*** test ***/
		if ((!init.inp.str_for_parse && init.inp.key == ('d' & 0x1f)) ||
			(init.inp.str_for_parse &&
				!ft_strcmp(init.inp.str_for_parse, "exit")))
			break ;
		else if (init.inp.str_for_parse)
		{
			//paste_vars(&init.inp.str_for_parse, &vars);		// $$ и $? не парсятся
			if (!parser(init.inp.str_for_parse, &init.prs))
				check_choice(init.execlist, init.prs.beg);
		}
		free_befor_exec(&init.prs);
	}
	input_finish(&init.inp);
	return (0);
}

// (+) добавить '\n' в echo
// (+) "$> ls;;" - ломает шелл
// (+) "$> ls ; exit " - не завершается шелл
// (+/-) quote с кавычками должен делать перенос строк, где требуется

//* (-) Ctrl+C или Ctrl+D при работающих командах, например "ls -lR /", - не работают
//* (-) "$> cat " - не работет обработка сигналов
//* (-) - Run the command "$> cat" then press ctrl+C. The shell must kill cat's proccess and give back the prompt.
// (-) Ctrl+T при последовательности действий: нажатие->стирание->нажатие - падает шелл
// (-) при вставке новой строки появляется БАГ
// (-) не заполнен интерфейс execlist.exec_envlist.path
// (-) env go-go-go

// (-) не работают перенаправления потоков

// (-) " ~ " - не подставляет домашнюю директорию
// (-) exit - не возвращает число завершения
// (-) cd не работает (довести до работоспособности все внутренние команды)
// (-) "$> cat -e << EOF >> /tmp/test.txt"

/*** for tests ***/

// int		main(int argc, char **argv, char **env)
// {
// 	t_init			init;

// 	(void)(argc);
// 	(void)(argv);
// 	(void)(env);
// 	sh21_init(&init, env);
// 	init.inp.str_for_parse = ft_strdup("echo > namefile");
// 	ft_strcpy(execlist.exec_envlist.path, "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Frameworks/Mono.framework/Versions/Current/Commands:/usr/local/munki:/Library/TeX/texbin");
// 	if (!parser(init.inp.str_for_parse, &init.prs))
// 		check_choice(execlist, init.prs.beg);
// 	free_befor_exec(&init.prs);
// 	input_finish(&init.inp);
// 	return (0);
// }
