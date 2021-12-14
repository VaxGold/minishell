/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   babelf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:17:29 by omercade          #+#    #+#             */
/*   Updated: 2021/12/13 20:39:57 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h";

int	skip_space(char *str, int index)
{
	while (isspace(arg[index]))
		index++;
	return (index);
}

void	babelf(t_ms *minidata)
{
	int i;

	ft_strdup(babel_expansions(minidata.buff));
	ft_lstnew(this.first);
	while (ft_lstlast(this.first).type == UNION)
	{
		//token_master();
		//token_arguments();
	}
	return ;
}
