/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:18:19 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 21:42:23 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gap_buf.h"

void	gap_print_buf(t_gapbuf *buf)
{
	size_t	size;

	if (buf->buf && buf->len_string)
	{
		if (buf->gap_start < buf->len_string + 1)
			size = buf->size_gap_buf + buf->len_string;
		else
			size = buf->len_string;
		write(STDOUT_FILENO, buf->buf, size);
	}
}
