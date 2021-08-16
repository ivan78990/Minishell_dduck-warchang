#include "../minishell.h"

static void	printing(char **str, int pos, int fd)
{
	int		strt;
	int		end;
	int		str_len;

	strt = (str[pos][0] == '"' || str[pos][0] == '\'');
	str_len = (int)ft_strlen(str[pos]);
	end = (str[pos][str_len - 1] == '"' || str[pos][str_len - 1] == '\'' );
	if (end && strt)
		ft_putnstr(str[pos] + 1, -1, fd);
	else if (end)
		ft_putnstr(str[pos], -1, fd);
	else if (strt)
		ft_putstr_fd(str[pos] + 1, fd);
	else
		ft_putstr_fd(str[pos], fd);
	if (str[pos + 1])
		ft_putchar_fd(' ', fd);
}

int	echo_b(char **args, int fd)
{
	int		i;
	int		n_flag;

	n_flag = 0;
	if (!args[0])
	{
		write(fd, "\n", 1);
		return (1);
	}
	if (!ft_strcmp(args[0], "-n"))
		n_flag = 1;
	i = -1;
	if (n_flag)
		++i;
	while (args[++i])
	{
		printing(args, i, fd);
		if (!args[i + 1] && !n_flag)
			ft_putchar_fd('\n', fd);
	}
	g_global.return_value = 0;
	return (1);
}
