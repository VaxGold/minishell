/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_pipeset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:53:32 by omercade          #+#    #+#             */
/*   Updated: 2022/02/09 19:42:04 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	exe_pipeset(t_ms *this)
{
	t_list *aux;

	if (ft_lstsize(this->tokenst) < 2)
		return ;
	aux = this->tokenst;
	while (aux)
	{
		pipe(((t_token *)aux)->fd);
		aux = aux->next;
	}
}
