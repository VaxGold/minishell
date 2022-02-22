/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:32:34 by omercade          #+#    #+#             */
/*   Updated: 2022/02/21 18:16:15 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			input_redir(t_list	*lst)
{
	int			fd_file;
	t_list		*aux;
	t_redirect	temp;

	aux = lst;
	while (aux)
	{
		temp = *((t_redirect *)(aux->content));
		if (ft_strncmp(temp.simbol, "<", ft_strlen(temp.simbol)))
			fd_file = open(temp.args[0], O_RDONLY);
		if (ft_strncmp(temp.simbol, "<<", ft_strlen(temp.simbol)))
			fd_file = open(temp.args[0], O_RDONLY);			//Heredoc BONUS!!
		aux = aux->next;
	}
	return (fd_file);
}

int			output_redir(t_list	*lst)
{
	int			fd_file;
	t_list		*aux;
	t_redirect	temp;

	aux = lst;
	while (aux)
	{
		temp = *((t_redirect *)(aux->content));
		if (ft_strncmp(temp.simbol, ">", ft_strlen(temp.simbol)))
			fd_file = open(temp.args[0], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (ft_strncmp(temp.simbol, ">>", ft_strlen(temp.simbol)))
			fd_file = open(temp.args[0], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		aux = aux->next;
	}
	return (fd_file);
}

t_exefiles	exe_redirect(t_list *lst_in, t_list *lst_out)
{
	t_exefiles	this;
	
	this.fd_infile = -2;
	this.fd_outfile = -2;
	if (lst_in)
		this.fd_infile = input_redir(lst_in);
	if (lst_out)
		this.fd_outfile = output_redir(lst_out);
	return (this);
}
