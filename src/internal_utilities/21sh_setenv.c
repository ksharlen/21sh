/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh21_setenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:09:07 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/13 22:52:39 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_utilities.h"

size_t			find_var_env(const char *name)
{
	int			i;
	size_t		len_name;

	i = 0;
	if (g_sh_environ && *g_sh_environ)
		while (g_sh_environ[i] && g_sh_environ[i][0])
		{
			if ((!ft_memcmp(g_sh_environ[i], name, len_name = ft_strnlen(name, '='))) && g_sh_environ[i][len_name] == '=')
				return (i);
			++i;
		}
	return (-1);
}

static int		new_val_name(int index, const char *value, size_t len_name)
{
	char	*buf;

	buf = (char[MAX_SIZE_PATH]){0};
	ft_strncpy(buf, g_sh_environ[index], len_name);
	buf[len_name] = '=';
	if (index != -1)
	{
		ft_strdel(&g_sh_environ[index]);
		g_sh_environ[index] = ft_strjoin(buf, value);
		if (g_sh_environ[index])
			return (SUCCESS);
	}
	return (FAILURE);
}

static int		push_new_environ(char **new_environ,
	size_t size_new_env, const char *name, const char *value)
{
	size_t		i;
	char		*buf;

	i = 0;
	buf = (char[MAX_SIZE_PATH]){0};
	ft_strcpy(buf, name);
	ft_strcat(buf, "=");
	while (i < size_new_env - 1)
	{
		new_environ[i] = ft_strdup(g_sh_environ[i]);
		if (!new_environ[i])
			return (FAILURE);
		++i;
	}
	new_environ[i] = ft_strjoin(buf, value);
	if (!new_environ)
		return (FAILURE);
	new_environ[size_new_env] = NULL;
	return (SUCCESS);
}

static int		create_new_name_val(const char *name, const char *value)
{
	size_t			len_env;
	char			**new_environ;

	len_env = ft_lineslen(g_sh_environ) + 1;
	new_environ = (char **)ft_memalloc(sizeof(char *) * (len_env + 1));
	if (!new_environ)
		return (FAILURE);
	push_new_environ(new_environ, len_env, name, value);
	ft_strdel_split(g_sh_environ);
	free(g_sh_environ);
	g_sh_environ = new_environ;
	new_environ = NULL;
	return (SUCCESS);
}

int				sh21_setenv(const char *name,
	const char *value, const int replace)
{
	int				index;
	enum e_err		err;

	err = FAILURE;
	if (name && value && *name)
	{
		index = find_var_env(name);
		if (index != -1)
		{
			if (replace)
				err = new_val_name(index, value, ft_strnlen(name, '='));
		}
		else
			err = create_new_name_val(name, value);
	}
	return (err);
}
