/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse_key.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:38:23 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/03 02:52:30 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_PARSE_KEY_H
# define INPUT_PARSE_KEY_H

# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

# include "libft.h"
# include "input_struct.h"
# include "input_macros.h"
# include "input_termcap.h"

int		input_getch(void);
void	input_process_key_press(struct s_input *inp);

#endif
