#ifndef GENERAL_H
# define GENERAL_H

/****** Includes **************/
# include "../srcs/Libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>

/******************************/

/******* Colors ***************/
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define WHITE "\033[0;37m"
# define NC "\033[1m"
/******************************/

/****** Macros ****************/
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define clear() printf("\033[H\033[J")
/******************************/

/****** Error Tags ************/
# define ARG "Invalid argument"
/******************************/

/****** Structures ************/
typedef struct		s_token
{
	char		*str;
	int			type;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

typedef struct		s_env
{
	char			*value;
	//struct s_env	next;
}					t_env;

typedef	struct		s_ms
{
	int				exit;
	t_token			start;
	t_env			env;
	int				pipe[2];
	
}					t_ms;
/******************************/




void    ft_prompt(void);

#endif
