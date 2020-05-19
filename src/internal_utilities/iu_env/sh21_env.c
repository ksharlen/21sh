/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh21_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 15:16:22 by ksharlen          #+#    #+#             */
/*   Updated: 2020/03/29 16:43:37 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_utilities.h"

static void		env_init(t_env *env)
{
	env->cmd = NULL;
	env->opt = 0;
}

static int		get_opt(int argc, char **opts, t_env *env)
{
	int				ch;
	enum e_err		err;

	ch = 0;
	err = SUCCESS;
	optarg = NULL;
	optopt = 0;
	optind = 1;
	while ((ch = getopt(argc, opts, ENV_OPT)) != -1)
	{
		if (ch == 'P')
			env->opt |= F_P;
		else if (ch == 'S')
			env->opt |= F_S;
		else if (ch == 'i')
			env->opt |= F_I;
		else if (ch == 'u')
			env->opt |= F_U;
		else if (ch == '?')
		{
			ft_printf("%v%s\n	   %s\n", STDERR_FILENO, USG, USG_1);
			return (FAILURE);
		}
	}
	return (err);
}

int				sh21_env(t_exec_lst *execlist, int argc,
					char **argv, char **env)
{
	t_env			m_env;
	enum e_err		err;

	(void)env;
	err = FAILURE;
	env_init(&m_env);
	err = get_opt(argc, argv, &m_env);
	if (err == SUCCESS)
	{
		++argv;
		work_opt(execlist, argv, &m_env);
	}
	return (err);
}
