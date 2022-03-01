/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:23:32 by omercade          #+#    #+#             */
/*   Updated: 2022/02/28 20:50:34 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		g_exit_status;

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
	//g_exit_status = 0;
	this.exit = 0;
	this.env = env;
	//signal(SIGINT, signal_handler);
	//signal(SIGQUIT, SIG_IGN);
	//reset_fds
	//set_env & set_secret_env
	/*END_INIT*/
	header();
	while (this.exit == 0)
	{
		buf = readline(BLUE "minishell:/>" WHITE" ");
		if (ft_strlen(buf) != 0)
		{
        	add_history(buf);
			//signal(SIGINT, signal_handler);
			//signal(SIGQUIT, SIG_IGN);
			this.tokenst = babelfish(ft_strjoin(buf, "\0"), this.env);		//PARSER
			execalibur(&this);
		}
		else
		{
			this.exit = 1;	
		}
		//**SALIDA PARA PRUEBAS**//
		free(buf);
	}
	/*FREES*/
	return (0);
}
