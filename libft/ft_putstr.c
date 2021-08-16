#include "libft.h"

void	ft_putstr(char *s)
{
	size_t	len;

	if (s)
	{
		len = ft_strlen(s);
		write(1, s, len);
	}
}
