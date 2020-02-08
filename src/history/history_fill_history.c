/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 22:55:57 by dsandshr          #+#    #+#             */
/*   Updated: 2020/02/06 10:20:34 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

t_history	*add_new_elem(t_history *hist, char *str)
{
	t_history_list *tmp;

	if (!(tmp = (t_history_list *)malloc(sizeof(t_history_list))))
		exit(0); //! Вывести ошибку в будущем
	while (hist->h_list->next)
		hist->h_list = hist->h_list->next;
	hist->h_list->next = tmp;
	tmp->prev = hist->h_list;
	tmp->location = hist->h_list->location + 1;
	tmp->comand = ft_strdup(str);
	hist->h_list = tmp;
	hist->end = tmp;
	hist->h_list->next = NULL;
	return (hist);
}

t_history	*fill_history(t_history *hist, char *str)
{
	if (str)
	{
		if (ft_strcmp(hist->end->comand, str))
		{
			hist = add_new_elem(hist, str);
			ft_printf("%v%s\n", hist->fd, hist->h_list->comand);
		}
	}
	return (hist);
}
