/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh_init.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 03:09:54 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/03 18:33:42 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include <sys/types.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <pwd.h>

# include "libft.h"
# include "21sh_limits.h"
# include "21sh_struct.h"
# include "internal_utilities.h"

# define CLEAN	ft_bzero

void			sh21_init(t_init *init);
void			sh21_init_start_env(struct s_start_env *env, const struct s_user_info *user);
//void			sh21_init_struct(t_init *init, struct s_ftsh *ftsh);

#endif