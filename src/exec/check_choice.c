/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_choice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:41:27 by mdelphia          #+#    #+#             */
/*   Updated: 2020/03/08 19:33:42 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
// прокрутка или при ошибке завершения команды
static void	list_no_go_and(t_pars_list **list)
{
	if ((*list)->f_delimiter & F_PIPE)
		while (*list)
		{
			(*list) = (*list)->next;
			if ((*list) && !((*list)->f_delimiter & F_PIPE))
			{
				(*list) = (*list)->next;
				break ;
			}
		}
	else
		while (*list)
		{
			(*list) = (*list)->next;
			if ((*list) && !((*list)->f_delimiter & F_AND))
				break ;
		}
}
// функция для промотки труб
static void	list_not_go_pipe(t_pars_list **list)
{
	if ((*list)->f_delimiter & F_PIPE)
		while (*list)
		{
			(*list) = (*list)->next;
			if ((*list) && !((*list)->f_delimiter & F_PIPE))
			{
				// (*list) = (*list)->next;
				break ;
			}
		}
	else if ((*list)->f_delimiter & F_OR)
		while (*list)
		{
			(*list) = (*list)->next;
			if ((*list) && !((*list)->f_delimiter & F_OR))
			{
				(*list) = (*list)->next;
				break ;
			}
		}
}
// функция для промотки листов при успешном завершении команды
static void	status_ok(t_pars_list **list)
{
	t_pars_list *buf_list;

	while (*list)
	{
		buf_list = (*list);
		if ((buf_list->f_delimiter & F_SEMICOLON) || (buf_list->f_delimiter & F_AND))
		{
			(*list) = (*list)->next;
			break ;
		}
		else if (buf_list->f_delimiter & F_OR)
		{
			(*list) = (*list)->next;
			list_not_go_pipe(list);
		}
		else
			(*list) = (*list)->next;
	}	
}
// функция для промотки листов при команде завершившейся с ошибкой
static void	status_dontok(t_pars_list **list)
{
	t_pars_list *buf_list;

	while (*list)
	{
		buf_list = (*list);
		(*list) = (*list)->next;
		if ((buf_list->f_delimiter & F_SEMICOLON) || (buf_list->f_delimiter & F_OR))
			break ;
		if (buf_list->f_delimiter & F_AND)
			list_no_go_and(list);
	}
}
// функция для определения следующего запускаемого листа
static void	next_list(int status, t_pars_list **list)
{
	if (!status)
		status_ok(list);
	else
		status_dontok(list);
}
// проверка И / ИЛИ / & и выбор следующего запускаемого листа
void		check_choice(t_exec_lst execlist, t_pars_list *list)
{
	int status;

	while (list)
	{
		if (list->f_delimiter & F_AMPERSANT)			// отдельно запускается фоновый режим выполнения команд
			status = run_ampersant(execlist, &list);
		else
			status = check_run(execlist, &list);		// запуск функции определения режима запускаемых команд (это могут быть трубы, или обычный режим, или внутренние команды)}
		next_list(status, &list);						// функция выбора следующего запускаемого листа
	}
}