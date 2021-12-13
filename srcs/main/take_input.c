/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:54:19 by omercade          #+#    #+#             */
/*   Updated: 2021/12/10 20:03:46 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/general.h"

void    take_input(char* str)
{
    char* buf;
  
    buf = readline("\n>>> ");
    if (strlen(buf) != 0)
    {
        add_history(buf);
        strcpy(str, buf);
        return ;
    }
}
