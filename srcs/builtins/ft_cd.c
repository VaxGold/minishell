/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:29:46 by omercade          #+#    #+#             */
/*   Updated: 2022/02/19 19:36:36 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

// char	*ms_get_env(char **env, char *arg)
// {
// 	int		i;
// 	char	**split;

// 	i = 0;
// 	while (env[i])
// 	{
// 		split = ft_split(env[i], '=');
// 		if (ft_strcmp(split[0], arg) == 0)
// 		{
// 			ft_free_tab(split);
// 			break ;
// 		}
// 		else
// 			i++;
// 		ft_free_tab(split);
// 	}
// 	if (env[i] == NULL)
// 		return (NULL);
// 	return (env[i]);
// }

// void	set_pwd(char **arg, char **env)
// {
// 	char	*string;

// 	string = ft_strjoin(arg, env);
// 	ms_set_env(env, string);
// 	free (string);
// }

// int	ft_cd(char **arg, char **env)
// {
// 	char	c[PATH_MAX];

// 	if (arg == NULL)
// 	{
// 		arg = ms_get_env(env, "HOME") + 5;
// 		if ((arg - 5) == NULL)
// 		{
// 			printf("cd: HOME not set\n");
// 			return (1);
// 		}
// 	}
// 	getcwd(c, sizeof(c));
// 	if (chdir(arg) == -1)
// 	{
// 		if (arg[0] == '\0')
// 			return (1);
// 		ft_putstr_fd("cd: ", 2);
// 		ft_putstr_fd(arg, 2);
// 		ft_putendl_fd(": No such file or directory", 2);
// 		return (1);
// 	}
// 	set_pwd("OLDPWD=", env);
// 	getcwd(c, sizeof(c));
// 	set_pwd("PWD=", c);
// 	return (0);
// }

int	ft_cd(char **arg, char **env)
{
	printf("Soy ft_cd con %s y %s\n", arg[0], env[0]);
	return (0);
}