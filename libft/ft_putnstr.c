#include "../minishell.h"

void	ft_putnstr(char *str, int n, int fd)
{
	int		i;

	i = -1;
	if (n < 0)
	{
		while (str[++i] && i < (int)ft_strlen(str) + n)
			ft_putchar_fd(str[i], fd);
	}
	else
	{
		while (str[++i] && i < n)
			ft_putchar_fd(str[i], fd);
	}
}
