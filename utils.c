/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:17:58 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/11 16:01:42 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char* replace(char* str, char* old, char* newstr) 
{
    int len = strlen(str);
    int oldlen = strlen(old);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (strchr(old, str[i]) != NULL) {
            count++;
        }
    }
    int newlen = len + count * (strlen(newstr) - oldlen);
    char* result = (char*) malloc((newlen + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (strchr(old, str[i]) != NULL) {
            strcpy(result + j, newstr);
            j += strlen(newstr);
        } else {
            result[j] = str[i];
            j++;
        }
    }
    result[j] = '\0';
    return result;
}

void	clean_quotes(char *str)
{
	int	i;
	int	j;
	int	quote;

	j = 0;
	i = 0;
	quote = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (!quote)
				quote = str[i];
			else if (quote == str[i])
				quote = 0;
			else
				str[j++] = str[i];
		}
		else
			str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
}

int	right_quotes(char *str)
{
	int single = 0;
	int paired = 0;
	int i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			if (single)
				single = 0;
			else if (!paired)
				single = 1;
		}
		else if (str[i] == '\"')
		{
			if (paired)
				paired = 0;
			else if (!single)
				paired = 1;
		}
		i++;
	}
	if (single || paired)
		return (0);
	return (1);
}