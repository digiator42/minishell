/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:21:37 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/09 14:05:27 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void handler(int sig)
{
	if(sig == SIGINT)
	{
		write(1, "\n", 14);
		rl_replace_line("", 0);
	}
}

int main()
{
	t_infra shell;
	signal(SIGINT, handler);
	while(1)
	{
		shell.rd = readline("minishell> ");
		ft_strtrim(shell.rd, "\n");
		if(!shell.rd)
			return(printf("exit\n"), 0);
		add_history(shell.rd);
	}
}