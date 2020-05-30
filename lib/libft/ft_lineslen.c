/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lineslen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:16:53 by ksharlen          #+#    #+#             */
/*   Updated: 2019/09/24 20:21:33 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lineslen(char *const lines[])
{
	size_t	ret_len;

	ret_len = 0;
	if (lines && *lines)
	{
		while (*lines)
		{
			++ret_len;
			++lines;
		}
	}
	return (ret_len);
}
