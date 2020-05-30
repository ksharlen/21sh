/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 17:57:44 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 21:09:45 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stdlib.h>
# include <sys/types.h>
# include <limits.h>

# include "libft.h"
# include "ft_dbl_list_cycl.h"

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

typedef struct	s_sstack
{
	t_dlc	*beg_dek;
}				t_stack;

/*
**DEV
*/
void			ft_stk_init(t_stack *stk);
void			ft_stk_push(t_stack *stk, void *data, size_t size_data);
void			*ft_stk_pop(t_stack *stk);
int				ft_stk_is_empty(t_stack *stk);

#endif
