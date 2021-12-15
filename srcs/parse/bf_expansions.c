/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_expansions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:41:07 by omercade          #+#    #+#             */
/*   Updated: 2021/12/15 18:55:25 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h";

void	exp_try(char *temp, char *expand, t_ms data)
{
	return ;
}

int		exp_change(char *expand, char *str, t_ms data)
{
	return (0);
}

void	bf_expansions(char *str, t_ms data)
{
	int		i;
	char	*temp;
	char	*expand;

	i = 0;
	temp = ft_strdup("");
	expand = ft_strdup("");
	while (str[i] != 0)
	{
		if (str[i] == '$' /*&& !quoted_exp(str, i)*/)
		{
			if (ft_strlen(temp) > 0)
				break;
			temp = ft_strdup("$");
		}
		i++;
	}
	//exp_try(temp, expand, data);			//on working...
	if (ft_strlen(expand) > 0)
	{
		//exp_change(expand, str, data);			//on working...
		bf_expansions(str, env);
	}
	free(temp);
	free(expand);
	return  ;
}
