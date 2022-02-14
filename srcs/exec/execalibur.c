/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execalibur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:07:23 by omercade          #+#    #+#             */
/*   Updated: 2022/02/14 19:01:06 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//------>FUNCIONAL<------//
void	init_pipes(t_ms *this)			//Delete?
{
	t_list	*aux;
	int		i;

	i = 0;
	if (ft_lstsize(this->tokenst) < 2)
		return ;
	aux = this->tokenst;
	while (aux)
	{
		if (i != 0)
			pipe(((t_token *)aux)->fd);
		aux = aux->next;
		i++;
	}
}

// void	redir (t_list *elem_lst, char **env, int fdin)
// {
// 	t_token *token;

// 	token = (t_token *)(elem_lst->content);
// 	token->pid = fork();
// 	if (token->pid)
// 	{
// 		close(token->fd[1]);
// 		dup2(token->fd[0], STDIN);
// 		waitpid(token->pid, NULL, 0);
// 	}
// 	else
// 	{
// 		close(token->fd[0]);
// 		dup2(((t_token *)(elem_lst->next->content))->fd[1], STDOUT);
// 		if (fdin == STDIN)
// 			exit(1);
// 		else
// 			exe_process(token, env);
// 	}
// }

// void	execalibur(t_ms *this)
// {
// 	t_list *aux;

// 	init_pipes(this);
// 	aux = this->tokenst;
// 	// dup2(fdin, STDIN);
// 	// dup2(fdout, STDOUT);
// 	printf("FIRST_PROCES\n");
// 	redir(aux, this->env, 1);
// 	aux = aux->next;
// 	while (aux && aux->next)
// 	{
// 		printf("N_PROCES\n");
// 		redir(aux, this->env, 1);
// 		aux = aux->next;
// 	}
// 	if (aux)
// 	{
// 		printf("LAST_PROCES\n");
// 		exe_process((t_token *)(aux->content), this->env);
// 	}
// }

//------>TEST<------//
void	execalibur(t_ms *this)
{
	t_list	*aux;

	aux = this->tokenst;

	//==1ST PROCESS==//
	printf("FIRST PROCESS\n");
	if (aux->next)
	{
		pipe(((t_token *)(aux->next->content))->fd);
		//	↑ Done!				↓ Not finished...
		((t_token *)(aux->content))->pid = fork();
		//Check fork error!!
		if (!((t_token *)(aux->content))->pid)
		{
			dup2(((t_token *)(aux->next->content))->fd[1], STDOUT_FILENO);
			close(((t_token *)(aux->next->content))->fd[0]);
			close(((t_token *)(aux->next->content))->fd[1]);
			exe_process((t_token *)(aux->content), this->env);
		}
		else
			waitpid(((t_token *)(aux->content))->pid, NULL, 0);
		//	END EXE_OPEN_PROCESS
	}
	else
	{
		((t_token *)(aux->content))->pid = fork();
		if (!((t_token *)(aux->content))->pid)
			exe_process((t_token *)(aux->content), this->env);
		else
			waitpid(((t_token *)(aux->content))->pid, NULL, 0);
	}
	aux = aux->next;

	//==MULTI-PROCESS==//
	int i = 1;			//*Depuracion*
	while (aux && aux->next)
	{
		printf("MULTI-PROCESS #%d\n", i);
		pipe(((t_token *)(aux->next->content))->fd);
		//	↑ Done!				↓ Not finished...
		((t_token *)(aux->content))->pid = fork();
		if (!((t_token *)(aux->content))->pid)
			exe_process((t_token *)(aux->content), this->env);
		else
			waitpid(((t_token *)(aux->content))->pid, NULL, 0);
		//	END EXE_MULTI-PROCESS
		aux = aux->next;
		i++;			//*Depuracion*
	}

	//==LAST PROCESS==//
	if (aux)
	{
		printf("CLOSE PROCESS\n");
		//	↑ Done!				↓ Not finished...
		((t_token *)(aux->content))->pid = fork();
		//Check fork error!!
		if (!((t_token *)(aux->content))->pid)
		{
			dup2(((t_token *)(aux->content))->fd[0], STDIN_FILENO);
			close(((t_token *)(aux->content))->fd[1]);
			close(((t_token *)(aux->content))->fd[0]);
			exe_process((t_token *)(aux->content), this->env);
		}
		else
			waitpid(((t_token *)(aux->content))->pid, NULL, 0);
		//	END EXE_CLOSE_PROCESS
	}
}