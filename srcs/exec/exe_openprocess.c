/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_openprocess.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:29:46 by omercade          #+#    #+#             */
/*   Updated: 2022/02/23 20:27:43 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exe_openprocess(t_ms *data)
{
	t_token	*actual_t;
	t_token	*next_t;
	int		opt;
	int		fd_file;
	int		(**menu)(t_ms *);

	menu = exe_menu();
	actual_t = (t_token *)(data->actual_token->content);
	next_t = (t_token *)(data->actual_token->next->content);
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
			close(next_t->fd[0]);
			dup2(next_t->fd[1], STDOUT_FILENO);
			close(next_t->fd[1]);
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
			data->actual_token = data->actual_token->next;
			exe_multiprocess(data);
		}
	}
}
