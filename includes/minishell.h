#ifndef MINISHELL_H
# define MINISHELL_H

/*
** INCLUDES
*/
# include "../Libft/libft.h"

# include "./parse.h"
# include "./builtins.h"

# include <readline/readline.h>
# include <readline/history.h>

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
 

/*
** COLORS
*/
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define WHITE "\033[0;37m"
# define NC "\033[1m"

/*
** MACROS
*/
# define MAX_INT 2147483647
# define MIN_INT -2147483648

# define STDIN 0
# define STDOUT 1
# define STDERR 2


/*
** ERROR TAGS
*/
# define ERRARG "Invalid argument\n"

/*
** STRUCTURES
*/
// typedef struct		s_token		//Pertenece a <parse.h>
// {
// 	char			*str;
// 	int				type;
// 	struct s_token	*prev;
// 	struct s_token	*next;
// }					t_token;

typedef	struct		s_ms
{
	int				exit;
	int				in;
	int				out;
	char			**env;
	char			**secret;
	t_list			*tokenst;
}					t_ms;

/*
** FUNCTIONS
*/
void	header(void);
int		ft_exit(char **cmd);

void	execalibur(t_ms *this);
void	exe_process(t_token *token, char **env);

void	secure_free(char *str);
void	free_strarr(char **array);

#endif