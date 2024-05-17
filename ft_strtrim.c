/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:14:34 by habouda           #+#    #+#             */
/*   Updated: 2024/05/17 17:08:22 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>


size_t	ft_strlen(const char *str)
{
	int	i = 0;
	while(str[i])
	{
		i++;
	}
	return (i);
}


size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dest_len >= size)
		return (src_len + size);
	while (src[i] && i < size - dest_len - 1)
	{
		dest[dest_len + i] = src [i];
		i++;
	}
	dest[i + dest_len] = '\0';
	return (src_len + dest_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*s2;

	s2 = malloc(sizeof(char)* ft_strlen(s1) + 1);
	i = 0;
	j = 0;
	while(s1[i] && set[j])
	{
		while (set[j] && s1[i])
		{
			if (set[j] && s1[i] && s1[i] != set[j])
			{
				ft_strlcat(s2, &s1[i], ft_strlen(s1));
			}
			i++;
		}
		j++;
		i = 0;
	}
	return (s2);
}
int	main()
{
	const char *s1 = "abcadfeg";
	const char *set = "a";
	printf("%s", ft_strtrim(s1, set));
}