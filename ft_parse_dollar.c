/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 11:12:28 by dduck             #+#    #+#             */
/*   Updated: 2021/07/29 11:12:30 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_dollar_change1(char **tmp, char **tmp2, char **tmp3, char **tmp4)
{
	*tmp4 = ft_strjoin(*tmp, *tmp2);
	ft_free_ptr(*tmp2);
	ft_free_ptr(*tmp);
	*tmp = ft_strjoin(*tmp4, *tmp3);
	ft_free_ptr(*tmp3);
	ft_free_ptr(*tmp4);
}

void	ft_dollar_get_tmp(char **tmp)
{
	ft_free_ptr(*tmp);
	*tmp = ft_strdup("");
}

char	*ft_dollar(char *str, int *i, char **env)
{
	t_count	cnt;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	char	*tmp4;

	*i = ft_init_dollar(&cnt, i, str);
	if (*i == cnt.j + 1)
		return (str);
	tmp = ft_substr(str, cnt.j + 1, *i - cnt.j - 1);
	cnt.k = -1;
	ft_check_env(env, &cnt, tmp);
	if (cnt.start)
	{
		ft_free_ptr(tmp);
		tmp2 = ft_substr(env[cnt.k], cnt.z + 1,
				ft_strlen(env[cnt.k]) - 1);
		tmp = ft_substr(str, 0, cnt.j);
		tmp3 = ft_strdup(str + *i);
		ft_dollar_change1(&tmp, &tmp2, &tmp3, &tmp4);
	}
	else
		ft_dollar_get_tmp(&tmp);
	ft_free_ptr(str);
	return (tmp);
}
