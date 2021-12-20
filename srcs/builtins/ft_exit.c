/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:30:37 by omercade          #+#    #+#             */
/*   Updated: 2021/12/20 20:01:55 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
