/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 10:58:45 by abello-r          #+#    #+#             */
/*   Updated: 2021/11/19 20:28:59 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/general.h"

int	main(int argc, char **argv, char **envp)
{
	char *data;

	(void) argc;
	(void) argv;
	(void) envp;

	ft_prompt();

	while (1)
	{
		data = readline(BLUE "Minishell: ");
		free(data);
	}
	return (0);
}
