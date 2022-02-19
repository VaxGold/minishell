/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_input_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:58:26 by adiaz-do          #+#    #+#             */
/*   Updated: 2022/02/17 20:58:28 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		input_redir(t_list *in_lst, char *heredoc_file)
{
	int			fd;
	t_redirect	*redir_data;

	fd = STDIN_FILENO;
	while (fd != -1 && in_lst)
	{
		close(fd);
		redir_data = in_lst->content;
		in_lst = in_lst->next;
		if (!in_lst && redir_data->type == here_doc)
			fd = set_redir(redir_data->type, heredoc_file, STDIN_FILENO);
		else if (redir_data->type == redir_in)
			fd = set_redir(redir_data->type, redir_data->args, STDIN_FILENO);
	}
}
