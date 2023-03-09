/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:06:06 by ahassan           #+#    #+#             */
/*   Updated: 2022/08/16 03:14:21 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countlen(int nb)
{
	int	counter;
	int	sign;

	counter = 0;
	sign = 1;
	if (nb == 0)
		counter++;
	if (nb < 0)
	{
		sign = sign * -1;
		counter++;
	}
	while (nb != 0)
	{
		nb /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = countlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[len] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[len--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
// int main()
// {
//       printf("%s\n", ft_itoa(-21474836489));
// }
