/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_hist_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:01:56 by dsandshr          #+#    #+#             */
/*   Updated: 2020/02/08 17:06:21 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

static t_history	*fill_21sh_story(t_history *hist, char *line)
{
	char			*tmp;

	hist->h_list->comand = ft_strdup(line);
	ft_strdel(&line);
	hist->size += 1;
	while (get_next_line(hist->fd, &line, FLAG_OFF) == 1)
	{
		tmp = line;
		hist = add_new_elem(hist, tmp);
		free(line);
		hist->size += 1;
	}
	//ft_strdel(&line);
	get_next_line(hist->fd, &line, FLAG_ON);
	//ft_strdel(&line);
	return (hist);
}

static t_history	*alloc_args(t_history *h, t_history_list *hl)
{
	h->beg = hl;
	h->end = hl;
	hl->comand = NULL;
	hl->prev = NULL;
	hl->next = NULL;
	hl->location = 1;
	h->h_list = hl;
	h->size = 0;
	return (h);
}

t_history			*history_init(void)
{
	char			*line;
	t_history		*history;
	t_history_list	*h_list;

	if (!(history = (t_history *)malloc(sizeof(t_history))))
		exit(0); //! Вывести ошибку в будущем
	if (!(h_list = (t_history_list *)malloc(sizeof(t_history_list))))
		exit(0); //! Вывести ошибку в будущем
	history->fd = open(".21sh_history", O_CREAT | O_RDWR | O_APPEND,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	history = alloc_args(history, h_list);
	if (!(get_next_line(history->fd, &line, FLAG_OFF)))
	{
		get_next_line(history->fd, &line, FLAG_ON);
		return (history);
	}
	else
		return (fill_21sh_story(history, line));
}
