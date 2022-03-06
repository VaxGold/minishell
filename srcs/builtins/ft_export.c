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

static void	swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_tab(char **arr)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_strncmp(arr[i], arr[j], ft_strlen(arr[i])) > 0)
				swap(&arr[i], &arr[j]);
			++j;
		}
		++i;
	}
}

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
	char	*tmp;
	int		i;

	i = 1;
	strings = ft_split(arg, '=');
	string = ft_strjoin(strings[0], "=\"");
	while (strings[i] && strings[i + 1])
	{
		tmp = ft_strjoin(string, strings[i++]);
		free(string);
		string = ft_strjoin(tmp, "=");
		free(tmp);
	}
	if (strings[i])
	{
		tmp = ft_strdup(string);
		free(string);
		string = ft_strjoin(tmp, strings[i]);
		free(tmp);
	}
	tmp = ft_strdup(string);
	free(string);
	string = ft_strjoin(tmp, "\"");
	free(tmp);
	free_strarr(strings);
	return (string);
}

void	ms_export_sort(char **env_export, int fd)
{
	int	i;
	char	*string;

	i = 0;
	ft_sort_tab(env_export);
	while (env_export[i])
	{
		string = ms_make_string(env_export[i++]);
		ft_putstr_fd("declare -x ", fd);
		ft_putstr_fd(string, fd);
		ft_putstr_fd("\n", fd);
		free(string);
	}
}

char	**ms_export_valid_arg(char *arg, char *strings, char **env)
{
	if (ft_strchr(arg, '=') == NULL)
	{
		if (ms_get_env(env, strings) == NULL)
			env = add_strarr(env, arg);
	}
	else
	{
		if (ms_get_env(env, strings) == NULL)
			env = add_strarr(env, arg);
		else
		{
			env = rm_strarr(env, strings);
			env = add_strarr(env, arg);
		}
	}
	return (env);
}

int	ft_export(t_ms *data)
{
	char	**strings;
	int		i;
	int		ret;
	char	**arg;
	int 	fd;

	arg = ((t_token *)(data->tokenst->content))->args;
	fd = ((t_token *)(data->actual_token->content))->fd_out;
	ret = 0;
	i = 1;
	while (arg[i])
	{
		if (ms_check_export_arg(arg[i]) != 0)
		{
			i++;
			ret = 1;
			continue ;
		}
		strings = ft_split(arg[i], '=');
		data->env = ms_export_valid_arg(arg[i], strings[0], data->env);
		free_strarr(strings);
		i++;
	}
	if (i == 1)
		ms_export_sort(data->env, fd);
	return (ret);
}
