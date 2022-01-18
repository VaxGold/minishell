/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   babelfish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:40:51 by omercade          #+#    #+#             */
/*   Updated: 2022/01/18 18:44:30 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

void	display_tokens(t_list *token)
{
	int i;

	i = 0;
	if (token == NULL )
	{
		printf("Lista de tokens vacia!\n");
		return ;
	}
	while (token != NULL)
	{
		printf("---->TOKEN #%d<----\n", i);
		printf("type: %d\n", ((t_token *)(token->content))->type);
		printf("content: %s\n\n", ((t_token *)(token->content))->str);
		token = token->next;
		i++;
	}
	return ;
}

void	display_quotes(int *quotes, int len)
{
	int i;

	i = 0;
	if (quotes == NULL )
	{
		printf("VACIO!\n");
		return ;
	}
	while (i < len)
	{
		printf("%d ", quotes[i]);
		i++;
	}
	printf("\n");
	return ;
}

void	space_correction(char *buf)
{
	printf("Espacios corregidos de %s\n", buf);
	return ;
}

t_list	*babelfish(char *buf, char **env)
{
	t_list	*ftoken;
	t_list	*temp;
	int		*quotes = NULL;

	(void) env;
	space_correction(buf);
	quotes = bf_escapes(quotes, buf);
	display_quotes(quotes, ft_strlen(buf));
	ftoken = bf_split(buf, quotes);
	temp = ftoken;
	display_tokens(ftoken);
	// while (temp != NULL)
	// {
	// 	bf_expansions(((t_token *)(temp->content))->str, env);
	// 	temp = temp->next;
	// }
	// // free(temp);
	// bf_tokenizer(ftoken);
	return (ftoken);
}


	// while (((t_token *)(ft_lstlast(ftoken)->content))->type == PIPE
	// 			|| ((t_token *)(ftoken->content))->type == EMPTY)
	// {
	// }