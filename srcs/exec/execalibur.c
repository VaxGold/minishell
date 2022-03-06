/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execalibur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:07:23 by omercade          #+#    #+#             */
/*   Updated: 2022/03/06 23:42:09 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	in_redirect(t_ms *data)
{
	int		fd;
	t_token	*token;

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
	int		fd;
	t_token	*token;

	token = ((t_token *)(data->actual_token->content));
	fd = exe_redirect(token->out, STDOUT_FILENO);
	if (fd > 2)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
}

static void	exe_offspring(t_ms *data)
{
	t_token	*token;

	token = ((t_token *)(data->actual_token->content));
	in_redirect(data);
	out_redirect(data);
	if (token->args)
		exe_process(token, data->env);
	exit(0);
}

void	execalibur(t_ms *data)
{
	t_token	*token;

	if (!data->tokenst || !((t_token *)(data->tokenst->content))->args)
		return ;
	data->actual_token = data->tokenst;
	if (!data->actual_token->next)
	{
		token = ((t_token *)(data->actual_token->content));
		token->fd_out = exe_redirect(token->out, STDOUT_FILENO);
		if (token->fd_out != -2 && exe_builtin(data) == -1)
		{
			signal(SIGINT, signal_handler_child);
			signal(SIGQUIT, signal_handler_child);
			token->pid = fork();
			if (token->pid == 0)
				exe_offspring(data);
			waitpid(token->pid, NULL, 0);
		}
	}
	else
		exe_openprocess(data);
}
