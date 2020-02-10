#include "input_parse_key.h"

void	input_update_rows(struct s_input *inp, struct s_win *wn)
{
	ssize_t	reminder;

	reminder = 0;
	if (inp->win.rows != wn->rows)
	{
		if (inp->win.rows > wn->rows)
		{
			//TODO
		}
		else if (inp->win.rows < wn->rows)
		{
			reminder = wn->rows - inp->win.rows;
			inp->save_refresh_pos.y += reminder;
		}
	}
}
