#include "minishell.h"

int	creat_pipe(t_list *lst_comm, int *fds, int in)
{
	t_comm	*comm;

	fds[0] = -1;
	fds[1] = -1;
	if (!lst_comm)
	{
		if (in > 2 )
			close(in);
		return (0);
	}
	comm = lst_comm->content;
	comm->fd_read = in;
	if (lst_comm->next)
	{
		if (pipe(fds) == -1)
			return (-1);
		comm->fd_write = fds[1];
	}
	return (1);
}

void	exec_child(int *fds, t_comm *comm, t_data *data)
{
	close(fds[0]);
	if (exec_fd(comm))
		exit(1);
	if (comm->flag_after_redir)
		close(comm->fd_read);
	if (is_builtin(comm, data))
		exit(0);
	is_bins(comm, data);
	if (comm->lst_redir)
	{
		close(comm->fd_write);
		close(comm->fd_read);
	}
}

int	exec_fork(t_list *lst_comm, t_data *data, int in)
{
	int		fds[2];
	int		init_pipe;
	t_comm	*comm;

	init_pipe = creat_pipe(lst_comm, fds, in);
	if (init_pipe != 1)
		return (init_pipe);
	comm = lst_comm->content;
	comm->pid = fork();
	if (comm->pid == -1)
	{
		perror("minishell");
		kill(0, SIGKILL);
	}
	if (comm->pid != 0)
	{
		close(fds[1]);
		init_pipe = exec_fork(lst_comm->next, data, fds[0]);
	}
	else if (comm->pid == 0)
		exec_child(fds, comm, data);
	return (init_pipe);
}
