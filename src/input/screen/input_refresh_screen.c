/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_refresh_screen.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 23:48:03 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/04 00:39:20 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

static void	clear_screen(struct s_cursor *sv_pos)
{
	visibility_cursor(NOT_VISIBLE_CUR);
	set_cursor_pos(sv_pos->x, sv_pos->y);
	clear_pos_cr_to_the_end();
}

void	refresh_screen(struct s_input *inp)
{
	char	*out_str;

	clear_screen(&inp->save_refresh_pos);
	if (IS_PRINT_KEY(inp->key))
	{
		gap_putchar_in_buf(&inp->gap, inp->key);
		++inp->cr.x;
	}
	else if (inp->key == KEY_DEL || inp->key == CTR_KEY('d'))
	{
		gap_del_sym_on_slide(&inp->gap);
	}
	else if (inp->key == KEY_BCKSPACE)
	{
		if (inp->gap.slide)
			--inp->cr.x;
		gap_del_sym_before_slide(&inp->gap);
	}
	out_str = gap_get_buf(&inp->gap);
	write(STDOUT_FILENO, out_str, inp->gap.len_string);
	set_cursor_pos(inp->cr.x, inp->cr.y);
	visibility_cursor(VISIBLE_CUR);
}
