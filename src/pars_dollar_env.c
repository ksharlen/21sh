/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_dollar_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 03:51:19 by student           #+#    #+#             */
/*   Updated: 2020/04/10 21:54:18 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "parser.h"

static char		*search_first_space(char *ptr)
{
	while (*ptr && !ft_isspace(*ptr))
		ptr++;
	return (ptr);
}

static char		*dollar_realloc(char **str, char *ptr)
{
	int		len;
	char	*new_str;
	char	*end_env;
	char	*env_val;
	char	*env_name;

	end_env = search_first_space(ptr) - 1;
	env_name = ft_memalloc(end_env - ptr + 1);
	ft_strncpy(env_name, ptr + 1, end_env - ptr);
	env_val = sh21_getenv(env_name);
	len = ft_strlen(env_val) + (end_env - ptr);
	new_str = ft_memalloc(ft_strlen(*str) + len + 1);
	ft_strncpy(new_str, *str, ptr - *str);
	ft_strcat(new_str, env_val);
	ft_strcat(new_str, end_env);
	free(env_name);
	free(env_val);
	free(*str);
	*str = new_str;
	new_str = NULL;
	return (*str);
}

static int		search_dollar (char *str)
{
	while (*str)
	{
		if (*str == '$')
			return (1);
		str++;
	}
	return (0);
}

char	*pars_insert_env_value(char **str)
{
    char	*ptr;

	ptr = *str;
	while (search_dollar(*str) && *ptr)
	{
		if (parse_is_quote(*ptr))
			ptr = parse_next_quote(ptr);
		if (*ptr == '$')
		{
			*str = dollar_realloc(str, ptr);
			ptr = *str;
		}
		else
			ptr++;
	}
	return (*str);
}

void	insert_dollar_args(t_pars_list *list)
{
	char	**ptr;
	int		i;
	
	i = 0;
	ptr = list->pars_args;
	while (*ptr)
	{
		list->pars_args[i] = pars_insert_env_value(ptr);
		ptr++;
		i++;
	}
	list->name_func = *(list->pars_args); // ne menyaetsya 0 argument, naprimer $> $SHLVL
}