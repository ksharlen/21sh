/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_termcap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 21:07:07 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/02 22:07:10 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_TERMCAP_H
# define INPUT_TERMCAP_H

# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <termcap.h>
# include <termios.h>

# include "libft.h"
# include "input_struct.h"
# include "input_macros.h"

struct s_cursor		get_pos_cursor(void);

#endif
