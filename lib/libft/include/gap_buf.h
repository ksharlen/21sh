/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_buf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:23:19 by ksharlen          #+#    #+#             */
/*   Updated: 2020/03/29 19:05:41 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAP_BUF_H
# define GAP_BUF_H

# include <unistd.h>
# include <sys/types.h>
# include <stdbool.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

# include "libft.h"

# define DFLT_SIZE_GAP		10

typedef struct	s_gapbuf
{
	char	*buf;
	size_t	main_size_gap_buf;
	size_t	size_buf;
	size_t	len_string;
	size_t	slide;
	size_t	size_gap_buf;
	size_t	gap_start;
	size_t	gap_end;
}				t_gapbuf;

/*
**INTERFACE_GENERAL
*/
void			gap_init(t_gapbuf *buf, size_t size_buf, size_t size_gap);
char			*gap_get_buf(t_gapbuf *buf);
void			gap_slide_left(t_gapbuf *buf);
void			gap_slide_right(t_gapbuf *buf);
void			gap_put_end_str(t_gapbuf *buf, char sym);

/*
**INTERFACE_DEL_INS_SYM
*/
void			gap_putchar_in_buf(t_gapbuf *buf, char sym);
void			gap_del_sym_before_slide(t_gapbuf *buf);
void			gap_del_sym_on_slide(t_gapbuf *buf);
void			gap_clean_buf(t_gapbuf *buf);
void			gap_swap_two_sym(t_gapbuf *buf);
void			gap_put_str(t_gapbuf *buf, const char *str);

/*
**INTERFACE_COPY_PASTE_CUT_STRING
*/
char			*gap_copy_str(t_gapbuf *buf);
char			*gap_cut_str(t_gapbuf *buf);
void			gap_paste_str(t_gapbuf *buf, const char *str);

/*
**INTERNAL
*/
void			die_gap(const char *s);
int				get_sym_ind_at_buf(t_gapbuf *buf, size_t pos_sym);
void			gapbuf_move_to_slide(t_gapbuf *buf);
void			get_new_gapbuf(t_gapbuf *buf, size_t len_get_new_gapbuf);
void			delete_gapbuf(t_gapbuf *buf);
void			gap_move(t_gapbuf *buf, size_t ind);

/*
**PRINT_BUF
*/
void			gap_print_buf(t_gapbuf *buf);

#endif
