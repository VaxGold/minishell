/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execalibur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:07:23 by omercade          #+#    #+#             */
/*   Updated: 2022/02/10 19:36:17 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*menu_builtins(void)
{
	void	(**menu)(t_ms *);

	menu = malloc(sizeof(*menu) * 8);
	menu[0] = &ft_cd;
	menu[1] = &ft_echo;
	menu[2] = &ft_env;
	menu[3] = &ft_export;
	menu[4] = &ft_pwd;
	menu[5] = &ft_unset;
	menu[6] = &ft_exit;
	menu[7] = (void *)0;
	return (menu);
}

int	search_builtins(t_token token)
{
	char	*cmd;

	cmd = token.args[0];	
	if (!ft_strcmp("cd\0", cmd))
		return (0);
	if (!ft_strcmp("echo\0", cmd))
		return (1);
	if (!ft_strcmp("env\0", cmd))
		return (2);
	if (!ft_strcmp("export\0", cmd))
		return (3);
	if (!ft_strcmp("pwd\0", cmd))
		return (4);
	if (!ft_strcmp("unset\0", cmd))
		return (5);
	if (!ft_strcmp("exit\0", cmd))
		return (6);
	return (-1);
}

void	execalibur(t_ms *this)
{
	t_list	*aux;
	int		opc;

	aux = this->tokenst;
	//opc = isbuiltin();
	if (opc == -1)		//command!!
	{
		pipe(((t_token *)(aux->content))->fd);
		((t_token *)(aux->content))->pid = fork();
		if (((t_token *)(aux->content))->pid < 0)
			exit(17);	//Revisar el error
		else if (((t_token *)(aux->content))->pid == 0)
			exe_process(((t_token *)(aux->content)), this->env);
		else
		{
			waitpid(((t_token *)(aux->content))->pid, &((t_token *)(aux->content))->status, 0);
			//check_err
		}
	}
	else
		//builtin!!
}

//FUNCIONAL

void	execalibur(t_ms *this)
{
	t_list	*aux;

	aux = this->tokenst;
	((t_token *)(aux->content))->pid = fork();
	if (((t_token *)(aux->content))->pid < 0)
		exit(17);	//Revisar el error
	else if (((t_token *)(aux->content))->pid == 0)
		exe_process(((t_token *)(aux->content)), this->env);
	else
	{
		waitpid(((t_token *)(aux->content))->pid, &((t_token *)(aux->content))->status, 0);
		//printf("Im are your father\n");
	}
}