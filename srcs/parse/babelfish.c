/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   babelfish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:40:51 by omercade          #+#    #+#             */
/*   Updated: 2022/02/10 17:21:09 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

/* 				DISPLAY FUNCTIONS				*/
void	display_array(char **arr, char *str)
{
	int	i;

	i = 0;
	if (!arr)
	{
		printf("NO ARGS!\n");
		return ;
	}
	while (arr[i] != 0)
	{
		printf("%s#%d: %s\t", str, i + 1, arr[i]);
		i++;
	}
	printf("\n");
	return ;
}

void	display_lst(t_list *lst, char *str)
{
	int	i;

	i = 0;
	if (!lst)
	{
		printf("NO %s_LST!\n", str);
		return ;
	}
	while (lst)
	{
		printf("%s_LST #%d->\t", str, i);
		printf("(%s)", ((t_redirect *)(lst->content))->simbol);
		display_array(((t_redirect *)(lst->content))->args, "LST_ARG");
		lst = lst->next;
		i++;
	}
	return ;
}

void	display_tokens(t_list *token)
{
	t_list	*aux;
	int		i;

	aux = token;
	i = 1;
	while (aux)
	{
		printf("TOKEN #%d\n", i);
		display_array(((t_token *)(aux->content))->args, "ARG");
		display_lst(((t_token *)(aux->content))->in, "IN");
		display_lst(((t_token *)(aux->content))->out, "OUT");
		printf("\n");
		aux = aux->next;
		i++;
	}
	return ;
}
/*				--------------------------				*/

t_list	*babelfish(char *buf, char **env)
{
	int		i;
	int		start;
	int		*quotes;
	t_list	*tokenst;

	start = 0;
	quotes = bf_escapes(buf);
	tokenst = NULL;
	i = 0;
	while (buf[i] != '\0')
	{
		if(buf[i] == '|' && quotes[i] == 0)
		{
			ft_lstadd_back(&tokenst, bf_tokenizer(ft_substr(buf, start, i - start), env));
			start = i + 1;
		}
		i++;
	}
	ft_lstadd_back(&tokenst, bf_tokenizer(ft_substr(buf, start, i - start), env));
	free(quotes);
	display_tokens(tokenst);
	return (tokenst);
}