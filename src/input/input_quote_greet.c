/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_quote_greet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:31:15 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/06 17:34:22 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_greeting.h"

int		input_quote_greet(const struct s_user_info *u_info)
{
	P_UNUSED(u_info);
	ft_putstr_fd(QUOTE_GREET_STR, STDOUT_FILENO);
	return (ft_strlen(QUOTE_GREET_STR));
}
