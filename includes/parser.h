#ifndef PARSER_H
# define PARSER_H

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
** STRUCTURES & ENUMS
*/

/*typedef struct		s_token
{
	char			*str;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;*/



/*
** FUNCTIONS
*/

#endif
