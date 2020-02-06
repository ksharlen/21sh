/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse_key.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:38:23 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/06 20:47:59 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_PARSE_KEY_H
# define INPUT_PARSE_KEY_H

# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

# include "libft.h"
# include "ft_queue.h"
# include "21sh_struct.h"
# include "input_macros.h"
# include "input_termcap.h"
# include "input_init.h"
# include "input_greeting.h"

int				input_getch(void);
void			input_process_key_press(struct s_input *inp);
char			*input_begin(struct s_input *inp);
void			refresh_screen(struct s_input *inp);
void			move_cursor(struct s_input *inp);
int				check_line_footnote_up(struct s_input *inp);
int				check_line_footnote_down(struct s_input *inp);
void			clear_full_screen(struct s_input *inp);
struct s_cursor	input_get_end_string(struct s_input *inp);
void			input_parse_page_keys(struct s_input *inp);
void			input_parse_keys_shift_words(struct s_input *inp);
void			ctr_keys(struct s_input *inp);
void			input_paste_to_buf(struct s_input *inp);
void			input_cut_from_buf(struct s_input *inp);
void			input_copy_from_buf(struct s_input *inp);
void			get_coor_word(struct s_input *inp, ssize_t pos);
void			input_additional_modes(struct s_input *inp);
void			input_quote_mode(struct s_input *inp);
void			input_put_new_line(struct s_input *inp);
void			clean_struct_input(struct s_input *inp);
int				search_double_quotes(t_queue *qu);

#endif
