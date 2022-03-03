NAME= minishell.a

# Agrega aquí los Sources #
BUILTINS = ft_cd ft_echo ft_env ft_exit ft_export ft_pwd ft_unset

EXEC = execalibur exe_process exe_builtin exe_redirect	\
		exe_closeprocess exe_openprocess exe_multiprocess

MAIN = header minishell

PARSE = babelfish bf_expansions bf_split bf_tokenizer bf_escapes \
			bf_delquotes bf_divisor bf_div_addarg bf_div_addredir

TOOLS = secure_free free_strarr add_strarr rm_strarr display_array display_lst display_tokens

SRCS=	$(addsuffix .c, $(addprefix srcs/builtins/, $(BUILTINS))) \
		$(addsuffix .c, $(addprefix srcs/exec/, $(EXEC))) \
		$(addsuffix .c, $(addprefix srcs/main/, $(MAIN))) \
		$(addsuffix .c, $(addprefix srcs/parse/, $(PARSE))) \
		$(addsuffix .c, $(addprefix srcs/tools/, $(TOOLS)))
#############################

#####!- Color outputs -!#####
BLUE=\033[0;34m
GREEN=\033[0;32m
RED=\033[0;31m
YELLOW=\033[0;33m
NC=\033[0m
B=`tput bold`
#############################


####!- General VARS -!#######
CFLAGS= -Wall -Werror -Wextra -g3 -fsanitize=address
OBJS= ${SRCS:.c=.o}
RM= rm -f
CC= gcc
#############################


####!- Make -!###############
${NAME}: ${OBJS}
	@clear
	@echo "\n${BLUE}${B}"[❄] ... Compiling ... [❄]"${NC}${B}\n"
	@make bonus -sC ./Libft/
	@cp ./Libft/libft.a .
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	$(CC) $(CFLAGS) $(SRCS) libft.a -o minishell -lreadline
	@mv libft.a ./srcs

all: ${NAME}

re: fclean all

clean:
	#@${RM} minishell ${OBJS}
	@clear ; echo "\n${BLUE}${B}"[❄] ... Junk files deleted ... [❄]"\n"
	@make -sC ./Libft/ clean
	@${RM} ${NAME} libft.a ./srcs/libft.a

fclean:
	@make clean
	@clear ; echo "\n${BLUE}${B}"[❄] ... Junk files deleted ... [❄]"\n"
	@${RM} minishell minishell.a ${NAME} ${OBJS}
	@make -sC ./Libft/ fclean
##############################
.PHONY: fclean clean all re