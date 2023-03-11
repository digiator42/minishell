/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:06:15 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/12 00:21:51 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void is_quote(char c, char *quote)
{
	if (c == '\'' || c == '\"')
		{
			if (!*quote)
				*quote = c;
			else if (*quote == c)
				*quote = 0;
	}
}

static char	*ft_copy(char const *s, char c, int *i)
{
	char	*str;
	char	quote;

	quote = 0;
	*i = 0;
	while (s[*i])
	{
		is_quote(s[*i], &quote);
		if (!quote && s[*i] == c)
			break ;
		(*i)++;
	}
	return (ft_substr(s, 0, *i));
}

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	cnt;
	size_t	word;
	char	quote;

	i = 0;
	cnt = 0;
	word = 0;
	quote = 0;
	while (s[i])
	{
		is_quote(s[i], &quote);
		if (s[i] == c && !quote)
			cnt = 0;
		if (!quote && s[i] != c && cnt == 0)
		{
			word++;
			cnt = 1;
		}
		i++;
	}
	return (word);
}

char	**ft_split_with_quotes(char const *s, char c)
{
	char	**tab;
	size_t	j;
	int i = 0;
	int len;
	int quote;

	j = 0;
	quote = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(*tab) * (count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	while (j < count_word(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		tab[j++] = ft_copy(s + i, c, &len);
		i += len;
	}
	tab[j] = NULL;
	return (tab);
}

// int main()
// {
// 	char **strs = ft_split_with_quotes("hello |from |pipe\"|\"", '|');
// 	while(*strs)
// 		printf("%s\n", *strs++);

// 	// int i = count_word("hello |from |pipe\"|\"", '|');
// 	// printf("%d\n", i);
// }