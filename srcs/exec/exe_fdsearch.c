/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_fdsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:43:47 by omercade          #+#    #+#             */
/*   Updated: 2022/02/08 21:48:23 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	exe_fdsearch(t_ms *this)
{
	t_list *aux;

	aux = this->tokenst;
	while (aux)
	{
		pipe(((t_token *)aux)->fd);
		aux = aux->next;
	}
}
