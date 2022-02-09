/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executioner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:43:38 by omercade          #+#    #+#             */
/*   Updated: 2022/02/08 22:44:39 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	executioner(t_ms *this)
{
	t_list	*aux;
	int		fpipe;

	exe_fdsearch(this);
	aux = this->tokenst;
	exe_proces(aux);
	while (aux)
	{
		aux = aux->next;
	}
	return ;
}



void	exe_proces(t_list *process, char **env)
{
	t_token	*aux;

	aux = ((t_token *)(process->content));

	aux->pid = fork();

	if (aux->pid)
	{
		if (process->next)
		{
			close();
			dup2();
			close();

		}
	}
	else
	{
		if (process->next)
		{
			close();
			dup2();
			close();
		}

	}
	
}