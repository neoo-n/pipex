CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = main.c access_env.c pipex.c utils.c ft_splitpipex.c\
		ft_splitpipex2.c 
#OBJDIR = obj
OBJ = ${SRC:.c=.o}
NAME = pipex
LIBFT = libft/libft.a
RM = rm

PURPLE = \033[1;34m
CYAN = \033[2;36m
RESET = \033[0m

all : ${NAME} header

header:
	@echo "$(PURPLE)"
	@echo ".------..------..------..------..------."
	@echo "|P.--. ||I.--. ||P.--. ||E.--. ||X.--. |"
	@echo "| :/\: || (\/) || :/\: || (\/) || :/\: |"
	@echo "| (__) || :\/: || (__) || :\/: || (__) |"
	@echo "| '--'P|| '--'I|| '--'P|| '--'E|| '--'X|"
	@echo "\`------'\`------'\`------'\`------'\`------'"
	@echo "$(RESET)"

${NAME} : ${OBJ} ${LIBFT}
		@${CC} ${CFLAGS} ${OBJ} ${LIBFT} -o ${NAME}

.o : .c
		@${CC} ${CFLAGS} -c $<

#${OBJDIR} :
#       mkdir -p ${OBJDIR}

${LIBFT} :
		@echo "$(CYAN)"
		@${MAKE} -C ./libft/
		@echo "$(RESET)"

clean :
		@${RM} -f ${OBJ}
		@${MAKE} -C ./libft clean

fclean :        clean
		@${RM} -f ${NAME}
		@${MAKE} -C ./libft fclean

re : fclean all

.PHONY : all clean fclean re