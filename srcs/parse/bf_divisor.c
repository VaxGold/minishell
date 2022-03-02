/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_divisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:01:20 by omercade          #+#    #+#             */
/*   Updated: 2022/03/02 19:33:30 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static void	add_arg(char *arg, t_list **lst, char **env)
{
	bf_div_addarg(arg, lst, env);
	free(arg);
}

void	bf_divisor(char *line, t_token *token, t_list **argst, char **env)
{
	int		i;
	int		start;
	int		*quotes;

	quotes = bf_escapes(line);
	start = 0;
	i = 0;
	while ((size_t)i < ft_strlen(line))
	{
		if ((line[i] == ' ' || line[i] == '<'
				|| line[i] == '>') && quotes[i] == 0)
		{
			add_arg(ft_substr(line, start, i - start), argst, env);
			if (line[i] == '<')
				i += bf_div_addredir(&line[i], &token->in, env);
			else if (line[i] == '>')
				i += bf_div_addredir(&line[i], &token->out, env);
			start = i + 1;
		}
		i++;
	}
	add_arg(ft_substr(line, start, i - start), argst, env);
	free(quotes);
	return ;
}
