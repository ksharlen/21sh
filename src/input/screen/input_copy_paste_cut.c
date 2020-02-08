/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_copy_paste_cut.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 00:41:35 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/08 22:53:26 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

void	input_copy_from_buf(struct s_input *inp)
{
	if (inp->gap.len_string)
		inp->buf = gap_copy_str(&inp->gap);
}

void	input_cut_from_buf(struct s_input *inp)
{
	if (inp->gap.len_string)
	{
		if (inp->buf)
			ft_strdel(&inp->buf);
		inp->buf = gap_cut_str(&inp->gap);
		inp->cr.x = inp->save_refresh_pos.x;
		inp->cr.y = inp->save_refresh_pos.y;
		set_cursor_pos(inp->cr.x, inp->cr.y);
		clear_pos_cr_to_the_end();
	}
}

void	input_paste_to_buf(struct s_input *inp)
{
	ssize_t	len_buf_paste;
	ssize_t	pos;

	if (inp->buf)
	{
		len_buf_paste = ft_strlen(inp->buf);
		pos = inp->gap.slide + len_buf_paste + inp->greet.len;
		get_coor_word(inp, pos);
		inp->key = 0;
		gap_paste_str(&inp->gap, inp->buf);
		refresh_screen(inp);
	}
}
