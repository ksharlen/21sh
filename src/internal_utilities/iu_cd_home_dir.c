/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iu_cd_home_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:37:02 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 21:08:10 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_utilities.h"

static void		push_curr_home_path(const char *old_path, char *new_path)
{
	uid_t			uid;
	char			*uhome_dir;

	(void)(old_path);
	(void)(new_path);
	uid = getuid();
	uhome_dir = getpwuid(uid)->pw_dir;
	ft_strcpy(new_path, uhome_dir);
	ft_strcat(new_path, old_path);
}

static void		push_any_users(const char *old_path, char *new_path)
{
	ft_strcpy(new_path, "/Users/");
	ft_strcat(new_path, old_path);
}

void			work_home_dir(const char *old_path, char *new_path)
{
	if (old_path && *old_path)
		++old_path;
	if (*old_path == '/' || !(*old_path))
		push_curr_home_path(old_path, new_path);
	else if (*old_path == '-')
		push_curr_home_path("", new_path);
	else if (ft_isalpha(*old_path))
		push_any_users(old_path, new_path);
}

void			cd_error(const char *error, const char *filename)
{
	ft_printf("%vcd: %s %s\n", STDERR_FILENO, error, filename);
}
