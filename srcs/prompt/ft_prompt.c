/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:14:23 by abello-r          #+#    #+#             */
/*   Updated: 2021/11/19 20:31:26 by abello-r         ###   ########.fr       */
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
