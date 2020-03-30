/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fill_way_for_path                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:42:49 by mdelphia          #+#    #+#             */
/*   Updated: 2020/03/15 20:27:25 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

static void	error_access_exec(t_pars_list *list)
{
	ft_putstr_fd("42sh: command not access: ", 2);
	ft_putstr_fd(list->name_func, 2);
	ft_putchar_fd('\n', 2);
	g_term_lst.exec_status = 126;
	exit(126);
}

static void	find_name_path(char *name_path, size_t *i, t_pars_list *list)
{
	size_t j;

	j = 0;
	while (name_path[*i])
	{
		if (name_path[*i] == ':')
		{
			(*i)++;
			break ;
		}
		list->name_run_func[j++] = name_path[(*i)++];
	}
	list->name_run_func[j] = '\0';
	ft_strcat(list->name_run_func, "/");
	ft_strcat(list->name_run_func, list->name_func);
}

int			exec_fill_way_for_path(char *str_path, t_pars_list *list)
{
	size_t i;

	i = 0;
	if (str_path)
		while (str_path[i])
		{
			find_name_path(str_path, &i, list);
			if (!access(list->name_run_func, 0))
			{
				if (!access(list->name_run_func, 1))
					return (1);
				else
					error_access_exec(list);
			}
		}
	return (0);
}
