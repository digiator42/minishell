/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:20:29 by ahassan           #+#    #+#             */
/*   Updated: 2022/08/10 07:35:07 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*r_dest;
	char	*r_src;

	i = 0;
	r_dest = (char *)dest;
	r_src = (char *)src;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		r_dest[i] = r_src[i];
		i++;
	}
	return (dest);
}

// int main()
// {
//     int isrc[] = {10, 20, 30, 40, 50};
//     int dest[5];

//     ft_memcpy(dest, isrc, sizeof(isrc));
//     printf("%d\n", dest[0]);
//     printf("----------------------\n");
//     bzero(dest,5);
//     printf("%d\n", dest[0]);
//     printf("----------------------\n");
//     memcpy(dest, isrc, sizeof(isrc));
//     printf("%d\n", dest[0]);

// }