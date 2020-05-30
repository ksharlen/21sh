/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iu_parser_setenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 22:16:09 by ksharlen          #+#    #+#             */
/*   Updated: 2020/05/30 22:36:42 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_utilities.h"

static void	change_equally_to_zero(char *str)
{
	char *equally;

	if (str && *str && (equally = ft_strchr(str, '=')))
		*equally = '\0';
}

char		*get_value_from_name(char *name)
{
	char *value;

	value = NULL;
	if (name && *name)
	{
		if ((value = ft_strchr(name, '=')) != NULL)
		{
			++value;
			if (*value)
			{
				change_equally_to_zero(name);
				return (value);
			}
		}
	}
	return (NULL);
}
