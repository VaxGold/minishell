/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_div_addredir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:18:13 by omercade          #+#    #+#             */
/*   Updated: 2022/03/03 19:32:30 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static int	fetch_simbol(char *line, char **simbol)
{
	int		i;
	char	checker;

	i = 0;
	checker = line[i];
	while (line[i] == checker)
		i++;
	*simbol = ft_substr(line, 0, i);
	return (i);
}

static int	word_count(char *s)
{
	int		comp;
	int		cles;
	int		*quotes;

	quotes = bf_escapes(s);
	comp = 0;
	cles = 0;
	if (*s == '\0')
		return (0);
	while (*s != '\0')
	{
		if (*s == ' ')
			cles = 0;
		else if (cles == 0)
		{
			cles = 1;
			comp++;
		}
		s++;
	}
	free(quotes);
	return (comp);
}

static char	*add_argredir(char *line, int *i)
{
	int		len;
	int		*quotes;
	char	*res;

	quotes = bf_escapes(line);
	len = 0;
	while ((line[*i + len] != ' ' && quotes[*i + len] == 0) && line[*i + len] != '\0')
		len++;
	res = bf_delquotes(ft_substr(line, *i, len));
	*i += len;
	free(quotes);
	return (res);
}

static char	**redir_args(char *line)
{
	char	**args;
	int		i;
	int		wpos;

	args = malloc(sizeof(char *) * (word_count(line) + 1));
	i = 0;
	wpos = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			args[wpos++] = add_argredir(line, &i);
		i++;
	}
	args[wpos] = "\0";
	return (args);
}

int	bf_div_addredir(char *line, t_list **lst, char **env)
{
	t_redirect	*this;
	char		*aux;
	int			len;
	int			i;

	this = malloc(sizeof(t_redirect));
	if (!this)
		return (0);
	len = fetch_simbol(line, &this->simbol);
	i = len;
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i] && line[i] != ' ' && line[i] != '<' && line[i] != '>')		//quotes?
		i++;
	if (len > 0)
	{
		aux = ft_substr(line, len, i - len);
		aux = bf_expansions(aux, env);
		this->args = redir_args(aux);
		ft_lstadd_back(lst, ft_lstnew(this));
		free(aux);
	}
	return (i - 1);
}
