#include "exec.h"

int		cmd_true(t_pars_list *list)
{
	list->status = 0;
	return (g_term_lst.exec_status = 0);
}
