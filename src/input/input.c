/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 22:10:43 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/07 13:57:29 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

#define IS_CTR_D	0
#define IS_CTR_C	1
#define NOT_EXT_KEY	2

void		input_put_new_line(struct s_input *inp)
{
	int	last_rows_from_str;

	if (inp->gap.len_string + inp->len_greet > (size_t)inp->win.cols)
	{
		last_rows_from_str = (inp->gap.len_string + inp->len_greet) / inp->win.cols;
		inp->cr.y = inp->save_refresh_pos.y + last_rows_from_str;
		set_cursor_pos(0, inp->cr.y);
	}
	write(STDOUT_FILENO, "\n", 1);
}

void		clean_struct_input(struct s_input *inp)
{
	if (inp)
	{
		gap_clean_buf(&inp->gap);
		ft_strdel(&inp->str_for_parse);
		inp->greet = NULL;
		inp->len_greet = 0;
	}
}

static int	check_ext_key(struct s_input *inp)
{
	if (PRESS_CTR_D_AND_EMPTY_STR(inp->key, inp->gap.len_string))
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		entry_canon(&inp->cfg_cpy);
		return (IS_CTR_D);
	}
	else if (inp->key == CTR_KEY('c'))
	{
		clean_struct_input(inp);
		return (IS_CTR_C);
	}
	return (NOT_EXT_KEY);
}

static void	input_preparation(struct s_input *inp)
{
	input_tgetent();
	ft_strdel(&inp->str_for_parse);
	gap_clean_buf(&inp->gap);
	inp->greet = input_greeting;
	entry_not_canon(&inp->cfg_cpy);
	inp->len_greet = inp->greet(&inp->u_info);
	inp->win = get_win_size();
	inp->cr = get_pos_cursor();
	--inp->cr.x;
	--inp->cr.y;
	inp->save_refresh_pos = inp->cr;
	inp->key = 0;
}

void	input_begin(struct s_input *inp)
{
	int	ext_key;

	input_preparation(inp);
	while (inp->key != KEY_NEW_LINE)
	{
		inp->key = input_getch();
		check_change_winsize(inp);
		ext_key = check_ext_key(inp);
		if (ext_key == IS_CTR_D)
			return ;
		else if (ext_key == IS_CTR_C)
			break ;
		input_process_key_press(inp);
	}
	input_put_new_line(inp);
	if (inp->gap.len_string)
		inp->str_for_parse = gap_get_buf(&inp->gap);
	input_additional_modes(inp);
	entry_canon(&inp->cfg_cpy);
}
