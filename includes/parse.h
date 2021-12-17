#ifndef PARSE_H
# define PARSE_H

/*
** INCLUDES
*/
# include "../libs/Libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>


/*
** MACROS
*/
# define EMPTY 0
# define EXEC 1
# define BUILTIN 2
# define ARG 3
# define PIPE 4
# define REDIR 5
# define TRUNC 6
# define EXIT 9

/*
** ERROR TAGS
*/
# define UNERR "Unknown error..."

/*
** STRUCTS & ENUMS
*/
typedef struct		s_token
{
	char			*str;
	int				type;
}					t_token;


/*
** FUNCTIONS
*/
t_list	*babelfish(char *buf, char **env);
void	bf_expansions(char *str, char **env);

int		skpspace(char *str, int index);
#endif