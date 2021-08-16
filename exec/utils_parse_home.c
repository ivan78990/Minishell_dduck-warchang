#include "../minishell.h"

char	*path_home(char *path, int rev_pars, t_data *data)
{
	char	*home_path;
	char	*new;
	int		res;

	if (!path)
		return (NULL);
	home_path = env_val("HOME", data);
	printf("home is : %s\n", home_path);
	if (rev_pars)
		res = ft_strstartswith(path, "~");
	else
		res = ft_strstartswith(path, home_path);
	if (!res)
		return (ft_strdup(path));
	if (rev_pars)
		new = ft_pathjoin(home_path, path + 1);
	else
	{
		if (*(path + ft_strlen(home_path)) == '\0')
			new = ft_strdup("~");
		else
			new = ft_pathjoin("~", path + ft_strlen(home_path));
	}
	return (new);
}
