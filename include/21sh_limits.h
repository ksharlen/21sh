/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh_limits.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 03:16:21 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/03 18:32:42 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH21_LIMITS_H
# define SH21_LIMITS_H

# include <sys/types.h>
# include <limits.h>

extern char **environ;

# define P_N	"21sh"

# define SH21_MAX_PATH	(sizeof(unsigned char) * 8 * 32) //!TMP
# define SH21_MAX_NAME	(sizeof(unsigned char) * 8 * 32)
# define SH21_MAX_ARG	1024

#endif