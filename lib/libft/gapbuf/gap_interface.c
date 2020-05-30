/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_interface.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 22:26:04 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 21:33:36 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

static void		fill_str_skip_gap(t_gapbuf *buf, char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < buf->len_string)
	{
		if (buf->buf[j])
		{
			str[i] = buf->buf[j];
			++i;
		}
		++j;
	}
}

char			*gap_get_buf(t_gapbuf *buf)
{
	char	*str;

	str = NULL;
	if (buf->len_string)
	{
		str = ft_strnew(buf->len_string);
		if (!str)
			die_gap("gap_get_buf: malloc_error");
		if (!buf->gap_start)
			ft_memcpy(str, &buf->buf[buf->gap_end + 1], buf->len_string);
		else if (buf->gap_start == (buf->len_string + 1))
			ft_memcpy(str, buf->buf, buf->len_string);
		else
			fill_str_skip_gap(buf, str);
		str[buf->len_string] = '\0';
	}
	return (str);
}

void			gap_slide_left(t_gapbuf *buf)
{
	if (buf->slide)
		--buf->slide;
}

void			gap_slide_right(t_gapbuf *buf)
{
	if (buf->slide < (buf->len_string))
		++buf->slide;
}

void			gap_init(t_gapbuf *buf, size_t size_buf,
	size_t size_gap)
{
	if (buf && size_buf && size_gap)
	{
		buf->buf = (char *)ft_memalloc(sizeof(char) *
			(size_buf + size_gap));
		if (!buf->buf)
			die_gap("gap_init: malloc_error");
		buf->size_buf = size_buf + size_gap;
		ft_bzero(buf->buf, sizeof(char) * buf->size_buf);
		buf->size_gap_buf = size_gap;
		buf->main_size_gap_buf = size_gap;
		buf->gap_start = 0;
		buf->gap_end = buf->size_gap_buf - 1;
		buf->slide = 0;
		buf->len_string = 0;
	}
	else
		die_gap("size_buf || size_gap = 0");
}
