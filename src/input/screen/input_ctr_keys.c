/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_ctr_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 00:39:14 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/06 00:46:47 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

void	ctr_keys(struct s_input *inp)
{
	if (inp->key == CTR_KEY('p'))
		input_paste_to_buf(inp);
	else if (inp->key == CTR_KEY('u'))
		input_cut_from_buf(inp);
	else if (inp->key == CTR_KEY('y'))
		input_copy_from_buf(inp);
}
