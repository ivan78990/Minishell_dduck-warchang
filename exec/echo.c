#include "../minishell.h"

int	n_flag(args, j)


void	printing(char **args, int j, int fd, int n)
{
	int i;

	i = 0;
	while(args[i])
		++i;
	while (j < i)
	{
		ft_putstr_fd(args[i], fd);
		ft_putstr_fd(" ", fd);
		j++;
	}
	ft_putstr_fd(args[i], fd);
	if (n == 0)
		ft_putstr_fd("\n", fd);
}

int	echo_b(char **args, int fd)
{
	int i;
	int j;
	int n;

	i = -1;
	j = 0;
	n = 0;
	while (args[i])
		++i;
	if (i > 0)
	{
		if (!ft_strcmp(args[j], "-n"))
		{
			while (!n_flag(args, j))
				j++;
			n++;
			printing(args, j, fd, n);
		}
		else
			printing(args, j, fd, n);
	}
	else
		ft_putstr_fd("\n", fd);
	g_global.return_value = 0;
	return (1);
}
