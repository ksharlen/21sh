/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_greeting.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 02:55:57 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/03 17:09:55 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_GREETING_H
# define INPUT_GREETING_H

# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

# include "libft.h"
# include "input_struct.h"
# include "input_macros.h"
# include "input_greeting.h"
# include "21sh_struct.h"

# define SIZE_TIME	8
# define SIZE_NAME SH21_MAX_NAME
# define SIZE_DIR SH21_MAX_PATH
# define SKIP_DATE		11
# define COLOR_DFLT		"\e[0m"
# define COLOR_TIME		"\e[34;1m"
# define COLOR_USER		"\e[31;1m"
# define COLOR_DIR		"\e[36;1m"
# define COLOR_YELLOW	"\e[33;1m"

int			input_greeting(const struct s_user_info *u_info);

#endif