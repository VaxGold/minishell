/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:56:25 by omercade          #+#    #+#             */
/*   Updated: 2022/02/12 17:59:09 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exe_opt(char *cmd)
{	
	if (!ft_strcmp("cd\0", cmd))
		return (0);
	if (!ft_strcmp("echo\0", cmd))
		return (1);
	if (!ft_strcmp("env\0", cmd))
		return (2);
	if (!ft_strcmp("export\0", cmd))
		return (3);
	if (!ft_strcmp("pwd\0", cmd))
		return (4);
	if (!ft_strcmp("unset\0", cmd))
		return (5);
	if (!ft_strcmp("exit\0", cmd))
		return (6);
	return (-1);
}
