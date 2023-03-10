/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:47:12 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/11 00:43:35 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINI_SHELL_H
# define MINI_SHELL_H

#define FALSE 0
#define TRUE 1

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

typedef struct s_var
{
	
}t_var;

typedef struct s_infra
{
	char *rd;
	char *trim_rd;
	char **cmds;
} t_infra;

char* replace(char* str, char* old, char* newstr);
int	right_quotes(char *str);
void	clean_quotes(char *str);
int	check_redirect(char *str);
#endif