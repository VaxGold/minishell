/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:08:18 by omercade          #+#    #+#             */
/*   Updated: 2022/02/07 19:17:16 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

void	add_argument(char *line, t_list **argst, char **env)
{
	if (ft_strlen(line) < 1)
		return ;
	line = bf_expansions(line, env);							//EXPANSIONS!!
	ft_lstadd_back(argst, ft_lstnew((void *)line));
	return ;
}

int	fetch_simbol(char *line, char **simbol)
{
	int i;

	i = 0;
	while (line[i] == '<' || line[i] == '>')
		i++;
	if (i > 3)
		return (0);
	*simbol = ft_substr(line, 0, i);
	return (i);
}

int	add_redirection(char *line, t_list **lst, char **env)
{
	int			i;
	int			len;
	char		*aux;
	t_redirect	*this;

	this = malloc(sizeof(t_redirect));
	if (!this)
		return (0);
	len = fetch_simbol(line, &this->simbol);
	if (len > 2)
		this->simbol = NULL;
	i = len;
	while (line[i] == ' ' && line[i])
		i++;
	while (line[i] != ' ' && line[i] != '<' && line[i] != '>' && line[i])
		i++;
	if (len > 0 && this->simbol != NULL)
	{
		aux = ft_substr(line, len, i - len);
		aux = bf_expansions(aux, env);					//EXPANSIONS!!
		this->args = ft_split(aux, ' ');
		free(aux);
		ft_lstadd_back(lst, ft_lstnew(this));
	}
	return (i);
}

void	bf_split(char *line, t_token *token, t_list **argst, char **env)
{
	int	i;
	int	start;
	int	*quotes;
	
	quotes = bf_escapes(line);
	start = 0;
	i = 0;
	while ( (size_t)i < ft_strlen(line))
	{
		if ((line[i] == ' ' || line[i] == '<' || line[i] == '>') && quotes[i] == 0)
		{
			add_argument(ft_substr(line, start, i - start), argst, env);
			if (line[i] == '<')
				i += add_redirection(&line[i], &token->in, env);
			else if (line[i] == '>')
				i += add_redirection(&line[i], &token->out, env);
			start = i + 1;
		}
		i++;
	}
	add_argument(ft_substr(line, start, i - start), argst, env);
	free(quotes);
	return ;
}