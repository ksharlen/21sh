#include "exec.h"

int		cmd_false(t_pars_list *list)
{
	list->status = 1;
	return (g_term_lst.exec_status = 1);
}
