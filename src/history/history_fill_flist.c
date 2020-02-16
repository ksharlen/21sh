/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_fill_flist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 22:55:57 by dsandshr          #+#    #+#             */
/*   Updated: 2020/02/16 18:18:23 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

t_history	*history_add_new_elem(t_history *hist, char *str)
{
	t_history_list *tmp;

	tmp = (t_history_list *)ft_memalloc(sizeof(t_history_list));
	ft_chk_null_ptr(tmp, E_MALLOC);
	hist->h_list = hist->end;
	hist->h_list->next = tmp;
	tmp->prev = hist->h_list;
	tmp->location = hist->h_list->location + 1;
	if (str)
		hist->h_list->comand = ft_strdup(ft_strrchrback(str, ';'));
	tmp->comand = NULL;
	hist->h_list = tmp;
	hist->end = tmp;
	hist->h_list->next = NULL;
	return (hist);
}

t_history	*history_fill_history(t_history *hist, char *str)
{
	int len_str;
	int qt_print_char;

	if (str)
	{
		len_str = ft_strlen(str);
		if (!hist->end->prev->comand || ft_strcmp(hist->end->prev->comand, str))
		{
			hist = history_add_new_elem(hist, str);
			ft_printf("%v%zd;", hist->fd, time(NULL));
			qt_print_char = ft_printf("%v%s\n",
				hist->fd, hist->h_list->prev->comand);
			if (len_str != qt_print_char - 1)
			{
				ft_printf("%vhistory_fill_history: file_write_error\n",
					STDERR_FILENO);
			}
		}
	}
	hist->h_list = hist->end;
	return (hist);
}
