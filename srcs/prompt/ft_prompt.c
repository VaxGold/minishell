/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:14:23 by abello-r          #+#    #+#             */
/*   Updated: 2021/12/13 18:18:31 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/general.h"

void    ft_prompt(void)
{
    printf("\n\n");
    printf(YELLOW "     &\n");
    printf(" .-\"`\"-.\n");
    printf("/       \\\n");
    printf("|   __  _|\n");
    printf("|  /  \\`/ \\\n");
    printf("WW  \\_o/_o/\n");
    printf("(        _)\n");
    printf("|   .----\\\n");
    printf(";  | '----'"); printf(YELLOW "\tHello %s\n" NC, getenv("USER"));
    printf("\\__'--;`\n");
    printf("|___/\\|\n" NC);
    printf("\n\n\n");
}

// void    ft_prompt(void)
// {
//     printf("           _       _      _          _ _ \n");
//     printf("          (_)     (_)    | |        | | |\n");
//     printf(" _ __ ___  _ _ __  _  ___| |__   ___| | |\n");
//     printf("| '_ ` _ \\| | '_ \\| |/ __| '_ \\ / _ \\ | |\n");
//     printf("| | | | | | | | | | |\\__ \\ | | |  __/ | |\n");
//     printf("|_| |_| |_|_|_| |_|_||___/_| |_|\\___|_|_|\n\n\n");
// }