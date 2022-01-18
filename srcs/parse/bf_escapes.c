/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_escapes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:41:39 by omercade          #+#    #+#             */
/*   Updated: 2022/01/18 18:44:19 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

void	check_escape(int *this, char *str)
{
	int	i;
	int	set;

	i = 0;
	set = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == '\\')
		{
			this[i++] = 3;
			this[i] = 3;
		}
		else if (str[i] == '\'')
		{
			if (set == 2)
				set = 0;
			else
				set = 2;
			this[i] = 2;
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
		i++;
	}
}

int	*bf_escapes(int *this, char *str)
{
	int i;
	
	if (this)
	{
		this = NULL;
		free(this);
	}
	this = malloc(sizeof(int) * ft_strlen(str));
	if (!this)
		return (NULL);
	check_escape(this, str);
	printf("DISPLAY ESCAPES\n");
	i = 0;
	while (i < (int)ft_strlen(str))
	{
		printf("%d -> %c\n", this[i], str[i]);
		i++;
	}
	return (this);
}
