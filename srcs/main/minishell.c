/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:23:32 by omercade          #+#    #+#             */
/*   Updated: 2022/02/19 19:30:51 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <signal.h>

void	rl_replace_line(const char *str, int n);

int		g_exit_status;

void	signal_handler(int signum)
{
	//g_exit_status += sig;
	if (signum == SIGINT)
	{
		//g_exit_status = 130;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (signum == SIGQUIT)
	{
		write(2, "Exit\n", 5);
		exit (0);
	}
}

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
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	//reset_fds
	//set_env & set_secret_env
	/*END_INIT*/
	header();
	while (this.exit == 0)
	{
		buf = readline(BLUE "minishell:/>" WHITE" ");
		if (buf)
		{
        	add_history(buf);
			this.tokenst = babelfish(ft_strjoin(buf, "\0"), this.env);	//PARSER
			execalibur(&this);
		}
		free(buf);
	}
	/*FREES*/
	return (0);
}
