/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_find_history.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 23:18:39 by dsandshr          #+#    #+#             */
/*   Updated: 2020/02/08 17:04:28 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

char	*find_history(t_history *hist, char *str)
{
	P_UNUSED(str);

	t_history_list *beg;
	t_history_list *end;

	beg = hist->beg;
	end = hist->end;
	return (NULL);
}
