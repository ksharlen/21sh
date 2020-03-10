/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_utilities.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <tjonella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:20:33 by ksharlen          #+#    #+#             */
/*   Updated: 2020/03/10 20:04:20 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_UTILITIES_H
# define INTERNAL_UTILITIES_H

# include <sys/types.h>
# include <limits.h>
# include <sys/stat.h>
# include <unistd.h>
# include <pwd.h>
# include <dirent.h>

# include "libft.h"
# include "sh_struct.h"

/*
**ERRORS
*/
# define S_NO_SUCH "no such file or directory:"
# define S_TOO_MANY "too many arguments"

/*
**ENV
*/
# define NO_SUCH "no such file or directory"
# define ENV_OPT "P:iu:S:"
# define USG	"usage: env [-iv] [-P utilpath] [-S string] [-u name]"
# define USG_1	"[name=value ...] [utility [argument ...]]"
# define F_P 1
# define F_I 2
# define F_U 4
# define F_S 8

/*
**ECHO
*/
# define ECHO_OPT "n"

/*
**CD
*/
# define CD_TOO_MANY		S_TOO_MANY
# define CD_ERR				cd_error
# define EMPTY_STR 			""
# define N_TOO_LONG 		"File name too long"
# define NOT_DIR			"Not a directory:"
# define PERM				"Permission denied:"

# define MAX_UNAME		256
# define MAX_SIZE_PATH	256

extern char		**g_sh_environ;

enum			e_find
{
	NOT_FOUND = -1,
	FOUND_INTERNAL_CMD,
	FOUND_SHELL_DIR,
	FOUND_PATH_ENV,
	FOUND,
	FOUND_EXIT,
};

typedef unsigned char	t_opts;
typedef struct s_argv	t_argv;

struct					s_nameval
{
	char	*name;
	char	*value;
};

typedef struct			s_env
{
	t_opts		opt;
	char		*path_exec;
	char		*cmd;
	char		**cmd_argv;
}						t_env;

void					init_env(char **env);
/*
**UTILITIES
*/
int						sh21_pwd(int argc, char **argv, char **env);
int						sh21_setenv(const char *name,
	const char *value, const int replace);
char					*sh21_getenv(const char *name);
int						sh21_unsetenv(const char *name);
int						sh21_echo(int argc, char **argv, char **env);
int						sh21_cd(int argc, char **argv, char **env);
int						sh21_env(int argc, char **argv, char **env);

void					work_home_dir(const char *old_path, char *new_path);
size_t					find_var_env(const char *name);
void					work_opt(char *const *p_argv, t_env *env);
void					exit_with_code(t_pars_list *list);

/*
**WORK_FLAGS
*/
char *const				*u_flag(char *const argv[]);
char					**s_flag(const char *str);
char *const				*change_value_name(char *const argv[]);
struct s_nameval		split_name_val(const char *nameval);
char					**split_s_key(const char *str);
void					cd_error(const char *error, const char *filename);

/*
**TMP
*/
void					print_env(void);
void					clean_env(void);

#endif
