/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 23:28:38 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/02 23:32:00 by ksharlen         ###   ########.fr       */
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
