/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:48:43 by habouda           #+#    #+#             */
/*   Updated: 2024/05/23 10:40:15 by habouda          ###   ########.fr       */
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
	return (i);
}

static int	count_words(const char *str, char c)
{
	int	word;
	int	counter;

	word = 0;
	counter = 0;
	while (*str)
	{
		if (*str != c && !word)
		{
			word = 1;
			counter++;
		}
		if (*str == c && word)
			word = 0;
		str++;
	}
	return (counter);
}

char	*array(const char *s, char c)
{
	int		i;
	char	*split;

	i = char_pos (s, c);
	split = malloc(sizeof(char) * (i + 1));
	if (!split)
	{
		free (split);
		return (NULL);
	}
	ft_strncpy(split, s, i, c);
	split[i] = '\0';
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		j;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	j = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			split[j] = array(s, c);
			if (!split[j++])
			{
				j = 0;
				while (split[j++])
					free(split[j]);
				return (NULL);
			}
			s = s + char_pos(s, c);
		}
	}
	split[j] = NULL;
	return (split);
}
