/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fill_point_args.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:01:29 by mdelphia          #+#    #+#             */
/*   Updated: 2020/03/11 19:01:32 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		parser_fill_point_args(t_pars_list *list)
{
	while (list)
	{
		if (list->pars_args)
			list->name_func = list->pars_args[0];
		list = list->next;
	}
}
