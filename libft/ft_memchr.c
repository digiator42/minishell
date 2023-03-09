/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 07:33:58 by ahassan           #+#    #+#             */
/*   Updated: 2022/08/16 03:13:56 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}

// int main()
// {
//     char s[] = "please find my loaction";
//     int c = 99;

//     char *i = (char *)ft_memchr1(s, c, 34);
//     printf("%c\n", *i);
// }
