/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:55:32 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/06 20:30:54 by ksharlen         ###   ########.fr       */
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
		str = input_begin(&init.inp);//if (str)
		if ((!str && init.inp.key == CTR_KEY('d')) || (str && !ft_strcmp(str, "exit")))
			break ;
		// ft_printf("str: %s\n", str);
		ft_strdel(&str);
	}
	ft_strdel(&init.inp.gap.buf);
	// entry_not_canon(&cp);
	// entry_canon(&cp);
	// ft_printf("hello owrld\n");
	return (0);
}