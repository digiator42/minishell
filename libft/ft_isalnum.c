/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 07:33:53 by ahassan           #+#    #+#             */
/*   Updated: 2022/08/16 03:13:27 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int i)
{
	return (ft_isdigit(i) || ft_isalpha(i));
}
// int main()
// {
//     char c = ']';

//     printf("%d\n", isalnum(c));
//     printf("%d\n", ft_isalnum(c));
// }
