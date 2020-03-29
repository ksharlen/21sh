#include "input_parse_key.h"

static void gap_clean(t_gapbuf *gap)
{
	gap_clean_buf(gap);
	free((gap)->buf);
	free(gap);
	(gap) = NULL;
}

static char	*get_line(void)
{
	struct s_input	inp;
	char			*line;

	input_init(&inp);
	input_preparation(&inp);
	inp.greet.mode = MODE_HEREDOC;
	input_greeting(&inp.greet);
	while (1)
	{
		inp.key = input_getch(&inp);
		input_process_key_press(&inp);
		if (inp.key == KEY_NEW_LINE)
			break ;
	}
	line = gap_get_buf(&inp.gap);
	gap_clean(&inp.gap);
	return (line);
}

char	*input_heredoc(char *delimeter)
{
	char			*line;
	char			buf[SH21_MAX_ARG];
	struct termios	cpy;

	entry_not_canon(&cpy);
	ft_bzero(buf, SH21_MAX_ARG);
	while (1)
	{
		line = get_line();
		if (!ft_memcmp(delimeter, line, ft_strlen(line) - 1))
		{
			ft_strdel(&line);
			break ;
		}
		ft_strcat(buf, line);
	}
	entry_canon(&cpy);
	return (ft_strdup(buf));
}
