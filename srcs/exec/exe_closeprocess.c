/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_closeprocess.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:30:19 by omercade          #+#    #+#             */
/*   Updated: 2022/02/23 21:17:36 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exe_closeprocess(t_ms *data)
{
	t_token	*actual_t;
	t_list	*aux;
	int		opt;
	int		fd_file;
	int		(**menu)(t_ms *);

	menu = exe_menu();
	actual_t = (t_token *)(data->actual_token->content);
	opt = exe_opt(actual_t->args[0]);
	if (opt != -1)
	{
		if (actual_t->in)
			exe_redirect(actual_t->in, data->fd_in);
		if (actual_t->out)
			data->fd_out = exe_redirect(actual_t->out, data->fd_out);
		menu[opt](data);
	}
	else
	{
		actual_t->pid = fork();
		if (actual_t->pid)
		{
			dup2(actual_t->fd[0], STDIN_FILENO);
			close(actual_t->fd[0]);
			close(actual_t->fd[1]);
			if (actual_t->in)
			{
				fd_file = exe_redirect(actual_t->in, data->fd_in);
				dup2(fd_file, STDIN_FILENO);
				close(fd_file);
			}
			if (actual_t->out)
			{
				fd_file = exe_redirect(actual_t->out, data->fd_out);
				dup2(fd_file, STDOUT_FILENO);
				close(fd_file);
			}
			exe_process(actual_t, data->env);
		}
		else
		{
			close(actual_t->fd[0]);
			close(actual_t->fd[1]);
		}
		aux = data->tokenst;
		while (aux)
		{
			waitpid(((t_token *)(aux->content))->pid, NULL, 0);
			aux = aux->next;
		}
	}
}
