/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:35:20 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 20:43:57 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_skip_word(const char *str, const char *entry_sym)
{
	while (*str && (ft_isalnum(*str) || (ft_strchr(entry_sym, *str))))
		str++;
	return ((char *)str);
}

static char	*ft_skip_not_words(const char *str, const char *entry_sym)
{
	if (str && *str && entry_sym)
		while (*str && (ft_isspace(*str) ||
			((!ft_strchr(entry_sym, *str)) && !ft_isalnum(*str))))
			++str;
	return ((char *)str);
}

size_t		ft_num_words(const char *str, const char *entry_sym)
{
	size_t	num_words;

	num_words = 0;
	if (str && *str && entry_sym)
	{
		while (*str)
		{
			str = (const char *)ft_skip_not_words(str, entry_sym);
			if (*str)
			{
				num_words++;
				str = (const char *)ft_skip_word(str, entry_sym);
			}
		}
	}
	return (num_words);
}
