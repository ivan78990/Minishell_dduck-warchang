/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:21:33 by dduck             #+#    #+#             */
/*   Updated: 2021/08/12 15:21:34 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_get_arg(const char *str, t_comm *comm)
{
	if (str)
	{
		comm->cnt_arg++;
		comm->flag_nonarg = 0;
	}
}

int	ft_flag_token(char *str)
{
	int	i;

	i = 0;
	if (ft_strchr(SPEC_PIP, str[i]))
		return (2);
	if (ft_strchr(SPEC_REDIR, str[i]))
		return (3);
	return (1);
}

t_list	*ft_get_pos_list_token(int count_drop, t_list *lst_token)
{
	while (count_drop > 0)
	{
		lst_token = lst_token->next;
		count_drop--;
	}
	return (lst_token);
}

t_list	*ft_lstclear_of_quote_and_dollar(t_list *lst_token, char **env)
{
	char	*clear_token;
	char	*tmp_content;
	t_list	*clear_list_token;
	t_list	*tmp_lst;

	clear_token = NULL;
	tmp_content = NULL;
	clear_list_token = NULL;
	tmp_lst = NULL;
	if (!lst_token)
		return (NULL);
	tmp_lst = lst_token;
	while (lst_token)
	{
		tmp_content = lst_token->content;
		clear_token = ft_parse_processor(tmp_content, env);
		ft_lstadd_back(&clear_list_token, ft_lstnew(ft_strdup(clear_token)));
		ft_free_ptr(clear_token);
		lst_token = lst_token->next;
	}
	ft_lstclear(&tmp_lst, ft_free_ptr);
	return (clear_list_token);
}

t_list	*ft_get_token(char *str, t_data *data, int *flag_error_syntax)
{
	t_count	tc;
	t_list	*lst_token_tmp;
	t_list	*lst_token;

	lst_token = NULL;
	lst_token_tmp = NULL;
	ft_init_count(&tc);
	tc.len = (int) ft_strlen(str);
	while (++tc.i < tc.len)
	{
		tc.start = tc.i;
		while (ft_isspace(str[tc.i]) && tc.i <= tc.len)
		{
			tc.start++;
			tc.i++;
		}
		tc.j = 0;
		ft_check_tokensym(str, &tc);
		ft_lstadd_back(&lst_token_tmp,
			ft_lstnew(ft_substr(str, tc.start, tc.j)));
	}
	if (!ft_check_token_syntax(lst_token_tmp))
		*flag_error_syntax = 1;
	lst_token = ft_lstclear_of_quote_and_dollar(lst_token_tmp, data->my_env);
	return (lst_token);
}
