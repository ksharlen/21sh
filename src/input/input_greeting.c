/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_greeting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 02:55:39 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/05 02:39:17 by ksharlen         ###   ########.fr       */
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
	CLEAN(greet->time, SIZE_TIME + 1);
	CLEAN(greet->user, SIZE_NAME + 1);
	CLEAN(greet->curr_d, SIZE_DIR + 1);
}

int			input_greeting(const struct s_user_info *u_info)
{
	t_greet	greet;
	int		ret_num_sym;

	ret_num_sym = 0;
	init_greet(&greet);
	get_time(greet.time);
	get_user(greet.user, u_info->user);
	get_curr_dir(greet.curr_d); //*NOT_DONE
	ft_putstr(COLOR_TIME);
	ret_num_sym += ft_printf("[%s]", greet.time);
	ft_putstr(COLOR_USER);
	ret_num_sym += ft_printf("%s", greet.user);
	ft_putstr(COLOR_DIR);
	ret_num_sym += ft_printf("(%s)", greet.curr_d);
	ft_putstr(COLOR_DFLT);
	ret_num_sym += ft_printf("$>");
	return (ret_num_sym);
}