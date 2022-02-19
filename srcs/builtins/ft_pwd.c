/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:30:43 by omercade          #+#    #+#             */
/*   Updated: 2022/02/19 19:13:31 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

int	ft_get_pwd(char **arg, char **env)
{
	char	c[PATH_MAX];

	(void)arg;
	(void)env;
	if (getcwd(c, sizeof(c)) == NULL)
		return (1);
	printf("%s\n", c);
	return (0);
}
