NAME= minishell.a

# Agrega aquí los Sources #
SRCS=	srcs/main/minishell.c \
		srcs/main/header.c

#####!- Color outputs -!#####
BLUE=\033[0;34m
GREEN=\033[0;32m
RED=\033[0;31m
YELLOW=\033[0;33m
NC=\033[0m
B=`tput bold`
#############################


####!- General VARS -!#######
CFLAGS= -Wall -Werror -Wextra
OBJS= ${SRCS:.c=.o}
RM= rm -f
CC= gcc
#############################


####!- Make -!###############
${NAME}: ${OBJS}
	@clear
	@echo "\n${BLUE}${B}"[❄] ... Compiling ... [❄]"${NC}${B}\n"
	@make -sC ./srcs/Libft/
	@cp ./srcs/Libft/libft.a .
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	$(CC) $(CFLAGS) $(SRCS) libft.a -o minishell -lreadline
	@mv libft.a ./srcs

all: ${NAME}
#############################


####!- Aditional rules -!####
.PHONY: fclean clean all re

re: fclean all

clean:
	#@${RM} minishell ${OBJS}
	@clear ; echo "\n${BLUE}${B}"[❄] ... Junk files deleted ... [❄]"\n"
	@make -sC ./srcs/Libft/ clean
	@${RM} ${NAME} libft.a ./srcs/libft.a

fclean:
	@make clean
	@clear ; echo "\n${BLUE}${B}"[❄] ... Junk files deleted ... [❄]"\n"
	@${RM} minishell minishell.a ${NAME} ${OBJS}
	@make -sC ./srcs/Libft/ fclean
##############################
