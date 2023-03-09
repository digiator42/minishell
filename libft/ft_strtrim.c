/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 03:16:02 by ahassan           #+#    #+#             */
/*   Updated: 2022/08/26 08:32:05 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	rear;
	char	*str;

	if (!s1)
		return (NULL);
	front = 0;
	rear = ft_strlen(s1);
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	if (rear > 0)
		rear--;
	while (rear > front && ft_strchr(set, s1[rear]))
		rear--;
	str = malloc(sizeof(char) * (rear - front + 2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[front], rear - front + 2);
	return (str);
}
