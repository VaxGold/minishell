/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:47:22 by adiaz-do          #+#    #+#             */
/*   Updated: 2022/02/13 18:04:21 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

/*
** INCLUDES
*/
# include "../Libft/libft.h"
# include "./parse.h"
# include "./minishell.h"
# include "./exec.h"

# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef	struct      s_build
{
    char            *next;
    char            *value;
}	                t_build;

int		ft_echo(char **args);
int		ft_exit(char **cmd);
int		ft_env(t_build *env);
int		ft_pwd(void);

#endif