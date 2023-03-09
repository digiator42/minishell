/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:20:29 by ahassan           #+#    #+#             */
/*   Updated: 2022/08/16 03:15:37 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	j = 0;
	dstlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	j = dstlen;
	if (size <= dstlen)
		return (size + srclen);
	while (dstlen < size - 1 && src[i] != '\0')
	{
		dest[dstlen] = src[i];
		dstlen++;
		i++;
	}
	dest[dstlen] = '\0';
	return (j + srclen);
}

// int main()
// {
// 	char src[] = "hello";
// 	char dest[] = "world";

// 	printf("%u\n", ft_strlcat(dest, src, 6));
// 	printf("--------------------------\n");
// 	printf("%u\n", strlcat(dest, src, 6));
// }
