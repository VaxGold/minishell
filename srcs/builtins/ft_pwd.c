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

int	ft_get_pwd(t_ms *data)
{
	char	c[PATH_MAX];

	(void)data;
	if (getcwd(c, sizeof(c)) == NULL)
		return (1);
	printf("%s\n", c);
	return (0);
}

int	ft_pwd(t_ms *data)
{
	ft_get_pwd(data);
	return (0);
}