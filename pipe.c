/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:06:15 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/11 23:53:25 by ahassan          ###   ########.fr       */
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

static char	*ft_cpystr(char const **s, char c)
{
	int		i;
	char	*str;
	char const	*tmp;
	char	quote;

	i = 0;
	tmp = *s;
	quote = 0;
	while (*s)
	{
		is_quote(**s, &quote);
		if (!quote && **s == c)
			break ;
		(*s)++;
	}
	printf("%ld\n", *s - tmp);
	str = malloc(sizeof(char) * (*s - tmp + 1));
	if (!str)
		return (NULL);
	str[*s - tmp] = '\0';
	return (ft_memcpy(str, *s, *s - tmp));
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

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	j;
	int i = 0;
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
		while (*s == c && *s)
			s++;
		tab[j] = ft_cpystr(&s, c);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

int main()
{
	char **strs = ft_split("hello |from |pipe\"|\"", '|');
	while(*strs)
		printf("%s\n", *strs++);

	// int i = count_word("hello |from |pipe\"|\"", '|');
	// printf("%d\n", i);
}