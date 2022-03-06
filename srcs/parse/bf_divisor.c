/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_divisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:01:20 by omercade          #+#    #+#             */
/*   Updated: 2022/03/06 22:11:31 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

void	bf_divisor(char *line, t_token *token, t_list **argst, char **env)
{
	int		i;
	int		start;
	int		*quotes;
	char	*aux;

	quotes = bf_escapes(line);
	start = 0;
	i = 0;
	while ((size_t)i < ft_strlen(line))
	{
		if ((line[i] == ' ' || line[i] == '<'
				|| line[i] == '>') && quotes[i] == 0)
		{
			aux = ft_substr(line, start, i - start);
			bf_div_addarg(aux, argst, env);
			free (aux);
			if (line[i] == '<')
				i += bf_div_addredir(&line[i], &token->in, env);
			else if (line[i] == '>')
				i += bf_div_addredir(&line[i], &token->out, env);
			start = i + 1;
		}
		i++;
	}
	aux = ft_substr(line, start, i - start);
	bf_div_addarg(aux, argst, env);
	free (aux);
	free(quotes);
	return ;
}
