/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:29:46 by omercade          #+#    #+#             */
/*   Updated: 2022/02/22 18:48:26 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/builtins.h"
#include "../../includes/minishell.h"

char	*ms_get_env(char **env, char *arg)
{
	int		i;
	char	**split;

	i = 0;
	while (env[i])
	{
		split = ft_split(env[i], '=');
		if (ft_strcmp(split[0], arg) == 0)
		{
			free_strarr(split);
			break ;
		}
		else
			i++;
		free_strarr(split);
	}
	if (env[i] == NULL)
		return (NULL);
	return (env[i]);
}

void	set_pwd(char *arg, char *path)
{
	char	*string;

	string = ft_strjoin(arg, path);
	printf("%s\n", string);
	//ms_set_env(env, string);
	free (string);
}

int	ft_cd(t_ms *data)
{
	char	c[PATH_MAX];
	char	**arg;
	char	*path;

	(void)data;
	arg = ((t_token *)(data->tokenst->content))->args;
	/*if (arg == NULL)
	{
		home_path = ms_get_env(data->env, "HOME") + 5;
		if ((home_path - 5) == NULL)
		{
			printf("cd: HOME not set\n");
			return (1);
		}
	}*/
	path = arg[1];
	getcwd(c, sizeof(c));
	if (chdir(path) == -1)
	{
		if (path == NULL)
			return (1);
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putendl_fd(": No such file or directory", 2);
		return (1);
	}
	set_pwd("OLDPWD=", c);
	getcwd(c, sizeof(c));
	set_pwd("PWD=", c);
	return (0);
}