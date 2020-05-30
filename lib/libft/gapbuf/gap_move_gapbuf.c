/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_move_gapbuf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:23:37 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 21:38:00 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

static void		gap_move_left(t_gapbuf *buf, size_t ind)
{
	if (buf->len_string)
	{
		if ((buf->gap_end + 1) != ind)
		{
			while (buf->gap_start != ind)
			{
				buf->buf[buf->gap_end] = buf->buf[buf->gap_start - 1];
				buf->buf[buf->gap_start - 1] = '\0';
				--buf->gap_start;
				--buf->gap_end;
			}
		}
	}
}

static void		gap_move_right(t_gapbuf *buf, size_t ind)
{
	if (buf->len_string)
	{
		if (buf->gap_end + 1 != ind)
		{
			while (buf->gap_end != (ind - 1))
			{
				buf->buf[buf->gap_start] = buf->buf[buf->gap_end + 1];
				buf->buf[buf->gap_end + 1] = '\0';
				++buf->gap_start;
				++buf->gap_end;
			}
		}
	}
}

void			gap_move(t_gapbuf *buf, size_t ind)
{
	if (buf->buf)
	{
		if (buf->gap_start < ind)
			gap_move_right(buf, ind);
		else if (buf->gap_start > ind)
			gap_move_left(buf, ind);
	}
}

void			gapbuf_move_to_slide(t_gapbuf *buf)
{
	int ind;

	ind = get_sym_ind_at_buf(buf, buf->slide);
	if (!ind || (buf->gap_end != (size_t)ind - 1 &&
		buf->slide < buf->len_string))
		gap_move(buf, ind);
	if (ind == -1)
		die_gap("gapbuf_move_to_slide: SLIDE > buf->len_string");
}
