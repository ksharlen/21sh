/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_utilities.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:20:33 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/03 17:44:52 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_UTILITIES_H
# define INTERNAL_UTILITIES_H

# include <sys/types.h>
# include <limits.h>
# include <sys/stat.h>
# include <unistd.h>
# include <pwd.h>

# include "libft.h"
# include "21sh_limits.h"

/*
**ERRORS
*/
# define S_NO_SUCH "no such file or directory:"
# define S_TOO_MANY "too many arguments"

# define PWD_ERR(err) ft_printf("pwd: %s\n", err)

# define P_ARGS_UNUSED(...) (void)(__VA_ARGS__)

/*
**ENV
*/
# define ENV_NO_SUCH "no such file or directory"
# define ENV_PRINT(err, filename) ft_printf("env: %s: %s\n", filename, err)
# define ENV_OPT "P:i:u:S:"
# define USG	"usage: env [-iv] [-P utilpath] [-S string] [-u name]"
# define USG_1	"[name=value ...] [utility [argument ...]]"
# define ENV_ERR(err, filename) ft_printf("env: %s: %s\n", filename, err)
# define ERR_EXT(err, filename) ENV_ERR; exit(EXIT_FAILURE)
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
# define CD_TOO_MANY S_TOO_MANY
# define CD_ERR(err, filename) ft_printf("cd: %s %s\n", err, filename)
# define EMPTY_STR ""
# define IU_PATH argv[1]
# define N_TOO_LONG "File name too long"
# define NOT_DIR	"Not a directory:"
# define PERM		"Permission denied:"

# define MAX_UNAME		SH21_MAX_NAME
# define MAX_SIZE_PATH	SH21_MAX_PATH

extern char **environ;

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

struct				s_nameval
{
	char	*name;
	char	*value;
};

typedef struct		s_env
{
	t_opts		opt;
	char		*path_exec;
	char		*cmd;
	char		**cmd_argv;
}					t_env;

int					ftsh_pwd(int argc, char **argv, char **env);
int					ftsh_setenv(const char *name,
	const char *value, const int replace);
char				*ftsh_getenv(const char *name);
int					ftsh_unsetenv(const char *name);
int					ftsh_echo(int argc, char **argv, char **env);
int					ftsh_cd(int argc, char **argv, char **env);
void				work_home_dir(const char *old_path, char *new_path);

size_t				find_var_env(const char *name);
int					ftsh_env(int argc, char **argv, char **env);
void				work_opt(char *const *p_argv, t_env *env);
char				**split_s_key(const char *str);

/*
**WORK_FLAGS
*/
char *const			*u_flag(char *const argv[]);
char				**s_flag(const char *str);
char *const			*change_value_name(char *const argv[]);
struct s_nameval	split_name_val(const char *nameval);

/*
**TOOLS_ENV
*/
t_argv				*convert_structs(const t_env *conv_from);
int					exec_env(const t_env *env);

#endif
