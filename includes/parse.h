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
	char			**args;
	t_list			*in;
	t_list			*out;
	//PIPES & FDs
	pid_t			pid;
	int				*fd;
	int				status;		//ERR_Control
}					t_token;

typedef struct		s_redirect
{
	char			**args;
	char			*simbol;
	int				pos;
}					t_redirect;

/*
** FUNCTIONS
*/
t_list	*babelfish(char *buf, char **env);
t_list	*bf_tokenizer(char *buf, char **env);
void	bf_split(char *line, t_token *token, t_list *largs, int *quotes);
int		*bf_escapes(char *str);
void	bf_expansions(char *str, char **env);

#endif