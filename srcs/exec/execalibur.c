/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execalibur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:07:23 by omercade          #+#    #+#             */
/*   Updated: 2022/02/16 19:56:23 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	close_process(t_list *token, char **env, t_list *tokenst)
{
	t_list	*aux;

	aux = tokenst;

	((t_token *)(token->content))->pid = fork();
	if (!((t_token *)(token->content))->pid)
	{
		dup2(((t_token *)(token->content))->fd[0], STDIN_FILENO);
		close(((t_token *)(token->content))->fd[0]);
		close(((t_token *)(token->content))->fd[1]);
		exe_process((t_token *)(token->content), env);
	}
	else
	{
		close(((t_token *)(token->content))->fd[0]);
		close(((t_token *)(token->content))->fd[1]);
	}

	while (aux)
	{
		int status;
		waitpid(((t_token *)(aux->content))->pid, &status, 0);
		aux = aux->next;
	}
}

void	multi_process(t_list *token, char **env, t_list *tokenst)
{
	if (token->next)
	{
		pipe(((t_token *)(token->next->content))->fd);
		((t_token *)(token->content))->pid = fork();
		if (!((t_token *)(token->content))->pid)
		{
			close(((t_token *)(token->content))->fd[1]);
			dup2(((t_token *)(token->content))->fd[0], STDIN_FILENO);
			close(((t_token *)(token->content))->fd[0]);
			dup2(((t_token *)(token->next->content))->fd[1], STDOUT_FILENO);
			close(((t_token *)(token->next->content))->fd[1]);
			close(((t_token *)(token->next->content))->fd[0]);
			exe_process((t_token *)(token->content), env);
		}
		else
		{
			close(((t_token *)(token->content))->fd[0]);
			close(((t_token *)(token->content))->fd[1]);
			multi_process(token->next, env, tokenst);
		}
	}
	else
		close_process(token, env, tokenst);
}

void	open_process(t_list *token, char **env, t_list *tokenst)
{
	pipe(((t_token *)(token->next->content))->fd);
	((t_token *)(token->content))->pid = fork();
	if (!((t_token *)(token->content))->pid)
	{
		close(((t_token *)(token->next->content))->fd[0]);
		dup2(((t_token *)(token->next->content))->fd[1], STDOUT_FILENO);
		close(((t_token *)(token->next->content))->fd[1]);
		exe_process((t_token *)(token->content), env);
	}
	else
		multi_process(token->next, env, tokenst);
}



void	execalibur(t_ms *this)
{
	t_list	*aux;

	aux = this->tokenst;
	if (aux->next)
		open_process(aux, this->env, this->tokenst);
	else
	{
		((t_token *)(aux->content))->pid = fork();
		if (!((t_token *)(aux->content))->pid)
			exe_process((t_token *)(aux->content), this->env);
		else
			waitpid(((t_token *)(aux->content))->pid, NULL, 0);
	}
}


