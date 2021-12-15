#ifndef PARSE_H
# define PARSE_H

/*
** INCLUDES
*/
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


/*
** MACROS
*/
# define EMPTY 0
# define EXEC 1
# define BUILTIN 2
# define UNION 3
# define ARG 4
/*# define PIPE 4
# define REDIR 5
# define TRUNC 6
# define FLAG 7*/
# define EXIT 9

/*
** ERROR TAGS
*/
# define UNERR "Unknown error..."

/*
** STRUCTS & ENUMS
*/



/*
** FUNCTIONS
*/
t_token	*babelfish(t_ms minidata, char *buf);
void	bf_expansions(char *str, t_ms data);

int		skpspace(char *str, int index);
#endif