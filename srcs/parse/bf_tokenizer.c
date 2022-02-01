/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:31:59 by omercade          #+#    #+#             */
/*   Updated: 2022/02/01 20:58:03 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

char	**lstargs(t_list *largs)
{
	char	**args;
	int		len;
	int		i;
	
	len = ft_lstsize(largs);
	if (len < 1)
		return (NULL);
	args = malloc(sizeof(char *) * (len + 1));
	if (!args)
		return (NULL);
	i = 0;
	while (largs)
	{
		args[i++] = ft_strdup((char *)(largs->content));
		largs = largs->next;
	}
	args[i] = '\0';
	return (args);
}

t_list	*bf_tokenizer(char *buf, char **env)
{
	t_token	new;
	t_list	*largs;
	int		*quotes;

	//Alocar token?
	quotes = bf_escapes(buf);
	bf_split(buf, &new, largs, quotes);
	//Comprobar lista de argumentos vacia?
	new.args = lstargs(largs);
	ft_lstclear(largs, free);
	free(quotes);
	return(ft_lstnew(&new));
}