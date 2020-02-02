/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:29:18 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/02 20:11:53 by ksharlen         ###   ########.fr       */
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
		if (key >= 32 && key <= 126)
			write(STDOUT_FILENO, &key, sizeof(int));
		else if (key == KEY_RIGHT_ARROW)
			write(STDOUT_FILENO, "OK ", 3);
	}
	while (key != '\n');

	entry_canon(&copy);
	return (0);
}
