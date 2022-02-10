/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skpspace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:15:45 by omercade          #+#    #+#             */
/*   Updated: 2022/02/10 19:50:19 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h";

int	skpspace(char *str, int index)
{
	while (isspace(arg[index]))
		index++;
	return (index);
}
