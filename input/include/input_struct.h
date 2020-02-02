/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:24:48 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/02 19:28:58 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_STRUCT_H
# define INPUT_STRUCT_H

# include <unistd.h>
# include <sys/types.h>
# include <limits.h>
# include <stdlib.h>

enum	e_key
{
	KEY_LEFT_ARROW = 1000,
	KEY_RIGHT_ARROW,
	KEY_UP_ARROW,
	KEY_DOWN_ARROW,
	KEY_HOME,
	KEY_END,
	KEY_DEL,
	KEY_PAGE_UP,
	KEY_PAGE_DOWN
};

struct s_key
{
	char	read_key[5];
	int		key;
	ssize_t	nread;
};

#endif
