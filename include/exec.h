/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:48:39 by mdelphia          #+#    #+#             */
/*   Updated: 2020/03/08 20:03:46 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH42_H
# define SH42_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>

# include "libft.h"
# include "sh_limits.h"
# include "sh_struct.h"
# include "internal_utilities.h"

/*
** exec function
*/
void					check_choice(t_exec_lst execlist, t_pars_list *list);
int						check_run(t_exec_lst execlist, t_pars_list **list);
int						stream_and_file(t_pars_list *list);
int						create_file(t_red_stream *stream_list);
int						redirect_stream(t_red_stream *stream_list);
int						dup_fd_and_close(int fd, int dup_fd);
int						run_ampersant(t_exec_lst execlist, t_pars_list **list);
void					run_exec(t_exec_lst execlist, int fd, t_pars_list *list);
void					run_pipe(t_exec_lst execlist, t_pipe_list **pipelist, t_pars_list **list);
int						new_or_open_file(char *file_name, int flag_open);
t_pars_list				*free_pars_list(t_pars_list **list);
t_pipe_list				*new_pipe_list(t_pipe_list *pipelist);
void 					free_pipe_list(t_pipe_list *pipelist);
int						stream_close_fd(t_red_stream *stream_list);
void					error_system(int status);
void					stream_save_std(t_red_stream *stream_list);
void					close_and_open_std(t_red_stream *stream_list);
int						write_this_dir(t_pars_list *list);
void 					free_befor_exec(t_info_parser *prs);
int                     exec_dup_stream(int oldfd, int newfd);

/*
** comands
*/
int						check_cmd(char *name_func);
int						run_cmd(t_exec_lst execlist, t_pars_list *list);
int						cmd_true(void);
int						cmd_false(void);
void 					cmd_check_var(t_pars_list *list);

#endif
