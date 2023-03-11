NAME = minishell

SRCS =	parsing.c 		\
		utils.c			\
		redirection.c	\
		pipe_err.c		\
		err_handling.c	\
		pipe_split.c	\

OBJS = $(SRCS:.c=.o)

GCC = cc

CFLAGS = -g3 -Wall -Werror -Wextra -I/usr/local/Cellar/readline/8.1/include -fsanitize=address

EXEC = minishell

all : $(NAME)

$(NAME): $(OBJS)
		cd libft && make
		$(GCC) $(CFLAGS) $(OBJS) -o $(EXEC) -L ./libft -lft -lreadline -L /usr/local/Cellar/readline/8.1/lib/
clean:
	rm -f $(OBJS)

fclean: clean
	cd libft && make fclean
	rm -f $(NAME) $(EXEC)

re : clean all