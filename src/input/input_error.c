/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 23:28:38 by ksharlen          #+#    #+#             */
/*   Updated: 2020/03/15 19:51:28 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_error.h"

void	input_str_error(const char *str)
{
	ft_printf("%verror: %s\n", STDERR_FILENO, *str ? str : "");
}

void	input_error_ext(const char *str)
{
	input_str_error(str);
	exit(EXIT_FAILURE);
}

void	print_sig_error(char *lvl, pid_t pid, char *err, char *file)
{
	ft_printf("%v[%s]    %d %s  %s\n", STDERR_FILENO, lvl, pid, err, file);
}
