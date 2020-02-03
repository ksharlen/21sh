/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_common_screen.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 01:28:50 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/04 01:45:27 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

int		check_line_footnote_up(struct s_input *inp)
{
	int	is_footnote;

	is_footnote = FALSE;
	if (inp->cr.x == inp->win.cols - 3)
	{
		++inp->cr.y;
		inp->cr.x = 0;
		is_footnote = TRUE;
	}
	return (is_footnote);
}

int		check_line_footnote_down(struct s_input *inp)
{
	int is_footnote;

	is_footnote = FALSE;
	if (!inp->cr.x)
	{
		--inp->cr.y;
		inp->cr.x = 0;
		is_footnote = TRUE;
	}
	return (is_footnote);
}
