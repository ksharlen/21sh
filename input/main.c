/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:29:18 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/02 20:36:58 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_init.h"
#include "input_parse_key.h"

int		main(void)
{
	struct termios copy;
	int		key;

	entry_not_canon(&copy);

	do
	{
		key = input_getch();
		printf("key = %d\n", key);
	}
	while (key != KEY_NEW_LINE);

	entry_canon(&copy);
	return (0);
}
