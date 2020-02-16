/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 23:25:34 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 19:55:20 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH21_BONUS_H
# define SH21_BONUS_H

# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

# include "sh_limits.h"
# include "sh_struct.h"
# include "input_macros.h"
# include "input_termcap.h"
# include "input_init.h"
# include "input_parse_key.h"
# include "input_greeting.h"

/*
**INPUT
*/
void	check_change_winsize(struct s_input *inp);
void	input_ctr_t(struct s_input *inp);

#endif