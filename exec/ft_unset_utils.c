#include "../minishell.h"

t_lst_env	*ft_lst_env_del_head(t_lst_env *tmp_lst_env)
{
	t_lst_env	*lst_start;

	lst_start = tmp_lst_env->next;
	ft_free_env_struct(tmp_lst_env);
	ft_free_ptr(tmp_lst_env);
	return (lst_start);
}
