/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <tjonella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:55:32 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/24 22:47:02 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

// t_term_var	g_term_lst;

// int		main(int argc, char **argv, char **env)
// {
// 	t_init			init;
// 	//t_vars		vars;

// 	(void)(argc);
// 	(void)(argv);
// 	sh21_init(&init, env);
// 	while (1)
// 	{
// 		input_begin(&init.inp);
// 		if ((!init.inp.str_for_parse && init.inp.key == ('d' & 0x1f)) ||
// 			(init.inp.str_for_parse &&
// 				!ft_strcmp(init.inp.str_for_parse, "exit")))
// 			break ;
// 		else if (init.inp.str_for_parse)
// 		{
// 			//paste_vars(&init.inp.str_for_parse, &vars);		// $$ и $? не парсятся
// 			// parser(init.inp.str_for_parse, &init.prs);
// 			//exec(...);
// 		}
// 	}
// 	input_finish(&init.inp);
// 	return (0);
// }

static void	put_list_test(t_red_stream *stream_list)
{
	while (stream_list)
	{
		printf("stream_a = %d\nstream_in = %d\n", stream_list->stream_a, stream_list->stream_in);
		printf("stream_name = %s\n", stream_list->stream_name);
		printf("flag_file = %d\nflag_close = %d", stream_list->flag_file, stream_list->flag_close);
		stream_list = stream_list->next;
	}
}

int		main(int ac, char **av)
{
	t_pars_list *list;
	char str[90] = ">namefile";
	char *splitter = &str[ft_strlen(str)];

	if (!(list = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (3);
	list->stream_list = NULL;
	
	printf("%s\n", str);
	pars_find_stream(str, splitter, list);
	put_list_test(list->stream_list);
	printf("\n\n\n");
	return (0);
}
