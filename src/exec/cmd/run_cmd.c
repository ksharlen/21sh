#include "exec.h"
// поиск и запуск необходимой внутренней команды
static int	find_and_run_cmd(t_pars_list *list)
{
	if (!ft_strcmp("true", list->name_func))
		list->status = cmd_true(list);
	else if (!ft_strcmp("false", list->name_func))
		list->status = cmd_false(list);
	else if (!ft_strcmp("cd", list->name_func))
		list->status = sh21_cd(0, NULL, NULL);	//////// замена
	else if (!ft_strcmp("echo", list->name_func))
		list->status = sh21_echo(0, NULL, NULL);	//////// замена
	else if (!ft_strcmp("pwd", list->name_func))
		list->status = sh21_pwd(0, NULL, NULL);	//////// замена
	else if (!ft_strcmp("setenv", list->name_func))
		list->status = sh21_setenv(NULL, NULL, 0);	//////// замена
	else if (!ft_strcmp("unsetenv", list->name_func))
		list->status = sh21_unsetenv(NULL);	//////// замена
	// else if (!ft_strcmp("env", list->name_func))//TODO: need add
		// list->status = minishell_env(0, NULL, NULL);	//////// замена
	return (g_term_lst.exec_status = list->status);
}

int			run_cmd(t_pars_list *list)
{
	cmd_check_var(list);
	return (find_and_run_cmd(list));
}
