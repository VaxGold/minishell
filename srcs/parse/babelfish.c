/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   babelfish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:40:51 by omercade          #+#    #+#             */
/*   Updated: 2022/02/28 17:52:31 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

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
	return (tokenst);
}