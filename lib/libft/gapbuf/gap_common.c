/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_common.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:23:23 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 21:33:04 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

void	get_new_gapbuf(t_gapbuf *buf, size_t len_get_new_gapbuf)
{
	if (!len_get_new_gapbuf)
		len_get_new_gapbuf = buf->main_size_gap_buf;
	if (len_get_new_gapbuf >= (buf->size_buf - buf->len_string))
		len_get_new_gapbuf = (buf->size_buf - buf->len_string);
	buf->gap_start = buf->len_string + 1;
	buf->gap_end = buf->gap_start + len_get_new_gapbuf - 1;
	buf->size_gap_buf = len_get_new_gapbuf;
}

int		get_sym_ind_at_buf(t_gapbuf *buf, size_t pos_sym)
{
	size_t	ind;
	size_t	sym;

	if (pos_sym <= buf->len_string)
	{
		ind = 0;
		sym = 0;
		while (ind < (buf->len_string + buf->size_gap_buf) && sym != pos_sym)
		{
			if (buf->buf[ind++] != '\0')
				++sym;
		}
		return (ind);
	}
	return (-1);
}

void	delete_gapbuf(t_gapbuf *buf)
{
	if (buf->size_gap_buf && buf->gap_start < buf->len_string)
	{
		while (buf->gap_start != (buf->size_gap_buf + buf->len_string + 1))
		{
			buf->buf[buf->gap_start++] = buf->buf[++buf->gap_end];
			buf->buf[buf->gap_end] = '\0';
		}
	}
	buf->gap_start = 0;
	buf->gap_end = 0;
	buf->size_gap_buf = 0;
}

void	die_gap(const char *s)
{
	write(STDERR_FILENO, s, ft_strlen(s));
	exit(EXIT_FAILURE);
}
