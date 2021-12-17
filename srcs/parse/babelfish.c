/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   babelfish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:40:51 by omercade          #+#    #+#             */
/*   Updated: 2021/12/17 20:49:48 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h";

// void	bf_tokenizer()
// {

// }

t_list	*babelfish(char *buf, char **env)
{
	int		i;
	t_list	*ftoken;

	
	bf_expansions(buf, env);
	ftoken = ft_lstnew(NULL);
	while (((t_token *)(ft_lstlast(ftoken)->content))->type == PIPE
				|| ((t_token *)(ftoken->content))->type == EMPTY)
	{
		//i = bf_master(ftoken, buf, i);
		//i = bf_added(ftoken, buf, i);
	}
	return (ftoken);
}