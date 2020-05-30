/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 00:37:51 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/25 00:51:39 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_write(int fildes, const void *buf, size_t nbyte)
{
	ssize_t	ret_write;

	ret_write = write(fildes, buf, nbyte);
	if (ret_write < 0)
	{
		ft_printf("%v%swrite error%s\n", STDERR_FILENO, FT_COLOR_RED,
				FT_COLOR_DFLT);
	}
	return (ret_write);
}
