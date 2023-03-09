/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 07:33:51 by ahassan           #+#    #+#             */
/*   Updated: 2022/08/16 03:13:21 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stddef.h>
// #include <stdint.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*c;

	c = (char *)s;
	i = 0;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}

// int	main(void)
// {
// 	char dest[] = "world";
// 	printf("%d\n", strlen(dest));
// 	bzero(dest, 5);
// 	printf("%s\n", dest);
// 	printf("%d\n", strlen(dest));
// 	printf("------------------------\n");
// 	char dest1[] = "world";
// 	printf("%d\n", strlen(dest1));
// 	ft_bzero(dest1, 7);
// 	printf("%s\n", dest1);
// 	printf("%d\n", strlen(dest1));

// }
