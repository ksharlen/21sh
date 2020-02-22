/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 00:11:34 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/22 15:57:23 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <sys/types.h>
# include <unistd.h>

# include "libft.h"
# include "sh_limits.h"
# include "sh_struct.h"

void			parser(char *str_for_parse, t_info_parser *prs);
char			*pars_find_stream(char *str, char *splitter, t_pars_list *list);
t_red_stream	*pars_add_lst_stream(t_red_stream **stream_list);

/*
**	добавить в либу
*/
int		ft_checkspase(char sym);

#endif