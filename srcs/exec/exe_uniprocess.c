/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_uniprocess.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:29:29 by omercade          #+#    #+#             */
/*   Updated: 2022/02/26 19:19:22 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	in_redirect(t_ms *data)
{
	int fd;
	t_token *token;

	token = ((t_token *)(data->actual_token->content));
	fd = exe_redirect(token->in, STDIN_FILENO);
	if (fd > 2)
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
}

static void	out_redirect(t_ms *data)
{
	int fd;
	t_token *token;

	token = ((t_token *)(data->actual_token->content));
	fd = exe_redirect(token->out, STDOUT_FILENO);
	if (fd > 2)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
}

void	exe_uniprocess(t_ms *data)
{
	t_token *token;

	token = ((t_token *)(data->actual_token->content));
	token->fd_out = exe_redirect(token->out, STDOUT_FILENO);
	if (token->fd_out != -2 && exe_builtin(data) == -1)
	{
		if (token->fd_out > 2)
			close(token->fd_out);
		token->pid = fork();
		if (token->pid == 0)
		{
			in_redirect(data);
			out_redirect(data);
			if (token->args)
				exe_process(token, data->env);	
			//SIGNAL
			exit(0);
		}
		else
		{
			//SIGNAL
		}
		waitpid(token->pid, NULL, 0);
	}
}