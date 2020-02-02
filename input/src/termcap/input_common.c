/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_common.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 21:06:48 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/02 23:35:32 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_termcap.h"

struct s_win	get_win_size(void)
{
	struct s_win	wn;

	wn.cols = input_tgetnum(CO);
	wn.rows = input_tgetnum(LI);
	return (wn);
}
