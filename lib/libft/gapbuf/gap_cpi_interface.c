/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_cpi_interface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:49:52 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 21:33:36 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

char			*gap_copy_str(t_gapbuf *buf)
{
	return (gap_get_buf(buf));
}

char			*gap_cut_str(t_gapbuf *buf)
{
	char	*str;

	str = gap_copy_str(buf);
	ft_memset(buf->buf, '\0', buf->size_buf);
	buf->size_gap_buf = buf->main_size_gap_buf;
	buf->gap_start = 0;
	buf->gap_end = buf->size_gap_buf - 1;
	buf->slide = 0;
	buf->len_string = 0;
	return (str);
}

void			gap_put_str(t_gapbuf *buf, const char *str)
{
	size_t	i;
	size_t	len_str;

	i = 0;
	len_str = ft_strlen(str);
	while (i < len_str)
		gap_putchar_in_buf(buf, str[i++]);
}

static void		put_str_in_gap(t_gapbuf *buf, const char *str)
{
	size_t	len_str;

	len_str = ft_strlen(str);
	if (len_str > buf->size_gap_buf)
	{
		delete_gapbuf(buf);
		get_new_gapbuf(buf, len_str);
	}
	gap_put_str(buf, str);
}

void			gap_paste_str(t_gapbuf *buf, const char *str)
{
	if (str && *str)
	{
		if (!buf->len_string || buf->slide == buf->len_string)
			gap_put_str(buf, str);
		else
			put_str_in_gap(buf, str);
	}
}
