/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_ctr_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 00:39:14 by ksharlen          #+#    #+#             */
/*   Updated: 2020/03/08 18:30:11 by ksharlen         ###   ########.fr       */
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

void		input_ctr_keys(struct s_input *inp)
{
	if (inp->key == ('p' & 0x1f))
		input_paste_to_buf(inp);
	else if (inp->key == ('u' & 0x1f))
		input_cut_from_buf(inp);
	else if (inp->key == ('y' & 0x1f))
		input_copy_from_buf(inp);
	else if (inp->key == ('q' & 0x1f))
		input_del_line(inp);
}
