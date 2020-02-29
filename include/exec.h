#ifndef SH42_H
# define SH42_H

// # include <stdlib.h> // есть в либе
// # include <unistd.h> // есть в либе
// # include <string.h> // есть в либе
// # include <sys/ttycom.h>
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

# define EXEC_ERROR_NUM 432

// интерфейс
typedef struct			s_exec_lst
{
	t_start_env			exec_envlist;
}						t_exec_lst;

// структура для труб
typedef struct			s_pipe_list
{
	int 				pfd[2];							// дескрипторы труб
	struct s_pipe_list	*next;
	struct s_pipe_list	*prev;
}						t_pipe_list;


/*
** exec function
*/
void					check_choice(t_exec_lst execlist, t_pars_list **list);
int						check_run(t_exec_lst execlist, t_pars_list **list);
int						stream_and_file(t_pars_list *list);
int						create_file(t_red_stream *stream_list);
int						redirect_stream(t_red_stream *stream_list);
int						dup_fd_and_close(int fd, int dup_fd);
int						run_ampersant(t_exec_lst execlist, t_pars_list **list);
void					run_exec(t_exec_lst execlist, int fd, t_pars_list *list);
void					run_pipe(t_exec_lst execlist, t_pipe_list **pipelist, t_pars_list **list);
int						new_or_open_file(char *file_name, int flag_open);
t_pars_list				*free_pars_list(t_pars_list *list);
t_pipe_list				*new_pipe_list(t_pipe_list *pipelist);
void 					free_pipe_list(t_pipe_list *pipelist);
int						stream_close_fd(t_red_stream *stream_list);
void					error_system(int status);
void					stream_save_std(t_red_stream *stream_list);
void					close_and_open_std(t_red_stream *stream_list);
int						write_this_dir(t_pars_list *list);

/*
** comands
*/
int						check_cmd(char *name_func);
int						run_cmd(t_pars_list *list);
int						cmd_true(t_pars_list *list);
int						cmd_false(t_pars_list *list);
void 					cmd_check_var(t_pars_list *list);

/***
 Используемые функции:
 fork()					- error_exit
 malloc()				- error_exit
 open()
 execve()
 acsses()
 close()
 waitpid()
 pipe()
 dup2()
 exit()

 	Из либы:
 	ft_putstr_fd()
 	ft_putchar_fd()
 	ft_strcmp()
 	ft_itoa()
***/

#endif
