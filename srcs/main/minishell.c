/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:23:32 by omercade          #+#    #+#             */
/*   Updated: 2022/03/06 22:36:18 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <signal.h>

int	main(int narg, char **xarg, char **env)
{
	t_ms	this;
	char	*buf;

	(void)xarg;
	if (narg != 1)
		return (!printf("ARGS ERROR!!\n"));
	this.exit = 0;
	this.env = env;
	header();
	while (this.exit == 0)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, signal_handler);
		buf = readline(BLUE "minishell:/>" WHITE" ");
		if (!buf)
			exit(!printf("exit\n"));
		if (buf && *buf != '\0')
		{
        	add_history(buf);
			this.tokenst = babelfish(ft_strjoin(buf, "\0"), this.env);	//PARSER
			execalibur(&this);
			ft_lstclear(&this.tokenst, free_token);
		}
		free(buf);
	}
	/*FREES*/
	free_all(this);
	return (0);
}
