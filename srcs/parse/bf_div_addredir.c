/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_div_addredir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:18:13 by omercade          #+#    #+#             */
/*   Updated: 2022/03/02 19:54:31 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static int	fetch_simbol(char *line, char **simbol)
{
	int i;
	char	checker;

	i = 0;
	checker = line[i];
	while (line[i] == checker)
		i++;
	*simbol = ft_substr(line, 0, i);
	return (i);
}

int	count_strings(char const *s, char c)
{
	int	act_pos;
	int	str_count;

	act_pos = 0;
	str_count = 0;
	if (s[act_pos] == c)
		str_count--;
	while (s[act_pos] != '\0')
	{
		if (s[act_pos] == c && s[act_pos + 1] != c && s[act_pos + 1] != '\0')
			str_count++;
		act_pos++;
	}
	str_count++;
	return (str_count);
}

static void	redir_args(char *line, t_list **flst, t_redirect *this)
{
	
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
		redir_args(aux, lst, this);
		free(aux);
	}
	return (i - 1);
}
