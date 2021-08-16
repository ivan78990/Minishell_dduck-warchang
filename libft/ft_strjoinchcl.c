#include "../minishell.h"

char	*ft_strjoinchcl(char *s1, char c)
{
	char	*new;

	new = ft_strjoinch(s1, c);
	if (!new)
		return (NULL);
	free(s1);
	s1 = NULL;
	return (new);
}
