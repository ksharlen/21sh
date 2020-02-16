/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh21_pwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 22:59:27 by rloraine          #+#    #+#             */
/*   Updated: 2019/10/05 15:41:50 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_utilities.h"

int		sh21_pwd(int argc, char *argv[], char *env[])
{
	char *pwd;

	(void)(argv);
	(void)(env);
	if (argc > 1)
		ft_printf("pwd: %s\n", S_TOO_MANY);
	else
	{
		pwd = (char[MAX_SIZE_PATH + 1]){0};
		if (getcwd(pwd, MAX_SIZE_PATH))
		{
			ft_printf("%s\n", pwd);
			return (0);
		}
	}
	return (-1);
}
