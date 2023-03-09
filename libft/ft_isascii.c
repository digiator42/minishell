/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 07:33:55 by ahassan           #+#    #+#             */
/*   Updated: 2022/08/16 03:13:37 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*int main ()
{
    int c = 128;
    char f = 'v';

    printf("%d\n", isascii(c));
    printf("%d\n", ft_isascii(c));

    printf("%d\n", isascii(f));
    printf("%d\n", ft_isascii(f));

}*/
