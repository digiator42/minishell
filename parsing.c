/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:21:37 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/09 22:15:39 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void handler(int sig)
{
	if(sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void excecute(char **cmds)
{
	int fd = fork();
	if(fd == 0)
	{
		if(execvp(cmds[0], cmds) == -1)
			printf("command not found: %s\n", cmds[0]);
	}
	else 
		wait(NULL);
	close(fd);	
}

int main()
{
	t_infra shell;
	int i;
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	while(1)
	{
		shell.rd = readline("minishell{😎}> ");
		if(!shell.rd)
			return(printf("exit\n"), 0);
		if(ft_strcmp(shell.rd, ""))
			add_history(shell.rd);
		shell.trim_rd =	ft_strtrim(shell.rd, "\t \n\r");
		char **cmds = ft_split(shell.trim_rd, ' ');
		if(!cmds[0])
			continue;
		i = 0;	
		while(cmds[i])
			clean_quotes(cmds[i++]);
		excecute(cmds);
		// free(shell.rd);
		// free(shell.trim_rd);
	}
}