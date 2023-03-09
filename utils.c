/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:17:58 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/09 19:08:03 by ahassan          ###   ########.fr       */
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