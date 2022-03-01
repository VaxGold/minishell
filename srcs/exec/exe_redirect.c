/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:32:34 by omercade          #+#    #+#             */
/*   Updated: 2022/02/28 20:50:30 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
