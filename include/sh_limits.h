/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_limits.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 03:16:21 by ksharlen          #+#    #+#             */
/*   Updated: 2020/03/15 19:58:00 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_LIMITS_H
# define SH_LIMITS_H

# include <sys/types.h>
# include <limits.h>

# define STR_ERR_SHELL	"21sh: "
# define P_N			"21sh"

# define SH21_MAX_PATH	256
# define SH21_MAX_NAME	256
# define SH21_MAX_ARG	1024

/*
** GREETING
*/
# define SIZE_TIME		8
# define SIZE_NAME		SH21_MAX_NAME
# define SIZE_DIR		SH21_MAX_PATH
# define SKIP_DATE		11
# define COLOR_DFLT		"\e[0m"
# define COLOR_TIME		"\e[34;1m"
# define COLOR_USER		"\e[31;1m"
# define COLOR_DIR		"\e[36;1m"
# define COLOR_YELLOW	"\e[33;1m"

# define F_SEMICOLON	1
# define F_AND			2
# define F_OR			4
# define F_AMPERSANT	8
# define F_PIPE			16
# define V_DOLLAR		32

# define EXEC_ERROR_NUM 254

/*
** FOR SIGNALS
*/
# define SHLVL "SHLVL"
# define FORMAT "%v[%s]    %d %s  %s\n"
# define PRINT_S(l, p, e, f) ft_printf(FORMAT, STDERR, l, p, e, f)
# define PRINT_SIG_ERR(lvl, pid, err, file) PRINT_S(lvl, pid, err, file)
# define ESIG	"Segmentation fault"
# define EBUS	"Bus error"
# define QUIT	"Quit"
# define EABR	"Abort trap"
# define FPOT	"Floating point exception"

/*
** STR_ERRORS
*/
# define DELIM_ERR	"parse error near"

typedef int32_t			t_key;

#endif
