/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_inchild.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:49:16 by omercade          #+#    #+#             */
/*   Updated: 2022/02/09 18:49:50 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*exe_slashjoin(const char *str1, const char *str2)
{
	char	*aux;
	char	*res;

	aux = ft_strjoin(str1, "/");
	res = ft_strjoin(aux, str2);
	secure_freedom(aux);
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
			cmd_route = exe_slashjoin(mypaths[i], cmd);
			if (access(cmd_route, F_OK) == 0)
			{
				free_2d(mypaths);
				return (cmd_route);
			}
			secure_freedom(cmd_route);
		}
		free_2d(mypaths);
	}
	return (cmd);
}

void	exe_inchild(t_token *token, char **env)
{
	char *cmd_route;

	cmd_route = path_finder(token->args[0], env);
	execve(cmd_route, token->args, env);
	printf("Error de comando\n");
	exit(42);
}
