/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skpspace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:15:45 by omercade          #+#    #+#             */
/*   Updated: 2021/12/15 18:21:06 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h";

int	skpspace(char *str, int index)
{
	while (isspace(arg[index]))
		index++;
	return (index);
}