/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_termcap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 21:07:07 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/03 00:47:14 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_TERMCAP_H
# define INPUT_TERMCAP_H

# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <termcap.h>
# include <termios.h>

# include "input_error.h"
# include "libft.h"
# include "input_struct.h"
# include "input_macros.h"

# define CO	"co"
# define LI	"li"
# define CM	"cm"
# define CD	"cd"
# define CH	"ch"
# define CV	"cv"

/*
**INTERFACE
*/
struct s_cursor		get_pos_cursor(void);
struct s_win		get_win_size(void);
void				set_cursor_pos(int col, int row); //?отсчет от 0
void				set_cursor_col(int col); //?отсчет колонки от 0
void				set_cursor_row(int row); //?отсчет линии от 0
void				clear_curr_line_to_the_end(void);

/*
**INTERNAL
*/
void				input_tgetent(void);
char				*input_tgetstr(char *cb);
char				*input_tgoto(char *cb, int one, int two);
void				input_tputs(const char *str, int affcnt, int (*putc)(int));
int					input_tgetnum(char *str);

#endif
