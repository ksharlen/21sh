/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_macros.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:28:43 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/02 19:16:59 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_MACROS_H
# define INPUT_MACROS_H

# include <limits.h>
# include <sys/types.h>

# define CTR_KEY(key) (key) ((key) & 0x1f)

/*
**KEY_PART
*/
# define ONE_SYM	1
# define ESC		"\x1b"
# define KEY_ARROW(key) ((key) >= 'A' && (key) <= 'D')


//!if CTR_KEY('q') если это истина

#endif
