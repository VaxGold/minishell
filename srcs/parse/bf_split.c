/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:08:18 by omercade          #+#    #+#             */
/*   Updated: 2022/01/18 18:46:57 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

t_spliter	init_split()
{
	t_spliter	this;

	this.start = 0;
	this.end = 0;
	return (this);
}

t_list	*create_content(char *str)
{
	t_token	*new;
	
	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->type = 0;
	new->str = ft_strdup(str);
	return (ft_lstnew((void *)new));
}

t_list	*bf_split(char *buf, int *quotes)
{
	t_list		*first = NULL;
	t_spliter	this;
	int			i;
	
	i = 0;
	this = init_split();
	while (buf[i] && buf[i] != '\n')
	{
		while (buf[i])
		{
			if (buf[i] == ' ' && quotes[i] == 0)
				break ;
			i++;
		}
		this.end = i;
		if (this.end != this.start)
			ft_lstadd_back(&first, create_content(ft_substr(buf, this.start, this.end - this.start)));
		i++;
		this.start = i;
	}
	return (first);
}
