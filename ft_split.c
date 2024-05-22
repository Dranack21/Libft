/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:48:43 by habouda           #+#    #+#             */
/*   Updated: 2024/05/22 17:17:07 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, unsigned int n, char c)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}


int	char_pos(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
	}
	while (str[i] == c)
	{
		i++;
	}
	return (i);
}


int	count_words(const char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] && str[i] != c)
		{
			i++;
		}
			words++;
			i++;
		while (str[i] == c && str[i])
			i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	j = 0;
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (*s == c)
        s++;
	while(*s)
	{
		i = char_pos (s, c);
		split[j] = malloc(sizeof(char) * (i + 1));	
		if (!split[j])
		{
			free (split);
			return (NULL);
		}
		ft_strncpy(split[j], s , i, c);
		split[j++][i] = '\0';
		s = s + i;
	}
	split[j] = NULL;
	return (split);
}


/*int	main()
{
	printf("%s\n", ft_split("", 'z')[0]);
}*/