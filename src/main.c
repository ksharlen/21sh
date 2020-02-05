/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:55:32 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/05 19:46:05 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"
// #include "21sh_init.h"
// #include "libft.h"

int		main(void)
{
	t_init			init;
	char			*str;

	sh21_init(&init);
	// get_struct_for_input(&inp, &init);
	while (1)
	{
		str = input_begin(&init.inp);
		if (!str || !ft_strcmp(str, "exit"))
			break ;
	}
	// entry_not_canon(&cp);
	// entry_canon(&cp);
	// ft_printf("hello owrld\n");
	return (0);
}