/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:23:32 by omercade          #+#    #+#             */
/*   Updated: 2021/12/13 20:44:55 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	main(int narg, char **xarg, char **env)
{
	t_ms	this;
	char	*buf;

	//(void) narg;
	(void) xarg;
	(void) env;		//DELETE!
	if (narg != 1)
		return (!printf(ARG));
	/*INITIALIZE*/
	this.exit = 0;
	this.in = dup(STDIN);
	this.out = dup(STDOUT);
	//reset_fds
	//set_env & set_secret_env
	/*END_INIT*/
	header();
	while (this.exit == 0)
	{
		buf = readline(BLUE "minishell:/>" WHITE" ");
		if (strlen(buf) != 0)
        	add_history(buf);
		else
				//pruebas
		//babelf(buff);		//Parser
		free(buf);
	}
	/*FREES*/
	return (0);
}