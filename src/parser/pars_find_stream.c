/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_find_stream.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 22:35:05 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/29 15:56:37 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
// выводит ошибку символа в перенаправлении
char	*put_error_parse(char *str, int fd)
{
	ft_putstr_fd("42sh: parse error near \'", fd);
	if (str[0] != '\0')
		ft_putstr_fd(str, fd);
	else
		ft_putstr_fd("\\0", fd);
	ft_putstr_fd("\'\n", fd);
	return (NULL);
}

// проверяет на валидность имени файла (должны отсутствовать системные символы) // 4.3
int		check_valid_char_name(char sym)
{
	if (sym == '&' || sym == '|' || sym == ';' || sym == '\0' || sym == '<' || sym == '>')
		return (1);
	return (0);
}
// проеряет есть ли перенаправления // 1.3
static int	check_stream(char *str, char *splitter)
{

	while (str != splitter && !ft_isspace(*str))
	{
		if (*str == '>' || *str == '<')
		{
			if (*(str - 1) == '&')
				return (2);
			else
				return (1);
		}
		str++;
	}
	return (0);
}
// создаёт новые листы // 1.2
static void	add_lst_stream(t_red_stream **stream_list, int nbrlst)
{
	while (nbrlst--)
		pars_add_lst_stream(stream_list);
}
// 1.1
char		*pars_find_stream(char *str, char *splitter, t_pars_list *list)
{
	int	nbrlst;

	if ((nbrlst = check_stream(str, splitter)))
	{
		add_lst_stream(&list->stream_list, nbrlst);
		if (nbrlst == 2)
			str = pars_stream_in_list(str, splitter, list->stream_list->end->prev);
		else
			str = pars_stream_in_list(str, splitter, list->stream_list->end);
	}
	return (str);
}
