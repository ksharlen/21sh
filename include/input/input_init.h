/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:23:45 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/03 23:17:57 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_INIT_H
# define INPUT_INIT_H

# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <termios.h>

# include "libft.h"
# include "input_macros.h"
# include "input_termcap.h"

void	entry_not_canon(struct termios *st_copy);
void	entry_canon(struct termios *st_term);
void	input_init(struct s_input *inp);

#endif