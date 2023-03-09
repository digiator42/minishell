/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:20:29 by ahassan           #+#    #+#             */
/*   Updated: 2022/08/16 03:15:59 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	j;

	j = ft_strlen(str);
	str = str + j;
	while (*str != c && j != 0)
	{
		str--;
		j--;
	}
	if (*str == c)
		return ((char *)str);
	return (NULL);
}

char	*ft_strrchr1(const char *str, int c)
{
	int	j;

	j = ft_strlen(str);
	while (str[j] != c && j)
	{
		j--;
	}
	if (str[j] == c)
		return ((char *)&str[j]);
	return (NULL);
}

// int main ()
// {
//     char c[] = "ffffffffflffffff";

//     printf("%s",strrchr(c, 'l'));
//     printf("\n");
//     printf("%s",ft_strrchr1(c, 'l'));
//     printf("\n");
//     printf("%s",ft_strrchr(c, 'l'));
//     printf("\n");
// }