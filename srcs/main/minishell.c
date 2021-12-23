/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:23:32 by omercade          #+#    #+#             */
/*   Updated: 2021/12/20 20:56:45 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	main(int narg, char **xarg, char **env)
{
	t_ms	this;
	char	*buf;
	char	**test;

	char	*num = "5";

	test = malloc(sizeof(char *) * 2);
	test[0] = num;
	test[1] = "\0";
	//(void) narg;
	(void) xarg;
	(void) env;		//DELETE!
	if (narg != 1)
		return (!printf("ARGS ERROR!!\n"));
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
		{
			this.exit = ft_exit(test);	//pruebas
		}
		//this.ftoken = babelf(buff);		//Parser
		free(buf);
	}
	/*FREES*/
	return (0);
}