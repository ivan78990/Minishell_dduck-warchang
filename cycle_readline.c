#include "minishell.h"

void	cycle_readline(t_list *lst_comm, t_data *data, char *input)
{
	rl_outstream = stderr;
	while (!data->flag_end)
	{
		signal_normal();

		input = readline("minishell: ");
		if (input == NULL)
			break ;
		lst_comm = ft_preparser(data, input);
		add_history(input);
		if (lst_comm)
		{
			if (lst_comm->next)
			{
				if (exec_fork(lst_comm, data, STDIN_FILENO) != -1)
					wait_child_process(lst_comm);
				else
					kill_child_process(lst_comm);
			}
			else
				simplest_exec(lst_comm->content, data);
			ft_free_lst_comm(lst_comm);
		}
		ft_refresh_dollar_quest(data);
		free(input);
	}
}
