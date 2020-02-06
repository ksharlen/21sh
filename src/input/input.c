/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 22:10:43 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/06 17:52:56 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

static void	input_preparation(struct s_input *inp)
{
	//TODO: i think get size_win and pos_cursor need add in press key
	input_tgetent();
	inp->greet = input_greeting;
	gap_clean_buf(&inp->gap);
	entry_not_canon(&inp->cfg_cpy);
	inp->win = get_win_size();
	inp->len_greet = inp->greet(&inp->u_info);
	inp->cr = get_pos_cursor();
	--inp->cr.x;
	--inp->cr.y;
	inp->save_refresh_pos = inp->cr;
	inp->key = 0;
}

static void	put_new_line(struct s_input *inp)
{
	int	last_rows_from_str;

	last_rows_from_str = (inp->gap.len_string + inp->len_greet) / inp->win.cols;
	inp->cr.y = inp->save_refresh_pos.y + last_rows_from_str;
	set_cursor_pos(0, inp->cr.y);
	write(STDOUT_FILENO, "\n", 1);
}

char	*input_begin(struct s_input *inp)
{
	char	*cmd;

	input_preparation(inp);
	while (inp->key != KEY_NEW_LINE)
	{
		inp->key = input_getch();
		if (PRESS_CTR_D_AND_EMPTY_STR(inp->key, inp->gap.len_string))
		{
			ft_putchar_fd('\n', STDOUT_FILENO);
			return (NULL);
		}
		else if (inp->key == CTR_KEY('c'))
			break ;
		input_process_key_press(inp);
	}
	put_new_line(inp);
	// write(STDOUT_FILENO, "\n", 1);
	cmd = input_additional_modes(inp);
	entry_canon(&inp->cfg_cpy);
	return (cmd);
}
