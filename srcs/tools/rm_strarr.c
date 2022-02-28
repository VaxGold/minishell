#include "../../includes/minishell.h"

char	**rm_strarr(char **matrix, char *line)
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
		if (ft_strncmp(matrix[i], line, ft_strlen(line)) == 0)
			i++;
		if (matrix[i])
		{
			new_matrix[j++] = ft_strdup(matrix[i]);
			i++;
		}
	}
	new_matrix[j] = NULL;
	free_strarr(matrix);
	return (new_matrix);
}