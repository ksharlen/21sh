/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_greet_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:06:58 by ksharlen          #+#    #+#             */
/*   Updated: 2020/04/30 02:12:20 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_greeting.h"

static void	get_curr_dir(t_exec_lst *execlist, char *curr_dir)
{
	char	*pwd;
	char	*p_dir;

	if (curr_dir)
	{
		pwd = (char[SIZE_DIR]){0};
		getcwd(pwd, SIZE_DIR);
		if (!ft_strcmp(pwd, sh21_getenv(execlist, "HOME")))
		{
			ft_strcpy(curr_dir, "~");
		}
		else
		{
			p_dir = ft_strrchr(pwd, '/');
			++p_dir;
			if (*p_dir)
				ft_strcpy(curr_dir, p_dir);
			else
				ft_strcpy(curr_dir, "/");
		}
	}
}

static void	get_user(char *curr_user, const char *user)
{
	if (curr_user)
		ft_strcpy(curr_user, user);
}

static void	get_time(char *curr_time)
{
	time_t	int_time;
	char	*str_time;

	if (curr_time)
	{
		str_time = NULL;
		int_time = time(NULL);
		ft_chk_sys_error(int_time, E_TIME);
		str_time = ctime(&int_time);
		ft_chk_null_ptr(str_time, E_CTIME);
		ft_strncpy(curr_time, str_time + SKIP_DATE, SIZE_TIME);
	}
}

static void	init_greet(t_greet *greet)
{
	ft_bzero(greet->time, SIZE_TIME + 1);
	ft_bzero(greet->user, SIZE_NAME + 1);
	ft_bzero(greet->curr_d, SIZE_DIR + 1);
}

void		input_greeting_init(t_exec_lst *execlist, t_greet *greet,
				const struct s_user_info *u_info)
{
	init_greet(greet);
	get_time(greet->time);
	get_user(greet->user, u_info->user);
	get_curr_dir(execlist, greet->curr_d);
}
