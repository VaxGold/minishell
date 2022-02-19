/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_delquotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:48:36 by omercade          #+#    #+#             */
/*   Updated: 2022/02/19 19:11:09 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

int		add_quoted(char	*fragment, char *ref)
{
	char	*aux;
	char	*added;
	char	simbol;
	int		len;

	simbol = fragment[0];
	len = 1;
	while (fragment[len] != simbol)
		len++;
	aux = ref;
	free(ref);
	added = ft_substr(fragment, 1, len - 2);
	ref = ft_strjoin(aux, added);
	free(aux);
	free(added);
	return (len);
}

void	add_rest(int start, int pos, char *str, char *ref)
{
	char	*aux;
	char	*added;

	if  (pos - start < 1)
		return;
	aux = ref;
	free(ref);
	added = ft_substr(str, start, pos - start);
	ref = ft_strjoin(aux, added);
	free(added);
	free(aux);
	return ;
}

char	*bf_delquotes(char *str)
{
	int		i;
	int		start;
	char	*res;

	i = 0;
	start = 0;
	while (str[i])
	{
		if (str[i] == '\"' || str[i]  == '\'')
		{
			add_rest(start, i, str, res);
			i += add_quoted(&str[i], res);
			start = i;
		}
		i++;
	}
	add_rest(start, i, str, res);
	free(str);
	return (res);
}