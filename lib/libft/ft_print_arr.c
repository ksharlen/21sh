/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 22:13:41 by ksharlen          #+#    #+#             */
/*   Updated: 2019/11/11 23:23:55 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_char(void *arr, size_t size, BYTE type)
{
	size_t	i;

	i = 0;
	if (type == CHAR)
		while (i < size)
		{
			ft_printf("arr[%zd] = %c\n", i, ((char *)arr)[i]);
			++i;
		}
	else if (type == UCHAR)
		while (i < size)
		{
			ft_printf("arr[%zd] = %hhd\n", i, ((unsigned char *)arr)[i]);
			++i;
		}
}

static void	print_short(void *arr, size_t size, BYTE type)
{
	size_t	i;

	i = 0;
	size /= sizeof(short);
	if (type == SHORT)
		while (i < size)
		{
			ft_printf("arr[%zd] = %hd\n", i, ((short *)arr)[i]);
			++i;
		}
	else if (type == USHORT)
		while (i < size)
		{
			ft_printf("arr[%zd] = %hu\n", i, ((unsigned short *)arr)[i]);
			++i;
		}
}

static void	print_int(void *arr, size_t size, BYTE type)
{
	size_t	i;

	i = 0;
	size /= sizeof(int);
	if (type == INT)
		while (i < size)
		{
			ft_printf("arr[%zd] = %d\n", i, ((int *)arr)[i]);
			++i;
		}
	else if (type == UINT)
		while (i < size)
		{
			ft_printf("arr[%zd] = %u\n", i, ((unsigned *)arr)[i]);
			++i;
		}
}

static void	print_long(void *arr, size_t size, BYTE type)
{
	size_t	i;

	i = 0;
	size /= sizeof(long);
	if (type == LONG)
		while (i < size)
		{
			ft_printf("arr[%zd] = %ld\n", i, ((long *)arr)[i]);
			++i;
		}
	else if (type == ULONG)
		while (i < size)
		{
			ft_printf("arr[%zd] = %lu\n", i, ((unsigned long *)arr)[i]);
			++i;
		}
}

void		ft_print_arr(void *arr, size_t size, BYTE type)
{
	if (type == CHAR || type == UCHAR)
		print_char(arr, size, type);
	else if (type == SHORT || type == USHORT)
		print_short(arr, size, type);
	else if (type == INT || type == UINT)
		print_int(arr, size, type);
	else if (type == ULONG || type == LONG)
		print_long(arr, size, type);
	else if (type == STRING)
		ft_printf("%s", (char *)arr);
}
