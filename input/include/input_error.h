/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 23:28:48 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/02 23:31:30 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_ERROR_H
# define INPUT_ERROR_H

# include <sys/types.h>
# include <unistd.h>

# include "libft.h"

void	input_error(const char *str);
void	input_error_ext(const char *str);

#endif
