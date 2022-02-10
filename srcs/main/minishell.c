/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:23:32 by omercade          #+#    #+#             */
/*   Updated: 2022/02/10 17:23:22 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	main(int narg, char **xarg, char **env)
{
	t_ms	this;
	char	*buf;


	//(void) narg;
	(void) xarg;
	//(void) env;		//DELETE!
	if (narg != 1)
		return (!printf("ARGS ERROR!!\n"));
	/*INITIALIZE*/
	this.exit = 0;
	this.in = dup(STDIN);
	this.out = dup(STDOUT);
	this.env = env;
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
			this.exit = 1;	//pruebas
		}
		this.tokenst = babelfish(ft_strjoin(buf, "\0"), env);		//PARSER
		execalibur(&this);
		free(buf);
	}
	/*FREES*/
	return (0);
}