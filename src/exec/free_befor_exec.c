#include "exec.h"

void	free_befor_exec(t_info_parser *prs)
{
	if	(prs->beg)
		free_pars_list(&prs->beg);
		prs->beg = NULL;
		prs->end = NULL;
}