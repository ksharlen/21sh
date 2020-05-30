/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:22:52 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 21:07:30 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *in, char *from)
{
	size_t	len_in;
	size_t	len_from;
	char	*dst;

	dst = NULL;
	if (in && from)
	{
		len_in = ft_strlen(in);
		len_from = ft_strlen(from);
		dst = ft_strnew(len_in + len_from);
		ft_chk_null_ptr(dst, E_MALLOC);
		ft_strcat(dst, in);
		ft_strcat(dst, from);
		ft_strdel(&in);
		ft_strdel(&from);
	}
	return (dst);
}
