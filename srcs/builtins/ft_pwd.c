/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:30:43 by omercade          #+#    #+#             */
/*   Updated: 2022/02/22 18:49:22 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/builtins.h"
#include "../../includes/minishell.h"

// int	ft_get_pwd(char **arg, char **env)
// {
// 	char	c[PATH_MAX];

// 	*arg = 0;
// 	*env = 0;
// 	if (getcwd(c, sizeof(c)) == NULL)
// 		return (1);
// 	printf("%s\n", c);
// 	return (0);
// }

int	ft_pwd(t_ms *data)
{
	printf("Soy ft_pwd en el token: %s.\n", ((t_token *)(data->tokenst->content))->args[0]);
	return (0);
}