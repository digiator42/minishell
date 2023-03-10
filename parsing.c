/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:21:37 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/10 19:53:36 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void handler(int sig)
{
	if(sig == SIGINT)
	{
		write(2, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

int excecute(char **cmds)
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
	return 1;
}

int get_line(t_infra *shell)
{
	int i;
	signal(SIGINT, handler);
	while(1)
	{
		shell->rd = readline("minishell{😎}> ");
		if(!shell->rd || !ft_strcmp(shell->rd, "exit"))
			return(printf("exit\n"), 0);
		if(ft_strcmp(shell->rd, ""))
			add_history(shell->rd);
		shell->trim_rd = ft_strtrim(shell->rd, "\t \n\r");
		if(!*shell->trim_rd)
			printf("nothing\n");
			
		if(!right_quotes(shell->trim_rd))
		{
			printf("error quoets\n");
			continue;
		}
		shell->cmds = ft_split(shell->trim_rd, ' ');
		if(!shell->cmds[0])
			continue;
		i = 0;	
		while(shell->cmds[i])
			clean_quotes(shell->cmds[i++]);
		if(excecute(shell->cmds))
			continue;
	}
}

int main()
{
	t_infra shell;

	
	get_line(&shell);
	// free(shell.rd);
	// free(shell.trim_rd);
}