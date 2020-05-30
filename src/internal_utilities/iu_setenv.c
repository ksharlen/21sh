/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iu_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:37:33 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 18:42:34 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_utilities.h"

size_t			find_var_env(t_exec_lst *execlist, const char *name)
{
	int			i;
	size_t		len_name;

	i = 0;
	if (execlist->sh_environ && *execlist->sh_environ)
		while (execlist->sh_environ[i] && execlist->sh_environ[i][0])
		{
			if ((!ft_memcmp(execlist->sh_environ[i], name,
				len_name = ft_strnlen(name, '='))) &&
					execlist->sh_environ[i][len_name] == '=')
				return (i);
			++i;
		}
	return (-1);
}

static int		new_val_name(t_exec_lst *execlist, int index, const char *value,
					size_t len_name)
{
	char	*buf;

	buf = (char[MAX_SIZE_PATH]){0};
	ft_strncpy(buf, execlist->sh_environ[index], len_name);
	buf[len_name] = '=';
	if (index != -1)
	{
		ft_strdel(&execlist->sh_environ[index]);
		execlist->sh_environ[index] = ft_strjoin(buf, value);
		if (execlist->sh_environ[index])
			return (SUCCESS);
	}
	return (FAILURE);
}

static int		push_new_environ(t_exec_lst *execlist, char **new_environ,
					const char *name, const char *value)
{
	size_t		i;
	char		*buf;
	size_t		size_new_env;

	i = 0;
	size_new_env = ft_lineslen(execlist->sh_environ) + 1;
	buf = (char[MAX_SIZE_PATH]){0};
	ft_strcpy(buf, name);
	ft_strcat(buf, "=");
	while (i < size_new_env - 1)
	{
		new_environ[i] = ft_strdup(execlist->sh_environ[i]);
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

static int		create_new_name_val(t_exec_lst *execlist, const char *name,
					const char *value)
{
	size_t			len_env;
	char			**new_environ;

	len_env = ft_lineslen(execlist->sh_environ) + 1;
	new_environ = (char **)ft_memalloc(sizeof(char *) * (len_env + 1));
	if (!new_environ)
		return (FAILURE);
	push_new_environ(execlist, new_environ, name, value);
	ft_strdel_split(execlist->sh_environ);
	free(execlist->sh_environ);
	execlist->sh_environ = new_environ;
	new_environ = NULL;
	return (SUCCESS);
}

int				sh21_setenv(t_exec_lst *execlist, const char *name,
					const char *value, const int replace)
{
	int				index;
	enum e_err		err;

	err = FAILURE;
	if (name && value && *name)
	{
		index = find_var_env(execlist, name);
		if (index != -1)
		{
			if (replace)
				err = new_val_name(execlist, index, value,
						ft_strnlen(name, '='));
		}
		else
			err = create_new_name_val(execlist, name, value);
	}
	return (err);
}
