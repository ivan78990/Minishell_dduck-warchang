#include "../minishell.h"

void	ft_exit(char **args)
{
	int	ret_exit;

	ret_exit = 0;
	if (args[0])
	{
		if (args[1])
		{
			ft_putendl_fd("exit", 1);
			ft_putendl_fd("bash: exit: too many arguments", 1);
			g_global.return_value = 1;
			exit(1);
		}
		if (!ft_isalpha(args[0][0]))
		{
			ret_exit = ft_atoi(args[0]);
			ft_putendl_fd("exit", 1);
			g_global.return_value = ret_exit;
			exit(ret_exit);
		}
	}
	ft_putendl_fd("exit", 1);
	g_global.return_value = ret_exit;
	exit(ret_exit);
}

int	ft_pwd(t_comm *comm)
{
	char	cwd[4097];

	ft_putstr_fd(getcwd(cwd, 4096), comm->fd_write);
	ft_putchar_fd('\n', comm->fd_write);
	g_global.return_value = 0;
	return (1);
}

int	ft_print_env(t_data *data, t_comm *comm, char **args)
{
	if (!args[0])
	{
		print_env(data, comm->fd_write);
		g_global.return_value = 0;
	}
	else
	{
		ft_putstr_fd("env: ", comm->fd_write);
		ft_putstr_fd(args[1], comm->fd_write);
		ft_putstr_fd(": No such file or directory", comm->fd_write);
		ft_putchar_fd('\n', comm->fd_write);
		g_global.return_value = 127;
	}
	return (1);
}
