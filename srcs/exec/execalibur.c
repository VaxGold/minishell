/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execalibur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:07:23 by omercade          #+#    #+#             */
/*   Updated: 2022/02/15 20:19:53 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//------>FUNCIONAL<------//
// void	execalibur(t_ms *this)
// {
// 	t_list	*aux;

// 	aux = this->tokenst;

// 	//==1ST PROCESS==//
// 	printf("FIRST PROCESS\n");
// 	if (aux->next)
// 	{
// 		pipe(((t_token *)(aux->next->content))->fd);
// 		//	↑ Done!				↓ Not finished...
// 		((t_token *)(aux->content))->pid = fork();
// 		//Check fork error!!
// 		if (!((t_token *)(aux->content))->pid)
// 		{
// 			close(((t_token *)(aux->next->content))->fd[0]);
// 			dup2(((t_token *)(aux->next->content))->fd[1], STDOUT_FILENO);
// 			close(((t_token *)(aux->next->content))->fd[1]);
// 			exe_process((t_token *)(aux->content), this->env);
// 		}
// 		else
// 		{
// 			close(((t_token *)(aux->next->content))->fd[0]);
// 			close(((t_token *)(aux->next->content))->fd[1]);
// 			waitpid(((t_token *)(aux->content))->pid, NULL, 0);
// 		}
// 		//	END EXE_OPEN_PROCESS
// 	}
// 	else
// 	{
// 		((t_token *)(aux->content))->pid = fork();
// 		if (!((t_token *)(aux->content))->pid)
// 			exe_process((t_token *)(aux->content), this->env);
// 		else
// 			waitpid(((t_token *)(aux->content))->pid, NULL, 0);
// 	}
// 	aux = aux->next;

// 	//==MULTI-PROCESS==//
// 	int i = 1;			/*Depuracion*/
// 	while (aux && aux->next)
// 	{
// 		printf("MULTI-PROCESS #%d\n", i);
// 		pipe(((t_token *)(aux->next->content))->fd);
// 		//	↑ Done!				↓ Not finished...
// 		((t_token *)(aux->content))->pid = fork();
// 		if (!((t_token *)(aux->content))->pid)
// 		{
// 			close(((t_token *)(aux->content))->fd[1]);
// 			close(((t_token *)(aux->next->content))->fd[0]);
// 			dup2(((t_token *)(aux->next->content))->fd[1], STDOUT_FILENO);
// 			close(((t_token *)(aux->next->content))->fd[1]);
// 			dup2(((t_token *)(aux->content))->fd[0], STDIN_FILENO);
// 			close(((t_token *)(aux->content))->fd[0]);
// 			exe_process((t_token *)(aux->content), this->env);
// 		}
// 		else
// 		{
// 			close(((t_token *)(aux->next->content))->fd[0]);
// 			close(((t_token *)(aux->next->content))->fd[1]);
// 			close(((t_token *)(aux->content))->fd[1]);
// 			close(((t_token *)(aux->content))->fd[0]);
// 			waitpid(((t_token *)(aux->content))->pid, NULL, 0);
// 		}
// 		//	END EXE_MULTI-PROCESS
// 		aux = aux->next;
// 		i++;			/*Depuracion*/
// 	}

// 	//==LAST PROCESS==//
// 	if (aux)
// 	{
// 		printf("CLOSE PROCESS\n");
// 		//	↑ Done!				↓ Not finished...
// 		((t_token *)(aux->content))->pid = fork();
// 		//Check fork error!!
// 		if (!((t_token *)(aux->content))->pid)
// 		{
// 			close(((t_token *)(aux->content))->fd[1]);
// 			dup2(((t_token *)(aux->content))->fd[0], STDIN_FILENO);
// 			close(((t_token *)(aux->content))->fd[0]);
// 			exe_process((t_token *)(aux->content), this->env);
// 		}
// 		else
// 		{
// 			close(((t_token *)(aux->content))->fd[0]);
// 			close(((t_token *)(aux->content))->fd[1]);
// 			waitpid(((t_token *)(aux->content))->pid, NULL, 0);
// 		}
// 		//	END EXE_CLOSE_PROCESS
// 	}
// }


//------>TEST<------//
void	close_process(t_list *token, char **env)
{
	if (!token)
		printf("A!\n");
	((t_token *)(token->content))->pid = fork();
	if (!((t_token *)(token->content))->pid)
	{
		close(((t_token *)(token->content))->fd[1]);
		dup2(((t_token *)(token->content))->fd[0], STDIN_FILENO);
		close(((t_token *)(token->content))->fd[0]);
		exe_process((t_token *)(token->content), env);
	}
	else
	{
		close(((t_token *)(token->content))->fd[1]);
		close(((t_token *)(token->content))->fd[0]);
		//waitpid(((t_token *)(token->content))->pid, NULL, 0);
	}
}

void	multi_process(t_list *token, char **env)
{
	if (token->next)
	{
		pipe(((t_token *)(token->next->content))->fd);
		((t_token *)(token->content))->pid = fork();
		if (!((t_token *)(token->content))->pid)
		{
			close(((t_token *)(token->content))->fd[1]);
			close(((t_token *)(token->next->content))->fd[0]);
			dup2(((t_token *)(token->next->content))->fd[1], STDOUT_FILENO);
			close(((t_token *)(token->next->content))->fd[1]);
			dup2(((t_token *)(token->content))->fd[0], STDIN_FILENO);
			close(((t_token *)(token->content))->fd[0]);
			exe_process((t_token *)(token->content), env);
		}
		else
		{
			close(((t_token *)(token->content))->fd[1]);
			close(((t_token *)(token->next->content))->fd[0]);
			close(((t_token *)(token->next->content))->fd[1]);
			close(((t_token *)(token->content))->fd[0]);
			multi_process(token->next, env);
			//waitpid(((t_token *)(token->content))->pid, NULL, 0);
		}
	}
	else
		close_process(token, env);
}

void	open_process(t_list *token, char **env)
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
	{
		close(((t_token *)(token->next->content))->fd[0]);
		close(((t_token *)(token->next->content))->fd[1]);
		multi_process(token->next, env);
		while (token)
		{
			waitpid(((t_token *)(token->content))->pid, NULL, 0);
			token = token->next;
		}
	}
}

void	execalibur(t_ms *this)
{
	t_list	*aux;

	aux = this->tokenst;
	if (aux->next)
		open_process(aux, this->env);
	else
	{
		((t_token *)(aux->content))->pid = fork();
		if (!((t_token *)(aux->content))->pid)
			exe_process((t_token *)(aux->content), this->env);
		else
			waitpid(((t_token *)(aux->content))->pid, NULL, 0);
	}
}

// void	execalibur(t_ms *this)
// {
// 	t_list	*aux;

// 	aux = this->tokenst;

// 	//==1ST PROCESS==//
// 	printf("FIRST PROCESS\n");
// 	if (aux->next)
// 	{
// 		pipe(((t_token *)(aux->next->content))->fd);
// 		//	↑ Done!				↓ Not finished...
// 		((t_token *)(aux->content))->pid = fork();
// 		//Check fork error!!
// 		if (!((t_token *)(aux->content))->pid)
// 		{
// 			close(((t_token *)(aux->next->content))->fd[0]);
// 			dup2(((t_token *)(aux->next->content))->fd[1], STDOUT_FILENO);
// 			close(((t_token *)(aux->next->content))->fd[1]);
// 			exe_process((t_token *)(aux->content), this->env);
// 		}
// 		else
// 		{
// 			close(((t_token *)(aux->next->content))->fd[0]);
// 			close(((t_token *)(aux->next->content))->fd[1]);
// 			waitpid(((t_token *)(aux->content))->pid, NULL, 0);
// 		}
// 		//	END EXE_OPEN_PROCESS
// 	}
// 	else
// 	{
// 		((t_token *)(aux->content))->pid = fork();
// 		if (!((t_token *)(aux->content))->pid)
// 			exe_process((t_token *)(aux->content), this->env);
// 		else
// 			waitpid(((t_token *)(aux->content))->pid, NULL, 0);
// 	}
// 	aux = aux->next;

// 	//==MULTI-PROCESS==//
// 	int i = 1;			/*Depuracion*/
// 	while (aux && aux->next)
// 	{
// 		printf("MULTI-PROCESS #%d\n", i);
// 		pipe(((t_token *)(aux->next->content))->fd);
// 		//	↑ Done!				↓ Not finished...
// 		((t_token *)(aux->content))->pid = fork();
// 		if (!((t_token *)(aux->content))->pid)
// 		{
// 			close(((t_token *)(aux->content))->fd[1]);
// 			close(((t_token *)(aux->next->content))->fd[0]);
// 			dup2(((t_token *)(aux->next->content))->fd[1], STDOUT_FILENO);
// 			close(((t_token *)(aux->next->content))->fd[1]);
// 			dup2(((t_token *)(aux->content))->fd[0], STDIN_FILENO);
// 			close(((t_token *)(aux->content))->fd[0]);
// 			exe_process((t_token *)(aux->content), this->env);
// 		}
// 		else
// 		{
// 			close(((t_token *)(aux->next->content))->fd[0]);
// 			close(((t_token *)(aux->next->content))->fd[1]);
// 			close(((t_token *)(aux->content))->fd[1]);
// 			close(((t_token *)(aux->content))->fd[0]);
// 			waitpid(((t_token *)(aux->content))->pid, NULL, 0);
// 		}
// 		//	END EXE_MULTI-PROCESS
// 		aux = aux->next;
// 		i++;			/*Depuracion*/
// 	}

// 	//==LAST PROCESS==//
// 	if (aux)
// 	{
// 		printf("CLOSE PROCESS\n");
// 		//	↑ Done!				↓ Not finished...
// 		((t_token *)(aux->content))->pid = fork();
// 		//Check fork error!!
// 		if (!((t_token *)(aux->content))->pid)
// 		{
// 			close(((t_token *)(aux->content))->fd[1]);
// 			dup2(((t_token *)(aux->content))->fd[0], STDIN_FILENO);
// 			close(((t_token *)(aux->content))->fd[0]);
// 			exe_process((t_token *)(aux->content), this->env);
// 		}
// 		else
// 		{
// 			close(((t_token *)(aux->content))->fd[0]);
// 			close(((t_token *)(aux->content))->fd[1]);
// 			waitpid(((t_token *)(aux->content))->pid, NULL, 0);
// 		}
// 		//	END EXE_CLOSE_PROCESS
// 	}
// }