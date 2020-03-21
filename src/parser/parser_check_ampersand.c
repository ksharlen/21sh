#include "parser.h"

void		parser_check_ampersand(char *splitter, t_pars_list *list)
{
	if (*splitter != '&' || (*splitter == '&' && *(splitter + 1) == '&'))
		return ;
	list->f_delimiter |= F_AMPERSANT;
	list->nbr_ampersant = parser_get_nbr_ampersand(list);
}