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
		comm->cnt_arg++;
		comm->flag_nonarg = 0;
}

int ft_get_flag_token_for_first_sym(char *str)
{
	if (!ft_strcmp(str, ""))
		return (1);
	if (ft_strchr(SPEC_PIP, str[0]))
		return (2);
	if (ft_strchr(SPEC_REDIR, str[0]))
		return (3);
	else
		return (1);
}

int ft_flag_token(t_list *lst_token, t_data *data)
{
	int	i;
	char *new_token_content;
	int flag_quote;

	flag_quote = 0;
	new_token_content = ft_parse_processor(lst_token->content, data->my_env, &flag_quote);
	ft_free_ptr(lst_token->content);
	lst_token->content = ft_strdup(new_token_content);
	ft_free_ptr(new_token_content);
	if (flag_quote)
		return (1);
	i = ft_get_flag_token_for_first_sym(lst_token->content);
	return (i);
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
		clear_token = ft_parse_processor(tmp_content, env, NULL);
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
//	printf("ft_get_token\n");
//	ft_print_token(lst_token_tmp);
	if (!ft_check_token_syntax(lst_token_tmp))
		*flag_error_syntax = 1;
	return (lst_token_tmp);
}
