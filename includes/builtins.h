/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:47:22 by adiaz-do          #+#    #+#             */
/*   Updated: 2022/02/19 19:28:27 by omercade         ###   ########.fr       */
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

# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

char	*ms_get_env(char **env, char *arg);
void	ft_free_tab(char **tab);
void	ft_sort_tab(char **arr);
char	*ft_strjoin_free_s1(char *s1, char const *s2);
void	set_pwd(char *arg, char	*c);
char	**ms_matrix_add_line(char **matrix, char *new_line);
char	**ms_matrix_remove_line(char **matrix, char *line);

int		ft_cd(char **arg, char **env);
int		ft_echo(char **args, char **env);
int		ft_env(char **args, char **env);
int 	ft_exit(char **args, char **env);
int		ft_export(char **arg ,char **env);
int		ft_get_pwd(char **arg, char **env);
int		ft_unset(char **env, char **arg);

#endif