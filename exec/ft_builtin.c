/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:38:28 by warchang          #+#    #+#             */
/*   Updated: 2021/08/18 10:38:30 by warchang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exit_mini(char **args)
{
	int	ret_exit;

	if (args[0])
	{
		if (ft_isalpha(args[0][0]))
		{
			ft_putendl_fd("minishell: exit : numeric argument required", 2);
			exit(255);
		}
		else
		{
			ret_exit = ft_atoi(args[0]);
			if (ret_exit <= 0)
			{
				ft_putendl_fd("minishell: exit : numeric argument required", 2);
				g_global.return_value = 255;
				exit(255);
			}
			ft_putendl_fd("exit", 2);
			g_global.return_value = ret_exit;
			exit(ret_exit);
		}
	}
}

int	ft_exit(char **args)
{
	long int	ret_exit;

	ret_exit = 0;
	if (args[0])
	{
		if (args[1])
		{
			ft_putendl_fd("exit", 2);
			ft_putendl_fd("minishell: exit: too many arguments", 2);
			return (1);
		}
		exit_mini(args);
	}
	ft_putendl_fd("exit", 2);
	g_global.return_value = ret_exit;
	exit(ret_exit);
}

int	ft_pwd(t_comm *comm)
{
	char	cwd[4097];

	ft_putstr_fd(getcwd(cwd, 4096), comm->fd_write);
	ft_putchar_fd('\n', comm->fd_write);
	g_global.return_value = 0;
	return (1);
}

int	ft_print_env(t_data *data, t_comm *comm, char **args)
{
	if (!args[0])
	{
		print_env(data, comm->fd_write);
		g_global.return_value = 0;
	}
	else
	{
		ft_putstr_fd("env: ", comm->fd_write);
		ft_putstr_fd(args[1], comm->fd_write);
		ft_putstr_fd(": No such file or directory", comm->fd_write);
		ft_putchar_fd('\n', comm->fd_write);
		g_global.return_value = 127;
	}
	return (1);
}
