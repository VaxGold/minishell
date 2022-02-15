/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <mangarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:42:14 by mangarci          #+#    #+#             */
/*   Updated: 2022/02/15 19:42:15 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		get_redir_type(t_list *token, t_redir_type *type)
{
	t_list	*aux;

	aux = token;
	*type = none;
	if (ft_lstsize(((t_token *)aux)->in) > 1)
	{
		*type = here_doc;
		return (2);
	}
	else if (ft_lstsize(((t_token *)aux)->in) > 0)
	{
		*type = redir_in;
		return (1);
	}
	if (ft_lstsize(((t_token *)aux)->out) > 1)
	{
		*type = redir_out_append;
		return (2);
	}
	else if (ft_lstsize(((t_token *)aux)->out) > 0)
	{
		*type = redir_out;
		return (1);
	}
	return (0);
}

int		set_redir(t_redir_type type, char *file, int dest)
{
	int		fd;

	fd = -1;
	if (type == redir_in || type == here_doc)
		fd = open(file, O_RDONLY);
	else if (type == redir_out)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (type == redir_out_append)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	/*if (fd == -1 || dup2(fd, dest) == -1)
	{
		perror(file);
		return (-1);
	} */
	return (fd);
}
