/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 07:33:57 by ahassan           #+#    #+#             */
/*   Updated: 2022/08/10 23:47:18 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*int main ()
{
    char c = 2;
    char f = ' ';

    printf("%d\n", ft_isprint(c));
    printf("%d\n", isprint(c));

    printf("%d\n", ft_isprint(f));
    printf("%d\n", isprint(f));
}*/
