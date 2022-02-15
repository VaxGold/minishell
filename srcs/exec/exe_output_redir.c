/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_output_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <mangarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:30:55 by mangarci          #+#    #+#             */
/*   Updated: 2022/02/15 19:30:56 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		output_redir(t_list *out_lst)
{
	int			fd;
	t_redirect	*redir_data;

	fd = STDOUT_FILENO;
	while (fd != -1 && out_lst)
	{
		redir_data = out_lst->content;
		out_lst = out_lst->next;
		close(fd);
		fd = -1;
		if (redir_data->type == redir_out_append)
			fd = set_redir(redir_data->type, redir_data->simbol, STDOUT_FILENO);
		else if (redir_data->type == redir_out)
			fd = set_redir(redir_data->type, redir_data->simbol, STDOUT_FILENO);
	}
	return (fd);
}
