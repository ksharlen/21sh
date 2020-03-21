/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_find_ampersand.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 21:25:16 by mdelphia          #+#    #+#             */
/*   Updated: 2020/03/21 21:25:16 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			parser_get_nbr_ampersand(t_pars_list *list)
{
	while (list)
	{
		if (list->nbr_ampersant)
			return (++list->nbr_ampersant);
		list = list->prev;
	}
	return (1);
}

char		*parser_find_ampersand(char *str, t_pars_list *list)
{
	if (*str != '&' ||
		(*str == '&' && (*(str + 1) == '>' || *(str + 1) == '<')))
		return (str);
	list->f_delimiter |= F_AMPERSANT;
	list->nbr_ampersant = parser_get_nbr_ampersand(list);
	*str = -1;
	return (++str);
}
