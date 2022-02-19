/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:30:37 by omercade          #+#    #+#             */
/*   Updated: 2022/02/19 20:07:58 by adiaz-do         ###   ########.fr       */
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

int ft_exit(char **args, char **env)
{
    int num;

    *env = 0;
    num = 0;
    if  (!args)
        return(!(printf("exit\n")));
    if  (ft_array_len(args) == 1)
    {
        while (ft_isdigit(args[0][num]))
            num++;
        if (num == 0)
            return(!(!printf("minishell: exit: %s: numeric argument required\n", args[0])));
        else if (num > 0)
            return(ft_atoi(args[0]));
    }
    else
        return(!(!printf("minishell: exit: too many arguments\n")));
	return (0);
}
