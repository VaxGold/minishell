/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   babelfish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:40:51 by omercade          #+#    #+#             */
/*   Updated: 2022/01/11 20:15:17 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h";

void	space_correction(char *buf)
{
	return ;
}

t_list	*babelfish(char *buf, char **env)
{
	int		i;
	t_list	*ftoken;
	t_list	*temp;

	space_correction(buf);
	ftoken = bf_split(buf);
	temp = ftoken;
	while (temp != NULL)
	{
		bf_expansions(((t_token *)(temp->content))->str, env);
		temp = temp->next;
	}
	// free(temp);
	bf_tokenizer(ftoken);
	return (ftoken);
}


	// while (((t_token *)(ft_lstlast(ftoken)->content))->type == PIPE
	// 			|| ((t_token *)(ftoken->content))->type == EMPTY)
	// {
	// }