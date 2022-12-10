CC = gcc

CFLAGS = -Wall -Wextra -Werror 
LIB = -lreadline

NAME =	minishell

NAME_LIBFT = libft.a

DIR_INC = -I ./includes/

DIR_INC += -I ./Libft/

SRCS =		main.c \
			builtin.c \
			env.c \
			init_struct.c \
			builtin2.c \
			
		

SRCS_DIR = ./srcs

DIR_OBJ = 	obj

OBJS = $(addprefix $(DIR_OBJ)/, ${SRCS:.c=.o})

DEPS = $(OBJS:.o=.d)

-include $(DEPS)

all:	${NAME}

${NAME}: ${OBJS}
		make -C ./Libft/
		${CC} $(DIR_INC) ${OBJS} -o ${NAME} -L ./Libft/ -lft -lreadline

$(DIR_OBJ)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DIR_INC) -o $@ -c $< -MMD

clean:
		rm -rf ${DIR_OBJ}
		make -C ./Libft/ clean

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re