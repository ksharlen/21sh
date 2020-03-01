#include "parser.h"

void        parser_fill_point_args(t_pars_list *list)
{
    while (list)
    {
        if (list->pars_args)
            list->name_func = list->pars_args[0];
        list = list->next;
    }
}