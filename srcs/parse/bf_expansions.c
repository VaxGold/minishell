/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_expansions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:41:07 by omercade          #+#    #+#             */
/*   Updated: 2022/02/09 17:24:07 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

int	iseov(char c)
{
	if (c == 0)
		return (1);
	else if (c < 48)
		return (0);
	else if (c >= 65 && c <= 90)
		return (0);
	else if (c >= 97 && c <= 122)
		return (0);
	else if (c == '_')
		return (0);
	return (1);
}

char	*exp_variable(char *expand, char **env)
{
	int		i;
	char	*mod;
	char	*temp;

	i = 0;
	mod = ft_strdup("");
	temp = ft_strjoin(expand, "=");
	while (env[i])
	{
		if (ft_strncmp(temp, env[i], ft_strlen(temp)) == 0)
			mod = ft_strdup(ft_substr(env[i],
						ft_strlen(temp), ft_strlen(env[i]) - ft_strlen(temp)));
		i++;
	}
	free(expand);
	free(temp);
	return (mod);
}

char	*exp_contructor(char *str, int start, int len, char **env)
{
	char	*aux;
	char	*end;
	char	*res;

	res = ft_substr(str, 0, start);
	end = exp_variable(ft_substr(str, start + 1, len - 1), env);
	aux = ft_strjoin(res, end);
	free(res);
	free(end);
	end = ft_substr(str, start + len, ft_strlen(str) - len);
	res = ft_strjoin(aux, end);
	free(aux);
	free(end);
	free(str);
	return (res);
}

char	*bf_expansions(char *str, char **env)
{
	int	*quotes;
	int	i;
	int	start;
	int	len;
	char	*res;

	quotes = bf_escapes(str);
	i = 0;
	start = -1;
	len = 0;
	while (str[i])
	{
		if ((iseov(str[i]) || str[i + 1] == 0) && start != -1)
		{
			len = i - start + 1;
			break ;
		}
		else if (str[i] == '$' && quotes[i] < 2)
			start = i;
		i++;
	}
	free(quotes);
	if (start == -1)
		return (str);
	res = exp_contructor(str, start, len, env);			//Sustitucion de la variable de entorno
	res = bf_expansions(res, env);
	return (res);
	//return (bf_expansions(res, env));				//Recursivo desactivado
}