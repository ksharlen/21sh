/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 00:11:34 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/23 17:43:00 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <sys/types.h>
# include <unistd.h>

# include "libft.h"
# include "sh_limits.h"
# include "sh_struct.h"

void		parser(char *str_for_parse, t_info_parser *prs);
void		parser_add_list(t_info_parser *prs);
char		*parser_skip_quotes(char *str, char *splitter);
char		*find_delimiter(char *str);
size_t		parser_count_args(const char *str, char *splitter);
size_t		parser_get_len_arg(char *str, char *splitter);
const char	*parser_skip_word(const char *str, char *splitter);
char		**parser_fill_args(char *start_str, char *splitter, size_t qty_args);
char		*parser_quote_arg(char **str, char *splitter);
char	    *fill_split_flag(char *splitter, int size, int *flags_splt);
char	    *skip_splitter(char *splitter, int *flags_splt);
int			parse_not_srvc_symb(char *c);

#endif