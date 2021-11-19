#ifndef GENERAL_H
# define GENERAL_H

/****** Includes **************/
# include "../srcs/Libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <stdio.h>
/******************************/

/******* Colors ***************/
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define NC "\033[1m" 
/******************************/

/****** Macros ****************/
# define MAX_INT 2147483647
# define MIN_INT -2147483648
/******************************/

/****** Error Tags ************/
# define ARG "Invalid argument"
/******************************/





void    ft_prompt(void);

#endif
