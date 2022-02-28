/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:30:10 by omercade          #+#    #+#             */
/*   Updated: 2022/02/22 18:49:15 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/builtins.h"
#include "../../includes/minishell.h"

int	ms_check_export_arg(char *arg)
{
	int	i;

	i = 0;
	if (ft_isalpha(arg[i]) == 0 && arg[i] != '_')
	{
		printf("export: '%s': not a valid identifier\n", arg);
		return (1);
	}
	i++;
	while (arg[i] && arg[i] != '=')
	{
		if (ft_isalnum(arg[i]) == 0 && arg[i] != '_')
		{
			printf("export: '%s': not a valid identifier\n", arg);
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ms_make_string(char *arg)
{
	char	**strings;
	char	*string;
	int		i;

	i = 1;
	strings = ft_split(arg, '=');
	string = ft_strjoin(strings[0], "=\"");
	while (strings[i] && strings[i + 1])
	{
		string = ft_strjoin_free_s1(string, strings[i++]);
		string = ft_strjoin_free_s1(string, "=");
	}
	if (strings[i])
		string = ft_strjoin_free_s1(string, strings[i]);
	string = ft_strjoin_free_s1(string, "\"");
	ft_free_tab(strings);
	return (string);
}

void	ms_export_sort(char **env_export)
{
	int	i;

	i = 0;
	ft_sort_tab(env_export);
	while (env_export[i])
		printf("declare -x %s\n", env_export[i++]);
}

char	**ms_export_valid_arg(char *arg, char *strings, char **env)
{
	char	*string;

	if (ft_strchr(arg, '=') == NULL)
	{
		if (ms_get_env(env, strings) == NULL)
			env = ms_matrix_add_line(env, arg);
	}
	else
	{
		string = ms_make_string(arg);
		if (ms_get_env(env, strings) == NULL)
			env = ms_matrix_add_line(env, arg);
		else
		{
			env = ms_matrix_remove_line(env, strings);
			env = ms_matrix_add_line(env, arg);
		}
		free(string);
	}
	return (env);
}

int	ft_export(t_ms *data)
{
	char	**strings;
	int		i;
	int		ret;
	char	**arg;

	arg = ((t_token *)(data->tokenst->content))->args;
	ret = 0;
	i = 1;
	while (arg[i])
	{
		if (ms_check_export_arg(arg[i]) != 0)
		{
			i++;
			continue ;
			ret = 1;
		}
		strings = ft_split(arg[i], '=');
		data->env = ms_export_valid_arg(arg[i], strings[0], data->env);
		ft_free_tab(strings);
		i++;
	}
	if (i == 1)
		ms_export_sort(data->env);
	return (ret);
}
/*
int	ft_export(t_ms *data)
{
	printf("Soy ft_export en el token: %s.\n", ((t_token *)(data->tokenst->content))->args[0]);
	return (0);
}*/