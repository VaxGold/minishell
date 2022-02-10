/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executioner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:43:38 by omercade          #+#    #+#             */
/*   Updated: 2022/02/09 18:05:57 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	secure_freedom(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return ;
}

char	*ft_slashjoin(const char *str1, const char *str2)
{
	char	*aux;
	char	*res;

	aux = ft_strjoin(str1, "/");
	res = ft_strjoin(aux, str2);
	secure_freedom(aux);
	return (res);
}

void	free_2d(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		secure_freedom(array[i]);
		i++;
	}
	free(array);
	array = NULL;
	return ;
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
			cmd_route = ft_slashjoin(mypaths[i], cmd);
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

void	exe_child(t_token *token, char **env)
{
	char *cmd_route;

	cmd_route = path_finder(token->args[0], env);
	execve(cmd_route, token->args, env);
	printf("Error de comando\n");
	exit(42);
}

void	execalibur(t_ms *this)
{
	t_list	*aux;

	aux = this->tokenst;
	((t_token *)(aux->content))->pid = fork();
	if (((t_token *)(aux->content))->pid < 0)
		exit(17);	//Revisar el error
	else if (((t_token *)(aux->content))->pid == 0)
		exe_child(((t_token *)(aux->content)), this->env);
	else
		printf("Im are your father\n");
}

// void	executioner(t_ms *this)
// {
// 	t_list	*aux;
// 	int		fpipe;

// 	exe_fdsearch(this);
// 	aux = this->tokenst;
// 	exe_proces(aux);
// 	while (aux)
// 	{
// 		aux = aux->next;
// 	}
// 	return ;
// }

// void	exe_proces(t_list *process, char **env)
// {
// 	t_token	*aux;

// 	aux = ((t_token *)(process->content));

// 	aux->pid = fork();

// 	if (aux->pid)
// 	{
// 		if (process->next)
// 		{
// 			close();
// 			dup2();
// 			close();

// 		}
// 	}
// 	else
// 	{
// 		if (process->next)
// 		{
// 			close();
// 			dup2();
// 			close();
// 		}

// 	}
	
// }