/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:08:18 by omercade          #+#    #+#             */
/*   Updated: 2022/01/11 20:29:52 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h";

t_spliter	init_split()
{
	t_spliter	this;

	this.start = 0;
	this.end = 0;
	this.squoted = 0;
	this.quoted = 0;
	return (this);
}

int	check_quotes(char c, int *squoted, int *quoted)
{
	//FALTA CONTROLAR LA /
	if (c == '\'')
		*squoted = *(!squoted);
	else if (c == '"' && *(!squoted))
		*quoted = *(!quoted);
	else
		return (0);
	return (1);
}

t_list	*create_content(char *str)
{
	t_token	*new;
	
	new = malloc(sizeof(t_token));
	new->type = 0;
	new->content = str;
	return (ft_lstnew_bonus((void *)content));
}

t_list	*bf_split(char *buf)
{
	t_list		*first;
	t_spliter	this;
	int			i;

	i = 0;
	this = init_split();
	while (buf[i] || buf[i] != '\n')
	{
		if (check_quotes(buf[i], &(this.squoted), &(this.quoted)))
			i++;
		while (buf[i] != ' ' && (!squoted && !quoted))
			i++;
		end = i;
		if (end != start)
			ft_lstadd_back_bonus(&first, create_content(ft_substr(buf, start, end - start)));
		i++;
		start = i;
	}
	return (token);
}
