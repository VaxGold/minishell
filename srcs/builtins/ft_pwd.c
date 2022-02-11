/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:30:43 by omercade          #+#    #+#             */
/*   Updated: 2022/02/11 15:57:01 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

int	ft_pwd(void)
{
	char	*cwd;

	cwd = malloc(PATH_MAX);
	if (!cwd)
		return (1);
	if (getcwd(cwd, PATH_MAX))
	{
		ft_putendl_fd(cwd, 1);
		return (0);
	}
	else
		return (1);
}

// void printDir()
// {
//     char cwd[1024];
//     getcwd(cwd, sizeof(cwd));
//     printf("\nDir: %s", cwd);
// }
