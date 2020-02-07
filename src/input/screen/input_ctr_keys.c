/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_ctr_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 00:39:14 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/08 00:45:55 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

static void	input_del_line(struct s_input *inp)
{
	if (inp->gap.len_string)
	{
		gap_clean_buf(&inp->gap);
		ft_strdel(&inp->str_for_parse);
		inp->cr = inp->save_refresh_pos;
		set_cursor_pos(inp->cr.x, inp->cr.y);
		clear_pos_cr_to_the_end();
	}
}

void	input_ctr_keys(struct s_input *inp)
{
	if (inp->key == CTR_KEY('p'))
		input_paste_to_buf(inp);
	else if (inp->key == CTR_KEY('u'))
		input_cut_from_buf(inp);
	else if (inp->key == CTR_KEY('y'))
		input_copy_from_buf(inp);
	else if (inp->key == CTR_KEY('q'))
		input_del_line(inp);
	else if (inp->key == CTR_KEY('t'))
		input_ctr_t(inp);
}
