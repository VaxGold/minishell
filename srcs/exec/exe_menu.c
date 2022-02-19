/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:58:19 by omercade          #+#    #+#             */
/*   Updated: 2022/02/19 19:30:39 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*exe_menu(void)
{
	int	(**menu)(char **, char **);

	menu = malloc(sizeof(*menu) * 8);
	menu[0] = &ft_cd;
	menu[1] = &ft_echo;
	menu[2] = &ft_env;
	menu[3] = &ft_export;
	menu[4] = &ft_get_pwd;
	menu[5] = &ft_unset;
	menu[6] = &ft_exit;
	menu[7] = (void *)0;
	return (menu);
}
