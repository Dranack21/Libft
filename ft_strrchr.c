/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:50:30 by habouda           #+#    #+#             */
/*   Updated: 2024/05/22 12:35:06 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
		s++;
	s--;
	while (i > 0)
	{
		if (*s == c)
			return ((char *)s);
		s--;
		i--;
	}
	return (0);
}
