CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = main.c access_env.c pipex.c utils.c ft_splitpipex.c
#OBJDIR = obj
OBJ = ${SRC:.c=.o}
NAME = pipex
LIBFT = libft/libft.a
RM = rm


all : ${NAME} 

${NAME} : ${OBJ} ${LIBFT}
		@${CC} ${CFLAGS} ${OBJ} ${LIBFT} -o ${NAME}

.o : .c
		@${CC} ${CFLAGS} -c $<

#${OBJDIR} :
#       mkdir -p ${OBJDIR}

${LIBFT} :
		@${MAKE} -C ./libft/

clean :
		@${RM} -f ${OBJ}
		@${MAKE} -C ./libft clean

fclean :        clean
		@${RM} -f ${NAME}
		@${MAKE} -C ./libft fclean

re : fclean all

.PHONY : all clean fclean re