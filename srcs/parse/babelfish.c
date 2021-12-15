/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   babelfish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:40:51 by omercade          #+#    #+#             */
/*   Updated: 2021/12/15 18:26:38 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h";

t_token	*babelfish(t_ms minidata, char *buf)
{
	int		i;
	t_token	*ftoken;

	bf_expansions(buf);
	ft_lstnew(ftoken);
	while (ft_lstlast(ftoken).type == UNION || ftoken->type == EMPTY)
	{
		//i = bf_master(ftoken, buf, i);
		//i = bf_added(ftoken, buf, i);
	}
	return (ftoken);
}
