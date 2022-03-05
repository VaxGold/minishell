/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_escapes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:41:39 by omercade          #+#    #+#             */
/*   Updated: 2022/03/04 18:14:11 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

int	escape_level(int *this, char *str, int i, int set)
{
	if (str[i] == '\'')
	{
		if (set == 2)
		{
			set = 0;
			this[i] = 2;
		}
		else if (set == 1)
			this[i] = set;
		else
		{
			set = 2;
			this[i] = 2;
		}
	}
	else if (str[i] == '\"')
	{
		if (set == 2)
			this[i] = set;
		else
		{
			set = !set;
			this[i] = 1;
		}
	}
	else
		this[i] = set;
	return (set);
}

int	*bf_escapes(char *str)
{
	int	*quotes;
	int	i;
	int	set;
	
	quotes = malloc(sizeof(int) * ft_strlen(str));
	if (!quotes)
		return (NULL);
	set = 0;
	i = 0;
	while (str[i])
	{
		set = escape_level(quotes, str, i, set);
		i++;
	}
	if (set != 0)
		return (NULL);
	return (quotes);
}
