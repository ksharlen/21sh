/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_additional_modes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:03:00 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/06 20:42:44 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

void	input_additional_modes(t_exec_lst *execlist, struct s_input *inp)
{
	if (inp->str_for_parse)
	{
		input_quote_mode(execlist, inp);
	}
}
