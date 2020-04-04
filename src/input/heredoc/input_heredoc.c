#include "input_parse_key.h"

static void gap_clean(t_gapbuf *gap)
{
	gap_clean_buf(gap);
	free(gap->buf);
}

static char	*new_line_for_heredoc(t_gapbuf *gap)
{
	char	*line;
	char	*gap_str;

	gap_str = gap_get_buf(gap);
	line = ft_strjoin(gap_str, "\n");
	ft_strdel(&gap_str);
	gap_clean(gap);
	return (line);
}

static char	*get_line(void)
{
	struct s_input	inp;

	input_init(&inp);
	inp.greet.mode = MODE_HEREDOC;
	input_greeting(&inp.greet);
	input_preparation(&inp);
	while (1)
	{
		inp.key = input_getch(&inp);
		input_process_key_press(&inp);
		if (inp.key == KEY_NEW_LINE)
		{
			write(STDOUT_FILENO, "\n", 1);
			break ;
		}
	}
	return (new_line_for_heredoc(&inp.gap));
}

char	*input_heredoc(char *delimeter)
{
	char			*line;
	char			buf[SH21_MAX_ARG];
	struct termios	cpy;

	line = NULL;
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
		ft_strdel(&line);
	}
	entry_canon(&cpy);
	return (ft_strdup(buf));
}
