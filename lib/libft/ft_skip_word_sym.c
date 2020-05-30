/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_word_sym.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:40:57 by ksharlen          #+#    #+#             */
/*   Updated: 2019/09/23 15:47:46 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_skip_word_sym(const char *str, char sym)
{
	if (str && *str)
	{
		while (str && ((*str > 32) || *str == sym))
			++str;
	}
	return ((char *)str);
}
