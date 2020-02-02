/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 20:41:03 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/02 22:35:02 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_init.h"

void	input_init(struct s_input *inp)
{
	if (inp)
	{
		gap_init(&inp->gap, INP_SIZE_BUF, INP_SIZE_GAP);
	}
	//greeting
	//lines
	//etc
}
