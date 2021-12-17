/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_expansions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:41:07 by omercade          #+#    #+#             */
/*   Updated: 2021/12/15 18:55:25 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h";

int		iseov(char *c)
{
	if (c < 48)
		return (0);
	else if (c >= 65 && c <= 90)
		return (0)
	else if (c >= 97 && c <= 122)
		return (0);
	else if (c == '_')
		return (0);
	return (1);
}

void exp_insert(char *str, char *mod, char *res)
{
	int		i;
	char	*start;
	char	*end;

	i = 0;
	while (str[i] != '$' /*&& !quoted_exp(str, i)*/)
		i++;
	start = ft_strjoin(ft_substr(str, 0, i), res);
	end = ft_strdup(ft_substr(str, i, ft_strlen(str) - i));
	str = ft_strjoin(start, end);
	free(start);
	free(end);
	return ;
}

void	exp_mod(char *expand, char *str, char **env)
{
	int i;
	char	*mod;
	char	*temp;

	i = 0;
	mod = ft_strdup("");
	temp = ft_strjoin(expand, "=");
	while (env[i])
	{
		if (ft_strncmp(temp, env[i], ft_strlen(temp)) == 0)
			mod = ft_strdup(ft_substr(env[i], ft_strlen(temp), ft_strlen(env[i]) - ft_strlen(temp)));
		i++;
	}
	free(temp);
	exp_insert(str, expand, mod);
	free(mod);
	return ;
}

void	bf_expansions(char *str, t_ms data)
{
	int		i;
	int		control;
	char	*expand;

	i = 0;
	control = -1;
	while (str[i] != 0)
	{
		if (iseov(str[i]) && control != -1)
		{
			expand = ft_strdup(ft_substr(str, control, i - control));
			break;
		}
		else if (str[i] == '$' /*&& !quoted_exp(str, i)*/)
			control = i + 1;
		i++;
	}
	if (control != -1)
	{
		exp_mod(expand, str, data);
		free(expand);
		bf_expansions(str, env);
	}
	return ;
}
