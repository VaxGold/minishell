/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:29:59 by omercade          #+#    #+#             */
/*   Updated: 2022/02/22 18:48:55 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/builtins.h"
#include "../../includes/minishell.h"

// int	ft_env(char **args, char **env)
// {
// 	int	i;
// 	*args = 0;
	
// 	i = 0;
// 	while (env[i])
// 		printf("%s\n", env[i++]);
// 	return (0);
// }


int	ft_env(t_ms *data)
{
	printf("Soy ft_env en el token: %s.\n", ((t_token *)(data->tokenst->content))->args[0]);
	return (0);
}