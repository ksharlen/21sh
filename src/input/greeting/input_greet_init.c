/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_greet_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:06:58 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/08 22:13:02 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_greeting.h"

static void	get_curr_dir(char *curr_dir)
{
	char	*pwd;
	char	*p_dir;

	if (curr_dir)
	{
		FT_CLEAN_UP(pwd, SIZE_DIR);
		getcwd(pwd, SIZE_DIR);
		p_dir = ft_strrchr(pwd, '/');
		++p_dir;
		if (*p_dir)
			COPY(curr_dir, p_dir);
		else
			COPY(curr_dir, "/");
	}
}

static void	get_user(char *curr_user, const char *user)
{
	if (curr_user)
		COPY(curr_user, user);
}

static void	get_time(char *curr_time)
{
	time_t	int_time;
	char	*str_time;

	if (curr_time)
	{
		str_time = NULL;
		CHK_SYS_ERR_EXT(int_time = time(NULL), E_TIME, P_N);
		CHK_NULL_PTR(str_time = ctime(&int_time), E_CTIME, P_N);
		ft_strncpy(curr_time, str_time + SKIP_DATE, SIZE_TIME);
	}
}

static void	init_greet(t_greet *greet)
{
	ft_bzero(greet->time, SIZE_TIME + 1);
	ft_bzero(greet->user, SIZE_NAME + 1);
	ft_bzero(greet->curr_d, SIZE_DIR + 1);
}

void	input_greeting_init(t_greet *greet, const struct s_user_info *u_info)
{
	init_greet(greet);
	get_time(greet->time);
	get_user(greet->user, u_info->user);
	get_curr_dir(greet->curr_d);
}
