/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:12:12 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/08 16:27:33 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtabdup(const char *str)
{
	size_t	len_str;
	char	*new_str;

	new_str = NULL;
	if (str && *str)
	{
		len_str = ft_strtablen(str);
		new_str = ft_strnew(len_str);
		ft_memcpy(new_str, str, len_str);
	}
	return (new_str);
}
