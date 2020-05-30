/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 23:14:45 by ksharlen          #+#    #+#             */
/*   Updated: 2019/11/11 18:19:40 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			getresult(const char *str, const int base, int num)
{
	char		*base_str_d;
	char		*base_str_u;
	int			digit;
	const char	*p_str;
	int			result;

	result = 0;
	base_str_d = (char[]){"0123456789abcdef"};
	base_str_u = (char[]){"0123456789ABCDEF"};
	p_str = str;
	while (num >= 0)
	{
		if ((p_str = ft_memchr(base_str_d, *str, base_str_d[base - 1])))
			digit = p_str - base_str_d;
		else
		{
			p_str = ft_memchr(base_str_u, *str, base_str_u[base - 1]);
			digit = p_str - base_str_u;
		}
		result += ft_pow(base, num--) * digit;
		++str;
	}
	return (result);
}

static int			getint(const char *str, int base)
{
	char		*base_str_d;
	char		*base_str_u;
	const char	*p_str;
	int			result;
	int			num;

	result = 0;
	num = -1;
	base_str_d = (char[]){"0123456789abcdef"};
	base_str_u = (char[]){"0123456789ABCDEF"};
	p_str = str;
	while (p_str && *p_str && (ft_memchr(base_str_d, *p_str,
		base) || ft_memchr(base_str_u,
			*p_str, base)))
	{
		p_str++;
		num++;
	}
	result = getresult(str, base, num);
	return (result);
}

static const char	*getsign(const char *str, int *sign)
{
	*sign = 1;
	if (*str == '-' || *str == '+')
	{
		*sign = (*str == '+') ? 1 : -1;
		return (++str);
	}
	return (str);
}

static const char	*skip_mask(const char *str, const int base)
{
	if (str && *str)
	{
		if (base == OCT && (*str == 'o' || *str == 'O'))
			++str;
		else if (base == HEX && (!ft_memcmp(str, "0x", 2) ||
			!ft_memcmp(str, "0X", 2)))
			str += 2;
		else if (base == BIN && (*str == 'b' || *str == 'B'))
			str++;
	}
	return (str);
}

int					ft_atoi_base(const char *str, const int base)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	if (str && *str && base > 0)
	{
		str = ft_skiptabs(str);
		if (*str)
		{
			if ((str = getsign(str, &sign)) && *str)
			{
				str = skip_mask(str, base);
				if (str && *str)
					result = getint(str, base);
			}
		}
	}
	return (result * sign);
}
