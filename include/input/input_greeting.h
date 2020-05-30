/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_greeting.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 02:55:57 by ksharlen          #+#    #+#             */
/*   Updated: 2020/03/29 18:44:33 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_GREETING_H
# define INPUT_GREETING_H

# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>

# include "libft.h"
# include "sh_struct.h"
# include "input_macros.h"
# include "internal_utilities.h"

# define QUOTE		"quote> "
# define DQUOTE		"dquote> "
# define BQUOTE		"bquote> "
# define HEREDOC	"heredoc> "

void	input_greeting(t_greet *greet);
void	input_greeting_init(t_exec_lst *execlist, t_greet *greet,
			const struct s_user_info *u_info);
int		input_additional_greet(t_greet *greet, const char *print_greet);

#endif
