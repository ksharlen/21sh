/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_copy_paste_cut.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 00:41:35 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/06 01:02:25 by ksharlen         ###   ########.fr       */
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

	if (inp->buf)
	{
		gap_paste_str(&inp->gap, inp->buf);
		len_buf_paste = ft_strlen(inp->buf);
		get_coor_word(inp, len_buf_paste);
		inp->key = 0;
		refresh_screen(inp);
	}
}
