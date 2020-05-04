/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_insert_tilda.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 21:39:19 by tjonella          #+#    #+#             */
/*   Updated: 2020/04/10 22:15:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char		*tilda_realloc(t_exec_lst *execlist, char **str, char *ptr)
{
	int		len;
	char	*new_str;

	len = ft_strlen(sh21_getenv(execlist, "HOME"));
	new_str = ft_memalloc(ft_strlen(*str) + len + 1);
	ft_strncpy(new_str, *str, ptr - *str);
	ft_strcat(new_str, sh21_getenv(execlist, "HOME"));
	ft_strcat(new_str, ptr + 1);
	free(*str);
	*str = new_str;
	new_str = NULL;
	return (*str);
}

static int		search_tilda(char *str)
{
	while (*str)
	{
		if (*str == '~')
			return (1);
		str++;
	}
	return (0);
}

char			*pars_insert_tilda(t_exec_lst *execlist, char **str)
{
	char	*ptr;

	ptr = *str;
	while (search_tilda(*str) && *ptr)
	{
		if (parse_is_quote(*ptr))
			ptr = parse_next_quote(ptr);
		if (*ptr == '~')
		{
			*str = tilda_realloc(execlist, str, ptr);
			ptr = *str;
		}
		else
			ptr++;
	}
	return (*str);
}
