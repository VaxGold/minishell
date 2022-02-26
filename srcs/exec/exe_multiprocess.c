/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_multiprocess.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:29:59 by omercade          #+#    #+#             */
/*   Updated: 2022/02/26 19:53:57 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// void	exe_multiprocess(t_ms *data)
// {
// 	t_token	*actual_t;
// 	t_token	*next_t;
// 	int		opt;
// 	int		fd_file;
// 	int		(**menu)(t_ms *);

// 	menu = exe_menu();
// 	actual_t = (t_token *)(data->actual_token->content);
// 	next_t = (t_token *)(data->actual_token->next->content);
// 	if (data->actual_token->next)
// 	{
		
// 		pipe(next_t->fd);
// 		opt = exe_opt(actual_t->args[0]);
// 		if (opt != -1)
// 		{
// 			if (actual_t->in)
// 				exe_redirect(actual_t->in, data->fd_in);
// 			if (actual_t->out)
// 				data->fd_out = exe_redirect(actual_t->out, data->fd_out);
// 			menu[opt](data);
// 			data->actual_token = data->actual_token->next;
// 			exe_multiprocess(data);
// 		}
// 		else
// 		{
// 			actual_t->pid = fork();
// 			if (!actual_t->pid)
// 			{
// 				close(actual_t->fd[1]);
// 				dup2(actual_t->fd[0], STDIN_FILENO);
// 				close(actual_t->fd[0]);
// 				dup2(next_t->fd[1], STDOUT_FILENO);
// 				close(next_t->fd[1]);
// 				close(next_t->fd[0]);
// 				if (actual_t->in)
// 				{
// 					fd_file = exe_redirect(actual_t->in, data->fd_in);
// 					dup2(fd_file, STDIN_FILENO);
// 					close(fd_file);
// 				}
// 				if (actual_t->out)
// 				{
// 					fd_file = exe_redirect(actual_t->out, data->fd_out);
// 					dup2(fd_file, STDOUT_FILENO);
// 					close(fd_file);
// 				}
// 				exe_process(actual_t, data->env);
// 			}
// 			else
// 			{
// 				close(actual_t->fd[0]);
// 				close(actual_t->fd[1]);
// 				data->actual_token = data->actual_token->next;
// 				exe_multiprocess(data);
// 			}
// 		}
// 	}
// 	else
// 		exe_closeprocess(data);
// }

static void	close_fd(t_ms *data)
{
	t_token	*actual_t;
	t_token	*next_t;

	actual_t = (t_token *)(data->actual_token->content);
	next_t	= (t_token *)(data->actual_token->next->content);
	close(actual_t->fd[0]);
	close(next_t->fd[1]);
}

static void	in_redirect(t_ms *data)
{
	int	fd;
	t_token	*actual_t;
	t_token	*next_t;

	actual_t = (t_token *)(data->actual_token->content);
	next_t	= (t_token *)(data->actual_token->next->content);
	fd = exe_redirect(actual_t->in, STDIN_FILENO);
	if (fd == -1)
		exit(-1);
	else if (fd > 0)
	{
		close(actual_t->fd[0]);
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	else
	{
		dup2(actual_t->fd[0], STDIN_FILENO);
		close(actual_t->fd[0]);
	}
}

static void	out_redirect(t_ms *data)
{
	int	fd;
	t_token	*actual_t;
	t_token	*next_t;

	actual_t = (t_token *)(data->actual_token->content);
	next_t	= (t_token *)(data->actual_token->next->content);
	fd = exe_redirect(((t_token *)(data->actual_token->content))->out, STDOUT_FILENO);
	if (fd == -1)
		exit(-1);
	else if (fd > 0)
	{
		dup2(next_t->fd[1], STDOUT_FILENO);
		close(next_t->fd[1]);
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	else
	{
		dup2(next_t->fd[1], STDOUT_FILENO);
		close(next_t->fd[1]);
	}
}

void	exe_multiprocess(t_ms *data)
{
	t_token	*actual_t;
	t_token	*next_t;

	if (data->actual_token->next)
	{
		actual_t = (t_token *)(data->actual_token->content);
		next_t	= (t_token *)(data->actual_token->next->content);
		pipe(next_t->fd);
		actual_t->pid = fork();
		if (actual_t->pid == 0)
		{
			actual_t->fd_out = exe_redirect(actual_t->out, STDOUT_FILENO);
			close(next_t->fd[0]);
			in_redirect(data);
			out_redirect(data);
			if (actual_t->fd_out != -2 && exe_builtin(data) == -1)
			{
				if (!actual_t->args)
					exe_process(actual_t, data->env);
				//signals
			}
			exit(0);
		}
		else
		{
			close_fd(data);
			data->actual_token = data->actual_token->next;
			exe_multiprocess(data);
		}
	}
	else
		exe_closeprocess(data);
}