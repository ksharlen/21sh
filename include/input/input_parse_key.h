/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse_key.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:38:23 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/04 01:34:45 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_PARSE_KEY_H
# define INPUT_PARSE_KEY_H

# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

# include "libft.h"
# include "21sh_struct.h"
# include "input_macros.h"
# include "input_termcap.h"
# include "input_init.h"
# include "input_greeting.h"

int		input_getch(void);
void	input_process_key_press(struct s_input *inp);
char	*input_begin(struct s_input *inp);
void	refresh_screen(struct s_input *inp);
void	move_cursor(struct s_input *inp);
int		check_line_footnote_up(struct s_input *inp);
int		check_line_footnote_down(struct s_input *inp);

#endif
