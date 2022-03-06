/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:32:34 by omercade          #+#    #+#             */
/*   Updated: 2022/03/06 19:26:13 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exe_redir_checkdir(char *arg, int *fd)
{
	DIR	*dir;

	dir = opendir(arg);
	if (dir)
	{
		closedir(dir);
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(arg, 2);
		ft_putendl_fd(": Is a directory", 2);
		return (-2);
	}
	*fd = open(arg, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, S_IRWXU);
	return (0);
}

int	exe_redir_heredoc(char *arg)
{
	char		*tmp;
	int			fd;

	fd = open(".tmp", O_RDWR | O_CREAT | O_TRUNC | O_APPEND, S_IRWXU);
	tmp = readline(BLUE" > "WHITE);
	rl_redisplay();
	if (ft_strcmp(tmp, arg))
		ft_putendl_fd(tmp, fd);
	while (ft_strcmp(tmp, arg))
	{
		free(tmp);
		tmp = readline(BLUE" > "WHITE);
		rl_redisplay();
		if (ft_strcmp(tmp, arg))
			ft_putendl_fd(tmp, fd);
	}
	free(tmp);
	ft_putstr_fd(WHITE"", STDOUT_FILENO);
	close(fd);
	return (open(".tmp", O_RDONLY));
}

int	exe_redirect(t_list *lst, int origin)
{
	int			fd;
	t_list		*aux;
	t_redirect	temp;

	if (!lst)
		return (origin);
	aux = lst;
	while (aux)
	{
		temp = *((t_redirect *)(aux->content));
		if (!temp.args || ft_arrlen(temp.args) != 1)
		{
			ft_putstr_fd("minishell: ambiguous redirect\n", 2);
			return (-2);
		}
		if (!ft_strcmp(temp.simbol, ">\0"))
		{
			if (exe_redir_checkdir(temp.args[0], &fd) == -2)
				return (-2);
		}
		else if (!ft_strcmp(temp.simbol, ">>\0"))
			fd = open(temp.args[0], O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);
		else if (!ft_strcmp(temp.simbol, "<\0"))
			fd = open(temp.args[0], O_RDONLY);
		else if (!ft_strcmp(temp.simbol, "<<\0"))
			fd = exe_redir_heredoc(temp.args[0]);
		aux = aux->next;
		if (aux)
			close(fd);
	}
	return (fd);
}
