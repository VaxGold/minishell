/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_multiprocess.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:29:59 by omercade          #+#    #+#             */
/*   Updated: 2022/02/23 21:04:16 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exe_multiprocess(t_ms *data)
{
	t_token	*actual_t;
	t_token	*next_t;
	int		opt;
	int		fd_file;
	int		(**menu)(t_ms *);

	menu = exe_menu();
	actual_t = (t_token *)(data->actual_token->content);
	next_t = (t_token *)(data->actual_token->next->content);
	if (data->actual_token->next)
	{
		
		pipe(next_t->fd);
		opt = exe_opt(actual_t->args[0]);
		if (opt != -1)
		{
			if (actual_t->in)
				exe_redirect(actual_t->in, data->fd_in);
			if (actual_t->out)
				data->fd_out = exe_redirect(actual_t->out, data->fd_out);
			menu[opt](data);
			data->actual_token = data->actual_token->next;
			exe_multiprocess(data);
		}
		else
		{
			actual_t->pid = fork();
			if (!actual_t->pid)
			{
				close(actual_t->fd[1]);
				dup2(actual_t->fd[0], STDIN_FILENO);
				close(actual_t->fd[0]);
				dup2(next_t->fd[1], STDOUT_FILENO);
				close(next_t->fd[1]);
				close(next_t->fd[0]);
				exe_process(actual_t, data->env);
			}
			else
			{
				close(actual_t->fd[0]);
				close(actual_t->fd[1]);
				data->actual_token = data->actual_token->next;
				exe_multiprocess(data);
			}
		}
	}
	else
		exe_closeprocess(data);
}