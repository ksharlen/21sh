/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iu_init_var_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:37:20 by ksharlen          #+#    #+#             */
/*   Updated: 2020/03/08 20:39:54 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_utilities.h"

char	**g_sh_environ;

void	print_env(void)
{
	char	**p_environ;
	char	*str;

	p_environ = g_sh_environ;
	while (p_environ && *p_environ)
	{
		str = (*p_environ);
		ft_printf("%s\n", str);
		++p_environ;
	}
}

void	clean_env(void)
{
	ft_strdel_split(g_sh_environ);
}

void	init_env(char **env)
{
	if (env && *env)
		g_sh_environ = ft_linedup(env);
	else
	{
		g_sh_environ = (char **)ft_memalloc(sizeof(char *) * 1);
		g_sh_environ[0] = NULL;
	}
}
