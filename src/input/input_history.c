/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:21:22 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/08 21:12:58 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

void	input_history(struct s_input *inp)
{
	char	*str_hist;

	if (inp->key == KEY_UP_ARROW)
	{
		str_hist = history_get_top_cmd(inp->hist);
		if (str_hist)
		{
// if (!ft_strcmp(str_hist, "pwd"))
// {
// 	printf("YES!!!\n");
// 	exit(EXIT_FAILURE);
// }
			inp->cr = inp->save_refresh_pos;
			clear_pos_cr_to_the_end();
			gap_clean_buf(&inp->gap);
			gap_put_str(&inp->gap, str_hist);
			inp->gap.slide = inp->gap.len_string;
		}
	}
	else if (inp->key == KEY_DOWN_ARROW)
	{
		str_hist = history_get_bottom_cmd(inp->hist);
		if (str_hist)
		{
			inp->cr = inp->save_refresh_pos;
			clear_pos_cr_to_the_end();
			gap_clean_buf(&inp->gap);
			gap_put_str(&inp->gap, str_hist);
			inp->gap.slide = inp->gap.len_string;
		}
	}
	get_coor_word(inp, inp->len_greet + inp->gap.len_string);
	refresh_screen(inp);
}
