/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_del_interface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 22:39:53 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 21:33:36 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

static void		del_sym(t_gapbuf *buf, size_t del)
{
	int	ind;

	if (del <= buf->len_string)
	{
		ind = get_sym_ind_at_buf(buf, del);
		gap_move(buf, ind);
		buf->buf[buf->gap_end++ + 1] = '\0';
		buf->len_string--;
		buf->size_gap_buf++;
	}
}

void			gap_del_sym_before_slide(t_gapbuf *buf)
{
	if (buf->len_string)
	{
		if (buf->slide == buf->len_string)
		{
			buf->buf[buf->len_string + buf->size_gap_buf - 1] = '\0';
			--buf->slide;
			--buf->len_string;
		}
		else if (buf->slide)
			del_sym(buf, --buf->slide);
	}
}

void			gap_del_sym_on_slide(t_gapbuf *buf)
{
	if (buf->len_string && buf->slide < buf->len_string)
		del_sym(buf, buf->slide);
}

void			gap_clean_buf(t_gapbuf *buf)
{
	if (buf->buf)
		ft_bzero(buf->buf, sizeof(char) * buf->size_buf);
	if (buf->len_string)
	{
		buf->size_gap_buf = buf->main_size_gap_buf;
		buf->gap_start = 0;
		buf->gap_end = buf->size_gap_buf - 1;
		buf->slide = 0;
		buf->len_string = 0;
	}
}

void			gap_swap_two_sym(t_gapbuf *buf)
{
	int		ind;

	if (buf->len_string > 1)
	{
		gap_move(buf, buf->size_gap_buf + buf->len_string + 1);
		ind = get_sym_ind_at_buf(buf, buf->slide);
		if (!buf->slide)
		{
			ft_swap_sym(&buf->buf[ind], &buf->buf[ind + 1]);
			buf->slide += 2;
		}
		else if (buf->slide == buf->len_string)
			ft_swap_sym(&buf->buf[ind - 1], &buf->buf[ind - 2]);
		else
		{
			ft_swap_sym(&buf->buf[ind - 1], &buf->buf[ind]);
			++buf->slide;
		}
	}
}
