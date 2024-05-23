/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:21:08 by habouda           #+#    #+#             */
/*   Updated: 2024/05/23 12:06:12 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (ft_strlen(s) < len)
	{
		dest = malloc(sizeof(char) * ft_strlen(s) + 1);
		if (!dest)
			return (NULL);
	}
	else
	{
		dest = malloc(sizeof(char) * len + 1);
		if (!dest)
			return (NULL);
	}
	while (i < len && start < ft_strlen(s))
	{
		dest[i] = s[start];
		start++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
