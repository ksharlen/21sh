/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_find_history.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 23:18:39 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 18:16:10 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

char	*find_history(t_history *hist, char *str)
{
	t_history_list *beg;
	t_history_list *end;

	(void)(str);
	(void)(end);
	(void)(beg);
	(void)(hist);
	beg = hist->beg;
	end = hist->end;
	return (NULL);
}
