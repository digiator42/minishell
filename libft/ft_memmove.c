/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:20:29 by ahassan           #+#    #+#             */
/*   Updated: 2022/08/16 03:14:07 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*csrc;
	char	*cdest;

	csrc = (char *)src;
	cdest = (char *)dest;
	if (!dest && !src)
		return (0);
	if (((size_t)dest - (size_t)src) < n)
	{
		n = n - 1;
		while (n)
		{
			cdest[n] = csrc[n];
			n--;
		}
		cdest[n] = csrc[n];
	}
	i = 0;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (cdest);
}

// int main()
// {
//     //case where there's overlapping

//         char csrc[100] = "Geeksfor-Geeksfor";
//         ft_memmove(csrc+5, csrc, strlen(csrc)+1);
//         printf("%s", csrc);
//         printf("\n---------------\n");
//         char csrc2[100] = "Geeksfor-Geeksfor";
//         memmove(csrc2+5, csrc2, strlen(csrc2)+1);
//         printf("%s\n", csrc2);
//         /*****************no over lapping*******************/
//         // char csrc[100] = "Geeksfor-Geeksfor";
//         // char dest[100];
//         // ft_memmove(dest, csrc, strlen(dest));
//         // printf("%s", csrc);
//         // printf("\n---------------\n");
//         // char csrc3[100] = "Geeksfor-Geeksfor";
//         // char dest2[16];
//         // memmove(dest2, csrc3, strlen(dest2));
//         // printf("%s", csrc3);
//         return (0);
// }