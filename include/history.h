/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 17:27:05 by dsandshr          #+#    #+#             */
/*   Updated: 2020/02/08 16:28:51 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include "libft.h"

typedef struct				s_history_list
{
	char					*comand;
	struct s_history_list	*next;
	struct s_history_list	*prev;
	size_t					location;
}							t_history_list;


typedef struct				s_history
{
	t_history_list			*h_list;
	t_history_list			*beg;
	t_history_list			*end;
	size_t					size;
	int						fd;
}							t_history;

t_history			*history_init(void);
char				*get_bottom_cmd(t_history *hist);
char				*get_top_cmd(t_history *hist);
t_history			*add_new_elem(t_history *hist, char *str);
t_history			*fill_history(t_history *hist, char *str);
void				history_del(t_history *hist);

#endif
