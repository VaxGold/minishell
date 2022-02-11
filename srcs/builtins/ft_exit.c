/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:30:37 by omercade          #+#    #+#             */
/*   Updated: 2022/02/11 17:57:10 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

int ft_array_len(char **cmd)
{
    int i;
    i = 0;
    while (cmd[i][0] != '\0')
        i++;
	printf("El retorno es %d\n", i);
    return (i);
}

int ft_exit(char **cmd)
{
    int num;

    num = 0;
    if (!cmd)
        return(!(printf("exit\n")));
    if (ft_array_len(cmd) == 1)
    {
        while (ft_isdigit(cmd[0][num]))
            num++;
        if (num == 0)
            return(!(!printf("minishell: exit: %s: numeric argument required\n", cmd[0])));
        else if (num > 0)
            return(ft_atoi(cmd[0]));
    }
    else
        return(!(!printf("minishell: exit: too many arguments\n")));
	return (0);
}
