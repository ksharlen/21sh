/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:00:09 by ksharlen          #+#    #+#             */
/*   Updated: 2019/09/23 01:36:27 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*p_str;

	p_str = NULL;
	while (*s && (*s != c))
		s++;
	if (*s == c)
		p_str = s;
	return ((char *)p_str);
}
