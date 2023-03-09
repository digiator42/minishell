/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 07:33:59 by ahassan           #+#    #+#             */
/*   Updated: 2022/08/16 03:14:00 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*r_s1;
	unsigned char	*r_s2;

	r_s1 = (unsigned char *)s1;
	r_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (r_s1[i] != r_s2[i])
			return (r_s1[i] - r_s2[i]);
		i++;
	}
	return (0);
}

// int main ()
// {
//     char s1[] = "ahmed";
//     char s2[] = "ahmed";

//     printf("%d\n", ft_memcmp(s1, s2, 5));
// }
