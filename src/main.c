/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:55:32 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/29 20:40:48 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_term_var	g_term_lst;

// static void	put_list_test(t_red_stream *stream_list)
// {
// 	while (stream_list)
// 	{
// 		printf("stream_a = %d\nstream_in = %d\n", stream_list->stream_a, stream_list->stream_in);
// 		printf("stream_name = %s\n", stream_list->stream_name);
// 		printf("flag_file = %d\nflag_close = %d\n\n", stream_list->flag_file, stream_list->flag_close);
// 		stream_list = stream_list->next;
// 	}
// }

// static void		test_stream(void)
// {
// 	t_pars_list *list;
// 	char str0[90] = ">namefile";
// 	char *splitter = &str0[ft_strlen(str0)];

// 	if (!(list = (t_pars_list *)malloc(sizeof(t_pars_list))))
// 	list->stream_list = NULL;

// 	printf("%s\n", str0);
// 	pars_find_stream(str0, splitter, list);

// 	char str1[90] = "&>-";
// 	splitter = &str1[ft_strlen(str1)];
// 	printf("%s\n", str1);
// 	pars_find_stream(str1, splitter, list);

// 	char str2[90] = "1>&-";
// 	splitter = &str2[ft_strlen(str2)];
// 	printf("%s\n", str2);
// 	pars_find_stream(str2, splitter, list);

// 	char str3[20] = "2<file2";
// 	splitter = &str3[ft_strlen(str3)];
// 	printf("%s\n", str3);
// 	pars_find_stream(str3, splitter, list);

// 	char str4[20] = ">>file2";
// 	splitter = &str4[ft_strlen(str4)];
// 	printf("%s\n", str4);
// 	pars_find_stream(str4, splitter, list);

// 	char str5[20] = "><name5";
// 	splitter = &str5[ft_strlen(str5)];
// 	printf("%s\n", str5);
// 	pars_find_stream(str5, splitter, list);

// 	char str6[40] = ">      				<          name6";
// 	splitter = &str6[ft_strlen(str6)];
// 	printf("%s\n", str6);
// 	pars_find_stream(str6, splitter, list);

// 	char str7[20] = "2>&1";
// 	splitter = &str7[ft_strlen(str7)];
// 	printf("%s\n", str7);
// 	pars_find_stream(str7, splitter, list);

// 	printf("\n");
// 	put_list_test(list->stream_list);
// 	printf("\n\n\n");
// }

int		main(int argc, char **argv, char **env)
{
	t_init			init;
	//t_vars		vars;

	(void)(argc);
	(void)(argv);
	(void)(env);
	sh21_init(&init, env);
	while (1)
	{
		input_begin(&init.inp);
									/*** test ***/	// необходимо реализовать заполнение интерфейса для exec
									// init.inp.str_for_parse = ft_strdup("ls kdirjsurif || ls -l && pwd");
									ft_strcpy(execlist.exec_envlist.path, "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Frameworks/Mono.framework/Versions/Current/Commands:/usr/local/munki:/Library/TeX/texbin");
									/*** test ***/
		if ((!init.inp.str_for_parse && init.inp.key == ('d' & 0x1f)) ||
			(init.inp.str_for_parse &&
				!ft_strcmp(init.inp.str_for_parse, "exit")))
			break ;
		else if (init.inp.str_for_parse)
		{
			//paste_vars(&init.inp.str_for_parse, &vars);		// $$ и $? не парсятся
			if (!parser(init.inp.str_for_parse, &init.prs))
				check_choice(execlist, init.prs.beg);
		}
		free_befor_exec(&init.prs);
	}
	input_finish(&init.inp);
	return (0);
}

// (-) "$> ls;;" - ломает шел


/*** for tests ***/

// int		main(int argc, char **argv, char **env)
// {
// 	t_init			init;
// 	//t_vars		vars;

// 	(void)(argc);
// 	(void)(argv);
// 	(void)(env);
// 	sh21_init(&init, env);
// 	init.inp.str_for_parse = ft_strdup("ls;;");
// 	ft_strcpy(execlist.exec_envlist.path, "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Frameworks/Mono.framework/Versions/Current/Commands:/usr/local/munki:/Library/TeX/texbin");
// 	if (!parser(init.inp.str_for_parse, &init.prs))
// 		check_choice(execlist, init.prs.beg);
// 	free_befor_exec(&init.prs);
// 	input_finish(&init.inp);
// 	return (0);
// }
