#ifndef MINISHELL_H
# define MINISHELL_H

/*
** INCLUDES
*/
# include "../srcs/Libft/libft.h"
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

/*
** ERROR TAGS
*/
# define ARG "Invalid argument\n"

/*
** STRUCTURES
*/
typedef	struct		s_env
{
	char			*value;
	struct s_env	*next;
}					t_env;

typedef	struct		s_ms
{
	int				exit;
	int				in;
	int				out;
	t_env			*env;
	t_env			*secret;
}					t_ms;

/*
** FUNCTIONS
*/
void    header(void);

#endif