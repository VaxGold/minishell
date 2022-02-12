/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execalibur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:07:23 by omercade          #+#    #+#             */
/*   Updated: 2022/02/12 18:21:00 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//TEST
void	exe_pipeset(t_ms *this)
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

// void	exe_cmd(t_list	*elem_lst, char **env, int fdin, int fdout)
// {
// 	t_token	*token;

// 	token = (t_token *)(elem_lst->content);
// 	token->pid = fork();
// 	if (token->pid)
// 	{
		
// 	}
// 	else
// 	{
		
// 	}
// }

void	redir (t_list *elem_lst, char **env, int fdin)
{
	t_token *token;

	token = (t_token *)(elem_lst->content);
	token->pid = fork();
	if (token->pid)
	{
		close(token->fd[1]);
		dup2(token->fd[0], STDIN);
		waitpid(token->pid, NULL, 0);
	}
	else
	{
		close(token->fd[0]);
		dup2(((t_token *)(elem_lst->next->content))->fd[1], STDOUT);
		if (fdin == STDIN)
			exit(1);
		else
			exe_process(token, env);
	}
}

void	execalibur(t_ms *this)
{
	t_list *aux;

	exe_pipeset(this);
	aux = this->tokenst;
	// dup2(fdin, STDIN);
	// dup2(fdout, STDOUT);
	printf("FIRST_PROCES\n");
	redir(aux, this->env, 1);
	aux = aux->next;
	while (aux && aux->next)
	{
		printf("N_PROCES\n");
		redir(aux, this->env, 1);
		aux = aux->next;
	}
	if (aux)
	{
		printf("LAST_PROCES\n");
		exe_process((t_token *)(aux->content), this->env);
	}
}

//FUNCIONAL
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

// 	exe_pipeset(this);
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