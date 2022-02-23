/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_uniprocess.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:29:29 by omercade          #+#    #+#             */
/*   Updated: 2022/02/23 21:21:32 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exe_uniprocess(t_ms *data)
{
	t_token	*actual_t;
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
		if (!actual_t->pid)
		{
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
			waitpid(actual_t->pid, NULL, 0);
	}
}