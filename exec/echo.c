#include "../minishell.h"

int	n_flag(char **args, int j)
{
	int		i;

	i = 0;
	if (args[j][0] == '-')
	{
		while (args[j][++i] != '\0')
		{
			if (args[j][i] != 'n')
				return (-1);
		}
		return (0);
	}
	return (-1);
}


void	printing(t_comm *comm, int j, int fd, int n)
{
	while (j < comm->cnt_arg)
	{
		ft_putstr_fd(comm->arg[j], fd);
		ft_putstr_fd(" ", fd);
		j++;
	}
	ft_putstr_fd(comm->arg[j], fd);
	if (n == 1)
		ft_putstr_fd("\n", fd);
}

int	echo_b(t_comm *comm, int fd)
{
	int j;
	int no_n;

	j = 0;
	no_n = 0;

	if (comm->cnt_arg > 1)
	{
		if (ft_strnstr(comm->arg[j], "-n", 2) != NULL)
		{
			while (!n_flag(comm->arg, j))
				j++;
			printing(comm, j, fd, no_n);
		}
		else
		{
			no_n++;
			printing(comm, j, fd, no_n);
		}
	}
	else
		ft_putstr_fd("\n", fd);
	g_global.return_value = 0;
	return (1);
}
