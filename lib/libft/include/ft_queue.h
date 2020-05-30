/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:30:40 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 21:10:31 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEUE_H
# define FT_QUEUE_H

# include <stdlib.h>
# include <sys/types.h>
# include <limits.h>

# include "ft_dbl_list_cycl.h"
# include "libft.h"

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

typedef struct	s_queue
{
	t_dlc		*beg_dek;
}				t_queue;

/*
**DEV
*/
void			ft_qu_init(t_queue *qu);
void			ft_qu_push(t_queue *qu, void *data, size_t size_data);
void			*ft_qu_pop(t_queue *qu);
int				ft_qu_is_empty(t_queue *qu);
void			ft_qu_remove(t_queue *qu, void (*del)());

#endif
