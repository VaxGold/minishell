/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:32:34 by omercade          #+#    #+#             */
/*   Updated: 2022/02/25 17:52:42 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// int			input_redir(t_list	*lst)
// {
// 	int			fd_file;
// 	t_list		*aux;
// 	t_redirect	temp;

// 	aux = lst;
// 	while (aux)
// 	{
// 		temp = *((t_redirect *)(aux->content));
// 		if (ft_strcmp(temp.simbol, "<\0"))
// 			fd_file = open(temp.args[0], O_RDONLY);
// 		if (ft_strcmp(temp.simbol, "<<\0"))
// 			fd_file = open(temp.args[0], O_RDONLY);			//Heredoc BONUS!!
// 		aux = aux->next;
// 		if (aux)
// 			close(fd_file);
// 	}
// 	return (fd_file);
// }

// int			output_redir(t_list	*lst)
// {
// 	int			fd_file;
// 	t_list		*aux;
// 	t_redirect	temp;

// 	aux = lst;
// 	while (aux)
// 	{
// 		temp = *((t_redirect *)(aux->content));
// 		if (!ft_strcmp(temp.simbol, ">\0"))			//Comprobar que no sea directorio
// 			fd_file = open(temp.args[0], O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, S_IRWXU);
// 		else if (ft_strcmp(temp.simbol, ">>\0"))
// 			fd_file = open(temp.args[0], O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);
// 		aux = aux->next;
// 		if (aux)
// 			close(fd_file);
// 	}
// 	return (fd_file);
// }

// t_exefiles	exe_redirect(t_list *lst_in, t_list *lst_out)
// {
// 	t_exefiles	this;
	
// 	this.fd_infile = -2;
// 	this.fd_outfile = -2;
// 	if (lst_in)
// 		this.fd_infile = input_redir(lst_in);
// 	if (lst_out)
// 		this.fd_outfile = output_redir(lst_out);
// 	return (this);
// }

int	exe_redirect(t_list *lst, int origin)
{
	int			fd;
	t_list		*aux;
	t_redirect	temp;

	if (!lst)
		return (origin);
	// if (ft_arrlen(((t_redirect *)(lst->content))->args) != 1)
	// 	return (-2);
	aux = lst;
	while (aux)
	{
		temp = *((t_redirect *)(aux->content));
		if (!ft_strcmp(temp.simbol, ">\0"))			//Comprobar que no sea directorio
			fd = open(temp.args[0], O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, S_IRWXU);
		else if (!ft_strcmp(temp.simbol, ">>\0"))
			fd = open(temp.args[0], O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);
		else if (!ft_strcmp(temp.simbol, "<\0"))
			fd = open(temp.args[0], O_RDONLY);
		else if (!ft_strcmp(temp.simbol, "<<\0"))
			fd = open(temp.args[0], O_RDONLY);			//Heredoc BONUS!!	
		aux = aux->next;
		if (aux)
			close(fd);	
	}
	return (fd);
}
