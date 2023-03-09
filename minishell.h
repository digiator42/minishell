
#ifndef MINI_SHELL_H
# define MINI_SHELL_H


# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/stat.h>
# include <termios.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"


typedef struct s_infra
{
	char *rd;
	char *trim_rd;
} t_infra;

char* replace(char* str, char* old, char* newstr);
void	clean_quotes(char *str);
#endif