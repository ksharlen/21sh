/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stroneof.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:38:10 by ksharlen          #+#    #+#             */
/*   Updated: 2019/09/30 13:14:13 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stroneof(const char *str, const char *find)
{
	const char *p_find;

	if (str && find && *find && *str)
	{
		p_find = find;
		while (*str)
		{
			if ((p_find = ft_strchr(find, *str)))
				return ((char *)str);
			++str;
		}
	}
	return (NULL);
}
