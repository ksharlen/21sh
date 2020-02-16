/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:24:10 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 19:56:47 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_init.h"

void	get_struct_for_input(struct s_input *inp, t_init *init)
{
	inp->u_info = init->u_inf;
}
