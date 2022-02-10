/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_fdsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:43:47 by omercade          #+#    #+#             */
/*   Updated: 2022/02/10 19:57:34 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	exe_fdsearch(t_ms *this)
{
	t_list	*aux;

	aux = this->tokenst;
	while (aux)
	{
		pipe(((t_token *)aux)->fd);
		aux = aux->next;
	}
}
