/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:51:38 by adiaz-do          #+#    #+#             */
/*   Updated: 2022/02/19 20:09:10 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

char	**ms_matrix_add_line(char **matrix, char *new_line)
{
	int		i;
	char	**new_matrix;

	i = 0;
	while (matrix[i])
		i++;
	new_matrix = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (matrix[i])
	{
		new_matrix[i] = ft_strdup(matrix[i]);
		i++;
	}
	new_matrix[i] = ft_strdup(new_line);
	i++;
	new_matrix[i] = NULL;
	ft_free_tab(matrix);
	return (new_matrix);
}

char	**ms_matrix_remove_line(char **matrix, char *line)
{
	int		i;
	int		j;
	char	**new_matrix;

	i = 0;
	j = 0;
	while (matrix[i])
		i++;
	new_matrix = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (matrix[i])
	{
		if (ft_strcmp(matrix[i], line) == 0)
			i++;
		if (matrix[i])
		{
			new_matrix[j++] = ft_strdup(matrix[i]);
			i++;
		}
	}
	new_matrix[j] = NULL;
	ft_free_tab(matrix);
	return (new_matrix);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*ft_strjoin_free_s1(char *s1, char const *s2)
{
	char	*tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	tab = (char *)malloc(sizeof(*tab) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (tab == 0)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		tab[i] = s2[j];
		j++;
		i++;
	}
	tab[i] = '\0';
	free(s1);
	return (tab);
}
