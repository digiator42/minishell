/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:07:57 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/11 01:00:38 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redirect(char *str, int *i, int flag)
{
	if (str[*i] == '>' || str[*i] == '<')
	{
		(*i)++;
		if ((str[*i] == '<' && str[*i - 1] == '<') || (str[*i] == '>' && str[*i - 1] == '>'))
			(*i)++;
		while (str[*i] == ' ')
			(*i)++;
		if ((str[*i-1] == '>' || str[*i-1] == '<') && (!flag))
			return (FALSE);
	}
	else
		(*i)++;
	return (TRUE);
}

int	check_redirect(char *str)
{
	int i;
	int len;
	len = ft_strlen(str) - 1;
	int flag = FALSE;
	if (str[len] == '>' || str[len] == '<')
		return (FALSE);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (!flag)
				flag = str[i];
			else if (flag == str[i])
				flag = FALSE;
		}
		if (!is_redirect(str, &i, flag))
			return (FALSE);
	}
	return (TRUE);
}