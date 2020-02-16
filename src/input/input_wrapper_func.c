/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_wrapper_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:09:01 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 17:15:30 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

ssize_t			input_read(const int fd, void *buf, const size_t nbyte)
{
	ssize_t	ret_read;

	ret_read = read(fd, buf, nbyte);
	ft_chk_sys_error(ret_read, E_READ);
	return (ret_read);
}

ssize_t			input_write(int fildes, const void *buf, size_t nbyte)
{
	ssize_t	ret_write;

	ret_write = write(fildes, buf, nbyte);
	if ((ret_write ^ nbyte) != 0)
		ft_err_exit(E_WRITE, "input_write: ret_write != nbyte");
	ft_chk_sys_error(ret_write, E_WRITE);
	return (ret_write);
}
