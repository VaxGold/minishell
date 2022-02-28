/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:30:37 by omercade          #+#    #+#             */
/*   Updated: 2022/02/22 18:49:08 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/builtins.h"
#include "../../includes/minishell.h"

int ft_array_len(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != NULL)
		i++;
	return (i);
}

int	ft_exit(t_ms *data)
{
	int		num;
	char	**args;

	num = 0;
	args = ((t_token *)(data->tokenst->content))->args;
	if (ft_array_len(args) == 1)
		{
			printf("exit");
			exit(0);
		}
//	else if (ft_array_len(args) == 2)
//	{
		while (args[1][num] != '\0')
			if (!ft_isdigit(args[1][num++])){
				printf("minishell: exit: %s: numeric argument required\n", args[1]);
				exit(-1);}
	if (ft_array_len(args) == 2)
{
		printf("exit");
		exit(ft_atoi(args[1]));
}
//	}
	else
		printf("minishell: exit: too many arguments\n");
	return (0);
}
/*
int	ft_exit(t_ms *data)
{
	printf("Soy ft_exit en el token: %s.\n", ((t_token *)(data->tokenst->content))->args[0]);
	return (0);
}*/