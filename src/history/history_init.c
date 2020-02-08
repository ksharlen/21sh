/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:01:56 by dsandshr          #+#    #+#             */
/*   Updated: 2020/02/08 21:09:22 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"
char		*ft_strrchrback(const char *s, int c)
{
	const char *p_str;

	if (s)
	{
		p_str = s;
		while (*p_str)
		{
			if (*p_str == c)
				return ((char *)p_str + 1);
			p_str++;
		}
		return ((char *)s);
	}
	return (NULL);
}

static t_history	*fill_21sh_story(t_history *hist, char *line)
{
	char			*tmp;

	hist->beg->comand = ft_strdup(ft_strrchrback(line, ';'));
	ft_strdel(&line);
	hist->size += 1;
	while (get_next_line(hist->fd, &line, FLAG_OFF) == 1)
	{
		tmp = line;
		hist = history_add_new_elem(hist, tmp);
		free(line);
		hist->size += 1;
	}
	get_next_line(hist->fd, &line, FLAG_ON);
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
	history_add_new_elem(h, NULL);
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
	history->fd = open(PTH_21SH_HIST, O_CREAT | O_RDWR | O_APPEND,
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
