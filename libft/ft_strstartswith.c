#include "../minishell.h"

int	ft_strstartswith(char *s1, char *s2)
{
	int	i;

	i = -1;
	if (!s1 || !s2)
		return (0);
	while (s2[++i])
	{
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}
