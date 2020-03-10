/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_fd_and_close.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:42:17 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/29 20:38:23 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
// для дублирования дескрипторов
int		dup_fd_and_close(int fd, int dup_fd)
{
	int num;
	num = isatty(fd);
	perror("line0:");
	printf("fd = %d >> num = %d\n", fd, num);
	printf("dup_fd = %d >> num = %d\n", dup_fd, num);
	if (fd != dup_fd)
	{
		if (dup2(fd, dup_fd) < 0)
			return (1);
		perror("line1:");
		close(fd);
	}
	return (0);
}
