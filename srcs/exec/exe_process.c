/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:55:41 by omercade          #+#    #+#             */
/*   Updated: 2022/02/14 18:42:49 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*slashjoin(const char *str1, const char *str2)
{
	char	*aux;
	char	*res;

	aux = ft_strjoin(str1, "/");
	res = ft_strjoin(aux, str2);
	free(aux);
	return (res);
}

char	**env_paths(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			return (ft_split(ft_substr
					(envp[i], 5, ft_strlen(envp[i]) - 5), ':'));
		i++;
	}
	return (NULL);
}

char	*path_finder(char *cmd, char **envp)
{
	int		i;
	char	*cmd_route;
	char	**mypaths;

	if (access(cmd, F_OK) != 0)
	{
		mypaths = env_paths(envp);
		i = -1;
		while (mypaths[++i])
		{
			cmd_route = slashjoin(mypaths[i], cmd);
			if (access(cmd_route, F_OK) == 0)
			{
				free_strarr(mypaths);
				return (cmd_route);
			}
			secure_free(cmd_route);
		}
		free_strarr(mypaths);
	}
	return (cmd);
}

void	exe_process(t_token *token, char **env)
{
	char *cmd_route;

	cmd_route = path_finder(token->args[0], env);
	execve(cmd_route, token->args, env);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(token->args[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(42);
}

// void	exe_process(char **cmd, char **env)		//GENERAL//
// {
// 	char *cmd_route;

// 	cmd_route = path_finder(cmd[0], env);
// 	printf("CMD ROUTE: %s\n", cmd_route);
// 	execve(cmd_route, cmd, env);
// 	ft_putstr_fd("minishell: ", 2);
// 	ft_putstr_fd(cmd[0], 2);
// 	ft_putstr_fd(": command not found\n", 2);
// 	exit(42);
// }
