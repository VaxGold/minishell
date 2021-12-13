/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 10:58:45 by abello-r          #+#    #+#             */
/*   Updated: 2021/12/10 20:30:41 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/general.h"

int	main(int argc, char **argv, char **envp)
{
	t_ms	this;
	char *data;

	(void) argc;
	(void) argv;
	(void) envp;

	ft_prompt();

	while (this.exit == 0)
	{
		data = readline(BLUE "Minishell:" WHITE" ");
		free(data);
	}
	return (0);
}
